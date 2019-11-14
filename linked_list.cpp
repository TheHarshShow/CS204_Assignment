#include <bits/stdc++.h>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
 
#define io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (ll i = a; i < b; i++)
#define enl "\n"
#define INF std::numeric_limits<ll>::max()
#define F first
#define S second
 
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ldb;
typedef vector<long long> vll;
typedef pair<long long,long long> pll;

struct node {

	ll key;
	struct node *next;
	struct node * prev;

};

struct node *createNode(){

	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->next=temp;
	temp->prev=temp;
	return temp;

}

void addKeyAfter(ll k1, ll k2, struct node *sent){

	struct node *temp=sent->next;


	while(temp!=sent){

		if(temp->key==k2){

			struct node *temp2=createNode();
			temp2->key=k1;
			temp2->next=temp->next;
			temp2->prev=temp;
			(temp2->next)->prev=temp2;
			temp->next=temp2;
			return;

		}

		temp=temp->next;

	}

	cout<<"Key not found"<<endl;


}


void addKeyAtBegin(ll k1, struct node *sent){

	struct node *temp=createNode();

	temp->key=k1;

	temp->next=sent->next;
	temp->prev=sent;
	(sent->next)->prev=temp;
	sent->next=temp;

}


void addAtEnd(ll k1, struct node *sent){


	struct node *temp=createNode();

	temp->key=k1;

	temp->next=sent;
	temp->prev=sent->prev;
	(sent->prev)->next=temp;
	sent->prev=temp;



}


void print(struct node *sent){

	struct node *temp=sent->next;

	while(temp!=sent){

		cout<<temp->key<<" ";

		temp=temp->next;
	}

	cout<<endl;

}

void deleteKey(ll k1, struct node *sent){

	struct node *temp=sent->next;
	while(temp!=sent){

		if(temp->key==k1){

			struct node *temp2=temp->prev;
			temp2->next=temp->next;
			(temp2->next)->prev=temp2;
			free(temp);
			return;
		}

		temp=temp->next;
	}

	cout<<"Key not found"<<endl;

}

void deleteFront(struct node *sent){

	struct node *temp=(sent)->next;

	if(temp==sent){cout<<"Empty"<<endl;return;}

	sent->next=temp->next;
	(temp->next)->prev=sent;
	free(temp);

}

void deleteBack(struct node *sent){

	struct node *temp=(sent)->prev;

	if(temp==sent){cout<<"Empty"<<endl;return;}

	sent->prev=temp->prev;
	(temp->prev)->next=sent;
	free(temp);
}


bool isEmpty(struct node *sent){

	if(sent->next==sent)return true;
	return false;

}

void printRev(struct node *sent){

	struct node *temp=sent->prev;

	while(temp!=sent){

		cout<<temp->key<<" ";

		temp=temp->prev;
	}

	cout<<endl;



}

int main(){


	struct node *sent=createNode();

	addKeyAtBegin(3, sent);
	addKeyAtBegin(4, sent);
	addKeyAtBegin(7, sent);
	addKeyAtBegin(8, sent);

	addAtEnd(10, sent);
	addAtEnd(11, sent);
	addAtEnd(12, sent);
	addAtEnd(13, sent);

	deleteKey(8,sent);

	addKeyAfter(23, 12, sent);

	print(sent);
	printRev(sent);


}


