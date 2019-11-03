#include <bits/stdc++.h>

#include "AVLTree.h"
#include "AVLTree.cpp"

#define ll long long
#define ldb long double
#define REP for(ll i=a; i<b; i++)

using namespace std;

int main(){

	BalancedTree<ll,ll> b1;

	b1.balancedInsert(7, 2);
	b1.balancedInsert(6, 2);
	b1.balancedInsert(5, 2);
	b1.balancedInsert(4, 2);
	b1.balancedInsert(3, 7);
	b1.balancedInsert(8, 2);
	b1.balancedInsert(7, 2);
	b1.balancedInsert(9, 2);
	b1.balancedInsert(10, 2);
	b1.balancedInsert(11, 2);
	b1.balancedInsert(12, 2);
	b1.balancedInsert(2, 2);
	//b1.balancedInsert(6, 2);	
	b1.balancedInsert(13, 2);

	//cout<<b1.getRoot()->key<<endl;


	b1.deleteNodeWithKey(6);
	b1.deleteNodeWithKey(4);

	cout<<b1.getNodeWithKey(2)->height<<endl;
	cout<<b1.getNodeWithKey(3)->height<<endl;
	cout<<b1.getNodeWithKey(5)->height<<endl;
	cout<<b1.getNodeWithKey(7)->height<<endl;
	cout<<b1.getNodeWithKey(8)->height<<endl;
	cout<<b1.getNodeWithKey(9)->height<<endl;
	cout<<b1.getNodeWithKey(10)->height<<endl;
	cout<<b1.getNodeWithKey(11)->height<<endl;
	cout<<b1.getNodeWithKey(12)->height<<endl;
	cout<<b1.getNodeWithKey(13)->height<<endl;


	cout<<b1.getRoot()->key<<endl;


	cout<<b1.getNodeWithKey(8)->height<<endl;


	b1.inorderPrint();
	
}