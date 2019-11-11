#define ll long long
#define pll pair<long long, long long>
#define REP(i,a,b) for(ll i=a; i<b; i++)

#include<bits/stdc++.h>
#include "graph.h"
#include<tuple>
#define MP make_pair
#define INF 1000000000

using namespace std;


void graph::dfsPrintAssist(ll x){



	if(visited[x])return;
	visited[x]=true;


	cout<<x<<"\n";


	for(auto u: adjList[x]){

		dfsPrintAssist(u.first);

	}


}

void graph::bfsPrintAssist(ll x){

	queue<ll> q1;
	q1.push(x);

	cout<<x<<endl;

	visited[x]=true;

	while(!q1.empty()){

		ll c=q1.front();
		q1.pop();


		for(auto u: adjList[c]){

			if(!(visited[u.first])){q1.push(u.first);
			cout<<u.first<<endl;visited[u.first]=true;}

		}




	}


}

graph::graph(ll n, ll m){

	numberOfVertices=n;
	numberOfEdges=m;

	distancePairs=(ll **)malloc((numberOfVertices+1) * sizeof(ll *));
	REP(i,0,n+1)distancePairs[i]=(ll *)calloc(numberOfVertices+1, sizeof(ll));

	edgeExists=(ll **)malloc((numberOfVertices+1) * sizeof(ll *));
	REP(i,0,n+1)edgeExists[i]=(ll *)calloc(numberOfVertices+1, sizeof(ll));

	adjMatrix=(ll **)malloc((numberOfVertices+1) * sizeof(ll *));
	REP(i,0,n+1)adjMatrix[i]=(ll *)calloc(numberOfVertices+1, sizeof(ll));

	adjList.assign(n+1, vector<pll> (0));
	visited=(bool *)malloc((n+1)*sizeof(bool));


	REP(i,0,n+1){visited[i]=false;}


}



void graph::addEdge(ll x, ll y, ll z){


	edgeList.push_back(make_tuple(x,y,z));
	edgeList.push_back(make_tuple(y,x,z));

	if(adjMatrix[x][y]==0)adjMatrix[x][y]=z;
	else adjMatrix[x][y]=min(adjMatrix[x][y], z);

	if(adjMatrix[y][x]==0)adjMatrix[y][x]=z;
	else adjMatrix[y][x]=min(z, adjMatrix[y][x]);

	edgeExists[x][y]=1;
	edgeExists[y][x]=1;

	adjList[x].push_back(MP(y,z));

	adjList[y].push_back(MP(x,z));

}


void graph::dfsPrint(ll x){

	dfsPrintAssist(x);


	REP(i,0,numberOfVertices+1){
		visited[i]=false;

	}

}


void graph::bfsPrint(ll x){

	bfsPrintAssist(x);

	REP(i,0,numberOfVertices+1)visited[i]=false;


}


void graph::belmanFordDistance(ll x){

	ll distancesFromX[numberOfVertices+1];

	REP(i,0,numberOfVertices+1)distancesFromX[i]=1000000000;
	distancesFromX[x]=0;
	REP(i,0,numberOfVertices-1){

		for(auto u: edgeList){

			ll a,b,w;
			tie(a,b,w)=u;
			distancesFromX[b]=min(distancesFromX[b], distancesFromX[a]+w);


		}


	}

	REP(i,1,numberOfVertices+1)cout<<distancesFromX[i]<<" ";
	cout<<endl;



}

void graph::dijkstraDistance(ll x){

	ll distancesFromX[numberOfVertices+1];
	ll processed[numberOfVertices+1];

	REP(i,0,numberOfVertices+1){distancesFromX[i]=1000000000;processed[i]=0;}
	distancesFromX[x]=0;
	priority_queue<pll> q1;

	q1.push(MP(0,x));

	while(!q1.empty()){

		ll a=q1.top().second;
		q1.pop();
		processed[a] = true;

	    for (auto u : adjList[a]) {
	       ll b = u.first, w = u.second;
	       if (distancesFromX[a]+w < distancesFromX[b]) {
	           distancesFromX[b] = distancesFromX[a]+w;
	           q1.push(MP(-distancesFromX[b],b));
	       }
		}

	}

	REP(i,1,numberOfVertices+1)cout<<distancesFromX[i]<<" ";
	cout<<endl;


}

void graph::floydWarshall(){


	REP(i,0,numberOfVertices+1){

	    REP(j,0,numberOfVertices+1){

	       if (i==j) {distancePairs[i][j] = 0;}
	       else if (adjMatrix[i][j]) distancePairs[i][j]=adjMatrix[i][j];
	       else distancePairs[i][j] = INF;
		}

	}



	REP(i,1,numberOfVertices+1){

		REP(j,1,numberOfVertices+1){

			REP(k,1,numberOfVertices+1){
				distancePairs[i][j]=min(distancePairs[i][j], distancePairs[i][k]+distancePairs[k][j]);

			}

		}

	}

	for(ll i=1; i<numberOfVertices+1; i++){

		for(ll j=1; j<numberOfVertices+1; j++){

			cout<<distancePairs[i][j]<<" ";

		}

		cout<<endl;


	}

}


void graph::uni(ll x, ll y, ll parent[], ll size[]){

	x=finde(x, parent);
	y=finde(y, parent);
	if(x==y)return;
	if(size[x]>size[y])swap(x,y);
	size[y]+=size[x];
	parent[x]=y;


}


ll graph::finde(ll x, ll parent[]){

	if(x==parent[x])return x;
	return parent[x]=finde(parent[x], parent);

}


ll graph::kruskalMST(){

	vector<tuple<ll,ll,ll> > edgeListTemp;

	ll parent[numberOfVertices+1];
	ll size[numberOfVertices+1];

	REP(i,0,edgeList.size()){


		edgeListTemp.push_back(make_tuple(get<2>(edgeList[i]), get<0>(edgeList[i]), get<1>(edgeList[i])));

	}

	sort(edgeListTemp.begin(), edgeListTemp.end());


	REP(i,1,numberOfVertices+1){parent[i]=i;size[i]=1;}

	ll ans=0;

	REP(i,0,edgeListTemp.size()){

		if(finde(get<1>(edgeListTemp[i]), parent) != finde(get<2>(edgeListTemp[i]), parent)){

			uni(get<1>(edgeListTemp[i]), get<2>(edgeListTemp[i]), parent, size);
			ans+=get<0>(edgeListTemp[i]);

		}


	}

	return ans;


}

ll graph::primMST(){

	ll visit[numberOfVertices+1];
	pll minEdge[numberOfVertices+1];

	ll ans=0;

	REP(i,0,numberOfVertices+1){visit[i]=0;minEdge[i]=MP(1000000000, -1);}


	minEdge[1].first=0;

	REP(i,1,numberOfVertices+1){

		ll selected=-1;
		REP(j,1,numberOfVertices+1){

			if(!visit[j] && (selected==-1 || minEdge[j].first < minEdge[selected].first))selected=j;

		}

		visit[selected]=1;

		ans+=minEdge[selected].first;

		REP(j,1,numberOfVertices+1){

			if(edgeExists[selected][j] && adjMatrix[selected][j] < minEdge[j].first)minEdge[j]=make_pair(adjMatrix[selected][j], selected);

		}


	}

	return ans;



}






