#define ll long long
#define pll pair<long long, long long>
#define REP(i,a,b) for(ll i=a; i<b; i++)
#define INF 100000000000000000

#include<bits/stdc++.h>
#include "graph.h"
#include "graph.cpp"
#include<tuple>

using namespace std;

int main(){

	// graph g1(10, 4);

	// g1.addEdge(2, 3);
	// g1.addEdge(1, 3, 5);
	// g1.addEdge(3, 5);
	// g1.addEdge(1, 2, 10);

	// g1.addEdge(3, 4);
	// g1.addEdge(1, 6);
	// g1.addEdge(7,8,100);


	// g1.floydWarshall();

	// cout<<endl;

	// REP(i,1,11){

	// 	g1.dijkstraDistance(i);


	// }


	ll n,m;
	cin>>n>>m;

	graph g1(n,m);

	REP(i,0,m){

		ll a,b,c;
		cin>>a>>b>>c;
		g1.addEdge(a,b,c);


	}

	cout<<g1.primMST()<<endl;
	cout<<g1.kruskalMST()<<endl;



}