#ifndef BST_TREE_H
#define BST_TREE_H

#include <bits/stdc++.h>
#include "binaryTree.h"
#include "binaryTree.cpp"

#define ll long long
#define ldb long double
#define REP for(ll i=a; i<b; i++)

using namespace std;


template<typename K, typename V>
class BST: public BinaryTree<K, V> {

private:

	void getNodeWithKeyAssistant(K key, struct treeNode<K,V> *node=NULL, ll flag=0);


public:

	BST();

	void insertNodeWithKeyAndValue(K key, V value=NULL);

	bool findNodeWithKey(K key, struct treeNode<K,V> *node=NULL, ll flag=0);


	void deleteNodeWithKey(K key);

	treeNode<K,V>* getNodeWithKey(K key);

	treeNode<K,V> *getNodeWithMaxKey();

	treeNode<K,V> *getNodeWithMinKey();


};

#endif //BST_TREE_H