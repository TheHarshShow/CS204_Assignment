#include <bits/stdc++.h>
#include "binaryTree.h"


#define ll long long
#define ldb long double
#define REP for(ll i=a; i<b; i++)

using namespace std;

template<typename K, typename V>
struct treeNode<K,V> *BinaryTree<K,V>::createNode(){

	treeNode<K,V> * temp=(treeNode<K,V> *)malloc(10*sizeof(treeNode<K,V>));

	temp->height=0;
	temp->leftChild=NULL;
	temp->rightChild=NULL;
	temp->parent=NULL;
	return temp;

}

template<typename K, typename V>
BinaryTree<K,V>::BinaryTree(){

	root=NULL;
	flagToAssistWithGetNode=0;

}

template<typename K, typename V>
void BinaryTree<K,V>::getNodeWithKeyAssistant(K key, struct treeNode<K,V> *node, ll flag){

	if(flagToAssistWithGetNode)return;

	if(!flag && node==NULL){

		flag=1;
		node=root;

	}

	if(node==NULL && flag)return;

	//cout<<node->key<<endl;

	if(node->key==key){

		nodeToAssistWithGetNode=node;
		flagToAssistWithGetNode=1;

		//cout<<flagToAssistWithGetNode<<endl;

		return;

	}

	getNodeWithKeyAssistant(key, node->leftChild, 1);
	getNodeWithKeyAssistant(key, node->rightChild, 1);

}

template<typename K, typename V>
bool BinaryTree<K,V>::findNodeWithKey(K key){

	getNodeWithKeyAssistant(key);
	if(flagToAssistWithGetNode){

		flagToAssistWithGetNode=0;
		return true;

	}

	return false;
}

template<typename K, typename V>
struct treeNode<K,V> * BinaryTree<K,V>::getNodeWithKey (K key) {


	getNodeWithKeyAssistant(key);

	if(flagToAssistWithGetNode) {
		flagToAssistWithGetNode=0;
	 	return nodeToAssistWithGetNode;

	 } else{
	 	return NULL;
	 }



}

template<typename K, typename V>
void BinaryTree<K,V>::insert(K key, V value, struct treeNode<K,V> * parent, asChild childflag){

	if(parent==NULL)parent=root;

	if(root==NULL){

		root=createNode();
		root->key = key;
		root->value = value;
		root->leafFlag=1;

	} else{

		struct treeNode<K,V> *temp=createNode();
		temp->key=key;
		temp->value=value;

		if(childflag == left){

			temp->leftChild=parent->leftChild;
			temp->parent=parent;
			parent->leftChild=temp;

			if(temp->leftChild == NULL){

				temp->leafFlag=1;

			} else{

				(temp->leftChild)->parent=temp;


			}

			

			parent->leafFlag=0;

		} else{

			temp->rightChild=parent->rightChild;
			temp->parent=parent;
			parent->rightChild=temp;

			if(temp->rightChild == NULL)temp->leafFlag=1;

			else{

				(temp->rightChild)->parent=temp;

			}

			parent->leafFlag=0;


		}

		

	}

}

template<typename K, typename V>
struct treeNode<K,V> *BinaryTree<K,V>::leftMostChild (struct treeNode<K,V> * tempNode){

	struct treeNode<K,V> * temp=tempNode;
	while(temp->leftChild != NULL){

		temp=temp->leftChild;

	}

	return temp;


}

template<typename K, typename V>
struct treeNode<K,V> * BinaryTree<K,V>::getParent(struct treeNode<K,V> * node){

	return node->parent;

}

