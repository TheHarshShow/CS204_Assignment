#include <bits/stdc++.h>
#include "binaryTree.h"
#include "binaryTree.cpp"


#define ll long long
#define ldb long double
#define REP for(ll i=a; i<b; i++)

using namespace std;


int main(){

	BinaryTree<ll,string> b1;

	b1.insert(1, "harsh");

	b1.insert(2, "harshiboy");

	b1.insert(3, "brij", b1.getRoot(), b1.right);

	b1.insert(4, "Rashmi", b1.getNodeWithKey(2), b1.right);

	b1.insert(5, "lol", b1.getNodeWithKey(4), b1.right);

	//b1.deleteNode(b1.getNodeWithKey(2));
	//b1.deleteNode(b1.getNodeWithKey(4));
	//b1.deleteNode(b1.getNodeWithKey(1));

	cout<<b1.getValueForKey(5)<<endl;
	cout<<b1.getValueForKey(2)<<endl;
	cout<<b1.getValueForKey(3)<<endl;
	cout<<b1.getValueForKey(100)<<endl;


	b1.inorderPrint();
	cout<<endl;
	b1.preorderPrint();
	cout<<endl;
	b1.postorderPrint();


}