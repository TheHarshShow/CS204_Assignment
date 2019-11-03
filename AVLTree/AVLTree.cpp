#include <bits/stdc++.h>

#include "AVLTree.h"

#define ll long long
#define ldb long double
#define REP for(ll i=a; i<b; i++)

using namespace std;

template<typename K, typename V>
BalancedTree<K,V>::BalancedTree(){

	this->root=NULL;
	this->flagToAssistWithGetNode=0;

}

template<typename K, typename V>
ll BalancedTree<K,V>::getHeight(struct treeNode<K,V> * node){

	if(node==NULL)return -1;
	else return node->height;

}

template<typename K, typename V>
struct treeNode<K,V>* BalancedTree<K,V>::leftRotate(struct treeNode<K,V> * node){

	struct treeNode<K,V> *temp1=node->rightChild;
	struct treeNode<K,V> *temp2=node->leftChild;
	struct treeNode<K,V> *temp3=(node->rightChild)->leftChild;

	temp1->leftChild=node;
	node->rightChild=temp3;

	//adjust parent pointers

	if(node == this->root){
		this->root=temp1;
		temp1->parent=NULL;
		node->parent=temp1;
		if(temp3!=NULL)temp3->parent=node;
	}
	else {

		if(node==(node->parent)->leftChild)(node->parent)->leftChild=temp1;
		else (node->parent)->rightChild=temp1;
		temp1->parent=node->parent;
		node->parent=temp1;
		if(temp3 != NULL)temp3->parent=node;

	}

	// adjust heights

	node->height=max(getHeight(temp2), getHeight(temp3))+1;
	temp1->height=max(getHeight(node), getHeight(temp1->rightChild))+1;

	//adjust leaf flags

	if(node->height==0)node->leafFlag=1;
	else node->leafFlag=0;

	if(temp1->height==0)temp1->leafFlag=1;
	else temp1->leafFlag=0;

	return temp1;

}

template<typename K, typename V>
struct treeNode<K,V> * BalancedTree<K,V>::rightRotate(struct treeNode<K,V> * node){

	struct treeNode<K,V> *temp1=node->leftChild;
	struct treeNode<K,V> *temp2=node->rightChild;
	struct treeNode<K,V> *temp3=(node->leftChild)->rightChild;

	temp1->rightChild=node;
	node->leftChild=temp3;

	//adjust parents;
	//if(node->key==5)cout<<"hallo"<<endl;

	if(node==this->root){

		//if(node->key==5)cout<<"halloagain"<<endl;


		this->root=temp1;
		temp1->parent=NULL;
		node->parent=temp1;
		if(temp3!=NULL)temp3->parent=node;
	} else{

		//if(node->key==5)cout<<"halloagain"<<endl;

		//if(node->key==5)cout<<"heheehe"<<endl;

		//cout<<node->parent->key<<endl;

		if(node==(node->parent)->rightChild)(node->parent)->rightChild=temp1;
		else (node->parent)->leftChild=temp1;

		//cout<<"hehee"<<endl;

		temp1->parent=node->parent;
		node->parent=temp1;
		if(temp3!=NULL)temp3->parent=node;

	}

	node->height=max(getHeight(temp2), getHeight(temp3))+1;
	temp1->height=max(getHeight(node), getHeight(temp1->leftChild))+1;

	//adjust leaf flags


	if(node->height==0)node->leafFlag=1;
	else node->leafFlag=0;

	if(temp1->height==0)temp1->leafFlag=1;
	else temp1->leafFlag=0;	


	return temp1;

}


template<typename K, typename V>
struct treeNode<K,V>* BalancedTree<K,V>::balancedInsert(K key, V value, struct treeNode<K,V> * node, ll flag){

	if(flag==0 && node==NULL){

		flag=2;
		node=this->root;

	}

