#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <bits/stdc++.h>

#include "BST.h"
#include "BST.cpp"

#define ll long long
#define ldb long double
#define REP for(ll i=a; i<b; i++)

using namespace std;

template<typename K, typename V>
class BalancedTree: public BST<K,V>{

public:

struct treeNode<K,V>*leftRotate(struct treeNode<K,V> * node);
struct treeNode<K,V>*rightRotate(struct treeNode<K,V> * node);
ll getHeight(struct treeNode<K,V> * node);

public:

	BalancedTree();

	struct treeNode<K,V>* balancedInsert(K key, V value, struct treeNode<K,V> * node=NULL, ll flag=0);
	struct treeNode<K,V>* deleteNodeWithKey(K key, struct treeNode<K,V>*node=NULL, ll flag=0);
	
};



#endif