template<typename K, typename V>
void BinaryTree<K,V>::deleteNode(struct treeNode<K,V> *nodeToBeDeleted){


	if(nodeToBeDeleted == root){



		if(nodeToBeDeleted->leftChild == NULL){


			root=nodeToBeDeleted->rightChild;
			root->parent=NULL;
			free(nodeToBeDeleted);

		} else if(nodeToBeDeleted->rightChild == NULL){


			root=nodeToBeDeleted->leftChild;
			root->parent=NULL;
			free(nodeToBeDeleted);

		} else{


			struct treeNode <K,V> *tempNode=leftMostChild(nodeToBeDeleted->rightChild);
			nodeToBeDeleted->key=tempNode->key;
			nodeToBeDeleted->value=tempNode->value;
			deleteNode(tempNode);

		}

	} else {

		if(nodeToBeDeleted->leftChild == NULL){

			//cout<<(nodeToBeDeleted->parent)->key<<endl;

			if(nodeToBeDeleted==(nodeToBeDeleted->parent)->leftChild){

				if(nodeToBeDeleted->rightChild == NULL){

					if((nodeToBeDeleted->parent)->rightChild==NULL){



						(nodeToBeDeleted->parent)->leafFlag=1;
						(nodeToBeDeleted->parent)->leftChild=NULL;
						free(nodeToBeDeleted);

					} else{



						(nodeToBeDeleted->parent)->leftChild=NULL;
						free(nodeToBeDeleted);

					}

				} else{



					(nodeToBeDeleted->parent)->leftChild=nodeToBeDeleted->rightChild;
					(nodeToBeDeleted->rightChild)->parent=nodeToBeDeleted->parent;
					free(nodeToBeDeleted);

				}

			} else {

				if(nodeToBeDeleted->rightChild == NULL){


					if((nodeToBeDeleted->parent)->leftChild==NULL){



						(nodeToBeDeleted->parent)->leafFlag=1;
						(nodeToBeDeleted->parent)->rightChild=NULL;
						free(nodeToBeDeleted);

					} else{


						(nodeToBeDeleted->parent)->rightChild=NULL;
						free(nodeToBeDeleted);

					}

				} else{



					(nodeToBeDeleted->parent)->rightChild=nodeToBeDeleted->rightChild;
					(nodeToBeDeleted->rightChild)->parent=nodeToBeDeleted->parent;
					free(nodeToBeDeleted);

				}

			}


		} else if(nodeToBeDeleted->rightChild == NULL){

			if(nodeToBeDeleted==(nodeToBeDeleted->parent)->leftChild){

				if(nodeToBeDeleted->leftChild == NULL){


					if((nodeToBeDeleted->parent)->rightChild==NULL){

						(nodeToBeDeleted->parent)->leafFlag=1;
						(nodeToBeDeleted->parent)->leftChild=NULL;
						free(nodeToBeDeleted);

					} else{

						(nodeToBeDeleted->parent)->rightChild=NULL;
						free(nodeToBeDeleted);

					}

				}else{

					(nodeToBeDeleted->parent)->leftChild=nodeToBeDeleted->leftChild;
					(nodeToBeDeleted->leftChild)->parent=nodeToBeDeleted->parent;
					free(nodeToBeDeleted);						

				}

			} else {


				if(nodeToBeDeleted->leftChild == NULL){


					if((nodeToBeDeleted->parent)->leftChild==NULL){

						(nodeToBeDeleted->parent)->leafFlag=1;
						(nodeToBeDeleted->parent)->rightChild=NULL;
						free(nodeToBeDeleted);

					} else{


						(nodeToBeDeleted->parent)->rightChild=NULL;
						free(nodeToBeDeleted);

					}

				}else{
				
					(nodeToBeDeleted->parent)->rightChild=nodeToBeDeleted->leftChild;
					(nodeToBeDeleted->leftChild)->parent=nodeToBeDeleted->leftChild;
					free(nodeToBeDeleted);
				}

			}


		} else{


			struct treeNode<K,V> *temp=leftMostChild(nodeToBeDeleted->rightChild);
			nodeToBeDeleted->key=temp->key;
			nodeToBeDeleted->value=temp->value;
			deleteNode(temp);

		}



	}

}

template<typename K, typename V>
void BinaryTree<K,V>::inorderPrint(struct treeNode<K,V> *node, ll flag){

	if(node==NULL && flag==0){
		//cout<<"Null root"<<endl;
		node=root;
		flag=1;
	}

	if(node==NULL && flag)return;

	inorderPrint(node->leftChild, 1);
	cout<<node->key<<": "<<node->value<<endl;
	inorderPrint(node->rightChild, 1);


}

template<typename K, typename V>
void BinaryTree<K,V>::preorderPrint(struct treeNode<K,V> *node, ll flag){

	if(node==NULL && flag==0){
		//cout<<"Null root"<<endl;
		node=root;
		flag=1;
	}

	if(node==NULL && flag)return;

	cout<<node->key<<": "<<node->value<<endl;

	preorderPrint(node->leftChild, 1);
	preorderPrint(node->rightChild, 1);


}

template<typename K, typename V>
void BinaryTree<K,V>::postorderPrint(struct treeNode<K,V> *node, ll flag){

	if(node==NULL && flag==0){
		//cout<<"Null root"<<endl;
		node=root;
		flag=1;
	}

	if(node==NULL && flag)return;

	postorderPrint(node->leftChild, 1);
	postorderPrint(node->rightChild, 1);
	cout<<node->key<<": "<<node->value<<endl;


}

template<typename K, typename V>
struct treeNode<K,V> *BinaryTree<K,V>::getRoot(){

	return root;

}

template<typename K, typename V>
bool BinaryTree<K,V>::isLeaf(struct treeNode<K,V>* node){

	if(node->leafFlag)return true;
	else return false;

}

template<typename K, typename V>
V BinaryTree<K,V>::getValueForKey(K key){

	if(findNodeWithKey(key)){

		getNodeWithKeyAssistant(key);
		flagToAssistWithGetNode=0;
		return nodeToAssistWithGetNode->value;

	} else return NULL;


}




