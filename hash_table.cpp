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

bool searchInList(struct node *sent, ll key){


	struct node *temp=sent->next;

	while(temp!=sent){

		if(temp->key==key)return true;

		temp=temp->next;
	}

	return false;

}


void insertInHashTable(struct node **table, ll n){

	ll t=n%97;
	addKeyAtBegin(n, table[t]);


}

void deleteInTable(struct node **table, ll n){


	ll t=n%97;
	deleteKey(n, table[t]);

}

bool searchInTable(struct node **table, ll n){

	ll t=n%97;

	return searchInList(table[t], n);


}


int main(){

	struct node *table[97];

	REP(i,0,97){

		table[i]=createNode();

	}

	insertInHashTable(table, 53);

	insertInHashTable(table, 97);

	insertInHashTable(table, 150);
	insertInHashTable(table, 151);
	insertInHashTable(table, 151);

	insertInHashTable(table, 96);
	insertInHashTable(table, 96+97);

	deleteInTable(table, 151);
	deleteInTable(table, 151);


	REP(i,0,97){cout<<i<<": ";print(table[i]);}


	cout<<searchInTable(table, 193)<<searchInTable(table, 96)<<searchInTable(table, 97)<<searchInTable(table, 151)<<endl;

}




