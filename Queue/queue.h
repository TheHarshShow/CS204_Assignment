#ifndef QUEUE_H
#define QUEUE_H

#import<bits/stdc++.h>

#define ll long long
#define REP(i,a,b) for(ll i=a; i<b; i++)

using namespace std;

class cue{


private:
	ll * list;
	ll p1;
	ll curr;
	ll size;

public:


	cue();

	void enqueue(ll x);

	ll dequeue();

	ll front();

	ll back();

	ll getSize();

	bool isEmpty();
};

#endif

