#include <bits/stdc++.h>

#include "BST.h"
#include "BST.cpp"

#define ll long long
#define ldb long double
#define REP for(ll i=a; i<b; i++)

using namespace std;

int main(){

	BST<ll, ll> b1;

	b1.insertNodeWithKeyAndValue(2, 2);
	b1.insertNodeWithKeyAndValue(1, 2);
	b1.insertNodeWithKeyAndValue(7, 2);
	b1.insertNodeWithKeyAndValue(6, 2);

	b1.insertNodeWithKeyAndValue(8, 2);

	b1.insertNodeWithKeyAndValue(4, 2);
	b1.insertNodeWithKeyAndValue(5, 2);
	
	
	//cout<<b1.getRoot()->key<<endl;



	b1.deleteNodeWithKey(2);

	cout<<b1.getRoot()->key<<endl;

	cout<<b1.getNodeWithKey(1)->parent->key<<endl;
	cout<<b1.getNodeWithKey(5)->parent->key<<endl;


	// cout<<b1.getRoot()->key<<endl;


	// b1.deleteNodeWithKey(8);

	// cout<<b1.getRoot()->key<<endl;

	// cout<<b1.getNodeWithMaxKey()->key<<endl;
	// cout<<b1.getNodeWithMinKey()->key<<endl;


	b1.inorderPrint();

}