#ifndef STACC_STACK_H
#define STACC_STACK_H

#include <bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for(ll i=a; i<b; i++)
#define ldb long double

using namespace std;

template<typename T>
class stacc {

private:

	ll curr;
	ll size;
	T *list;


public:



	stacc();

	void push(T x);

	T pop();

	T top();

	ll getSize();

	ll getNumberOfElementsInStacc();

	bool isEmpty();

	bool isFull();


};

#endif
