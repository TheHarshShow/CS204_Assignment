#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <bits/stdc++.h>

#define ll long long
#define ldb long double
#define REP for(ll i=a; i<b; i++)

using namespace std;

template<typename K, typename V>
struct treeNode{

	K key;
	V value;
	ll leafFlag;
	struct treeNode *rightChild;
	struct treeNode *leftChild;
	struct treeNode *parent;


};



template<typename K, typename V>
class BinaryTree{

protected:

	struct treeNode<K,V> *createNode();
	struct treeNode<K,V>* root;
	struct treeNode<K,V>* nodeToAssistWithGetNode;
	ll flagToAssistWithGetNode;



public:
	
	enum asChild{

		left, right

	};

	BinaryTree();

	void getNodeWithKeyAssistant(K key, struct treeNode<K,V> *node =NULL, ll flag=0);

	bool findNodeWithKey(K key);


	struct treeNode<K,V> *getNodeWithKey (K key) ;

	void insert(K key, V value, struct treeNode<K,V> * parent = NULL, asChild childflag=left);

	struct treeNode<K,V> *leftMostChild (struct treeNode<K,V> * tempNode);

	struct treeNode<K,V> *getParent(struct treeNode<K,V> * node);

	void deleteNode(struct treeNode<K,V> *nodeToBeDeleted);

	void inorderPrint(struct treeNode<K,V> *node = NULL, ll flag=0);


	void preorderPrint(struct treeNode<K,V> *node = NULL, ll flag=0);

	void postorderPrint(struct treeNode<K,V> *node = NULL, ll flag=0);

	struct treeNode<K,V> *getRoot();

	bool isLeaf(struct treeNode<K,V>* node);

	V getValueForKey(K key);


};

#endif //BINARY_TREE_H


