#ifndef GRAPH_H
#define GRAPH_H

#define ll long long
#define pll pair<long long, long long>

#include<bits/stdc++.h>
#include<tuple>

using namespace std;

class graph{

private:

	vector<tuple<ll,ll,ll> > edgeList;
	vector<vector<pll> > adjList;
	ll numberOfVertices;
	ll numberOfEdges;
	bool * visited;
	ll **adjMatrix;

	ll **distancePairs;

	ll **edgeExists;


public:

	void dfsPrintAssist(ll x);

	void bfsPrintAssist(ll x);

	graph(ll n, ll m);

	void addEdge(ll x, ll y, ll z=1);

	void dfsPrint(ll x);

	void bfsPrint(ll x);

	void belmanFordDistance(ll x);

	void dijkstraDistance(ll x);

	void floydWarshall();

	void uni(ll x, ll y, ll parent[], ll size[]);

	ll finde(ll x, ll parent[]);

	ll kruskalMST();

	ll primMST();

};

#endif