	if(flag && node==NULL){

		//if(key==3)cout<<"gogo"<<endl;

		node=this->createNode();
		node->key=key;
		node->value=value;
		node->height=0;

		if(flag==2)this->root=node;
		return node;

	}else {

		if(node->key >= key){

			//if(key==3)cout<<"haha"<<endl;
			node->leftChild=balancedInsert(key,value,node->leftChild,1);
			(node->leftChild)->parent=node;

			//if(key==3)cout<<" "<<node->leftChild->key<<endl;
		} else {

			//if(key==3)cout<<"bolo"<<endl;

			node->rightChild=balancedInsert(key,value,node->rightChild,1);
			(node->rightChild)->parent=node;

		}

		//if(key==3)cout<<"gigi"<<endl;

		node->height=max(getHeight(node->leftChild), getHeight(node->rightChild))+1;

		//if(key==3)cout<<node->key<<" "<<node->height<<endl; 

		ll balance=getHeight(node->leftChild)-getHeight(node->rightChild);

		//if(key==3)cout<<node->key<<" "<<balance<<endl; 


		if(-1<=balance && balance<=1)return node;
		else if(balance < -1){

			if(key<=(node->rightChild)->key)node->rightChild=rightRotate(node->rightChild);
			return leftRotate(node);

		} else{

			if(key>(node->leftChild)->key)node->leftChild=leftRotate(node->leftChild);


			//if(key==3)cout<<node->key<<" "<<balance<<endl; 

			//if(key==3)rightRotate(node);


			return rightRotate(node);

		}

	}

	


}	

template<typename K, typename V>
struct treeNode<K,V>* BalancedTree<K,V>::deleteNodeWithKey(K key, struct treeNode<K,V> * node, ll flag){

	//if(node->key==10 )cout<<"haha"<<endl;

	if(!(this->findNodeWithKey(key)))return NULL;

	if(flag==0 && node==NULL){

		flag=2;
		node=this->root;

	}

	if(flag && node==NULL){

		return NULL;

	} else{

		//if(node->key==10)cout<<node->key<<endl;

		if(node->key > key){

				//cout<<key<<" "<<"hehe"<<endl;


			node->leftChild=deleteNodeWithKey(key, node->leftChild, 1);
			if(node->leftChild != NULL)(node->leftChild)->parent=node;

		} else if (node->key < key){

				//cout<<key<<" "<<"hehee"<<endl;
			//cout<<node->key<<" "<<21<<endl;


			node->rightChild=deleteNodeWithKey(key, node->rightChild, 1);
			if(node->rightChild != NULL)node->rightChild->parent=node;

		} else{


			if(node->leftChild == NULL){

				//cout<<key<<" "<<"heheee"<<endl;


				if(node==this->root){


					this->root=node->rightChild;
					(node->rightChild)->parent=NULL;
					free(node);

				} else{


					//if(node->key==10)cout<<"hamao"<<endl;

					if(node==(node->parent)->leftChild){

						(node->parent)->leftChild=node->rightChild;
					
					}
					else if(node==(node->parent)->rightChild)(node->parent)->rightChild=node->rightChild;
					if(node->rightChild!=NULL)(node->rightChild)->parent=node->parent;

				}

				return node->rightChild;

			} else if(node->rightChild == NULL){

				//cout<<key<<" "<<"heheeee"<<endl;

				if(node==this->root){

					this->root=node->leftChild;
					(node->leftChild)->parent=NULL;
					free(node);

				} else{

					if(node==(node->parent)->leftChild)(node->parent)->leftChild=node->leftChild;
					if(node==(node->parent)->rightChild)(node->parent)->rightChild=node->leftChild;
					if(node->leftChild!=NULL)(node->leftChild)->parent=node->parent;

				}

				return node->leftChild;

			} else{

				//cout<<key<<" "<<"heheeeee"<<endl;

				struct treeNode<K,V>* temp1=this->leftMostChild(node->rightChild);

				//cout<<temp1->key<<endl;

				node->key=temp1->key;
				node->value=temp1->value;
				K key2=node->key;

				//cout<<node->rightChild->key<<endl;

				node->rightChild=deleteNodeWithKey(key2, node->rightChild, 1);

				if(node->rightChild!=NULL)(node->rightChild)->parent=node;

			}

		}


	}


	node->height=max(getHeight(node->leftChild), getHeight(node->rightChild))+1;

	ll balance=getHeight(node->leftChild)-getHeight(node->rightChild);

	if(balance>=-1 && balance<=1)return node;
	else if(balance < -1){

		struct treeNode<K,V> *temp1=node->rightChild;
		if(getHeight(temp1->leftChild)>getHeight(temp1->rightChild))node->rightChild=rightRotate(temp1);
		return leftRotate(node);

	} else{


		struct treeNode<K,V> *temp=node->leftChild;
		if(getHeight(temp->rightChild)>getHeight(temp->leftChild))node->leftChild=leftRotate(temp);
		return rightRotate(node);

	}



}







