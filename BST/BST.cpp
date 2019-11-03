#include <bits/stdc++.h>

#include "BST.h"

#define ll long long
#define ldb long double
#define REP for(ll i=a; i<b; i++)

using namespace std;

template<typename K, typename V>
BST<K,V>::BST(){

	this->root=NULL;
	this->flagToAssistWithGetNode=0;

}


template<typename K, typename V>
void BST<K,V>::insertNodeWithKeyAndValue(K key, V value){



	if(this->root == NULL){

		(this->root)=this->createNode();
		(this->root)->key=key;
		(this->root)->value=value;

	} else{

		struct treeNode<K,V>* temp=this->root;
		struct treeNode<K,V>* temp2;
		while(temp != NULL){

			if(temp->key >= key){

				temp2=temp;
				temp=temp->leftChild;

			} else {

				temp2=temp;
				temp=temp->rightChild;

			}


		}

		if(temp2->key >= key){

			struct treeNode<K,V>* nodeToBeInserted=this->createNode();
			nodeToBeInserted->key=key;
			nodeToBeInserted->value=value;
			nodeToBeInserted->parent=temp2;
			nodeToBeInserted->leafFlag=1;
			temp2->leftChild=nodeToBeInserted;
			temp2->leafFlag=0;

		} else {

			struct treeNode<K,V>* nodeToBeInserted=this->createNode();
			nodeToBeInserted->key=key;
			nodeToBeInserted->value=value;
			nodeToBeInserted->parent=temp2;
			nodeToBeInserted->leafFlag=1;
			temp2->rightChild=nodeToBeInserted;
			temp2->leafFlag=0;



		}

	}


}

template<typename K, typename V>
bool BST<K,V>::findNodeWithKey(K key, struct treeNode<K,V> *node, ll flag){

	if(!flag && node == NULL){

		node=this->root;
		flag=1;
	}

	if(flag && node == NULL){

		return false;

	}

	if(node->key == key)return true;
	if(node->key > key)return findNodeWithKey(key, node->leftChild, 1);
	return findNodeWithKey(key, node->rightChild, 1);


}

template<typename K, typename V>
void BST<K,V>::getNodeWithKeyAssistant(K key, struct treeNode<K,V> *node, ll flag){

	if(this->flagToAssistWithGetNode)return;

	if(flag==0 && node == NULL){

		flag=1;
		node=this->root;

	}

	if(node==NULL && flag)return;

	if(node->key==key){

		this->nodeToAssistWithGetNode=node;
		this->flagToAssistWithGetNode=1;

	} else if(node->key>key){

		getNodeWithKeyAssistant(key, node->leftChild, 1);

	} else {

		getNodeWithKeyAssistant(key, node->rightChild, 1);

	}

}

template<typename K, typename V>
void BST<K,V>::deleteNodeWithKey(K key){


	if(!findNodeWithKey(key))return;
	else{

		getNodeWithKeyAssistant(key);
		this->flagToAssistWithGetNode=0;
		this->deleteNode(this->nodeToAssistWithGetNode);

	}


}

template<typename K, typename V>
struct treeNode<K,V>* BST<K,V>::getNodeWithKey(K key){

	getNodeWithKeyAssistant(key);
	if(this->flagToAssistWithGetNode){

		this->flagToAssistWithGetNode=0;
		return this->nodeToAssistWithGetNode;

	}
	return NULL;

}

template<typename K, typename V>
struct treeNode<K,V> *BST<K,V>::getNodeWithMaxKey(){

	struct treeNode<K,V>*temp=this->root;
	while(temp->rightChild != NULL){

		temp=temp->rightChild;

	}

	return temp;


}

template<typename K, typename V>
struct treeNode<K,V> *BST<K,V>::getNodeWithMinKey(){

	struct treeNode<K,V>*temp=this->root;

	while(temp->leftChild != NULL){

		temp=temp->leftChild;

	}

	return temp;


}

