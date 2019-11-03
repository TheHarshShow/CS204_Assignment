#include<bits/stdc++.h>

#define ll long long
#define REP(i,a,b) for(ll i=a; i<b; i++)

using namespace std;

struct node{

	ll key;
	struct node * ptrf;
	struct node * ptrb;
	ll sentinelFlag;

};

struct node * makeNode(){

	struct node *neew=(struct node *)malloc(sizeof(struct node));
	neew->ptrf=NULL;
	neew->ptrb=NULL;
	neew->sentinelFlag=0;

	return neew;
}

class linkedList{

private:

	struct node *sentinel;


public:

	linkedList(){

		sentinel=makeNode();
		sentinel->sentinelFlag=1;
		sentinel->ptrf=sentinel;
		sentinel->ptrb=sentinel;

	}

	void addAtFront(struct node **x){

		(*x)->ptrf=sentinel->ptrf;
		(*x)->ptrb=sentinel;
		(sentinel->ptrf)->ptrb=*x;
		sentinel->ptrf=*x;

	}

	void addAtBack(struct node **x){

		(*x)->ptrf=sentinel;
		(*x)->ptrb=sentinel->ptrb;
		(sentinel->ptrb)->ptrf=*x;
		sentinel->ptrb=*x;

	}

	ll count(){

		struct node *temp=sentinel->ptrf;
		ll ctr=0;
		while(temp!=sentinel){

			temp=temp->ptrf;
			ctr++;

		}

		return ctr;
	}

	void addAfterKey(struct node **x, ll k){

		struct node *temp=sentinel->ptrf;
		ll flag=0;
		while(temp!=sentinel){

			if(temp->key == k){

				flag=1;
				(*x)->ptrf=temp->ptrf;
				(temp->ptrf)->ptrb=*x;
				(*x)->ptrb=temp;
				temp->ptrf=*x;

			}
			temp=temp->ptrf;

		}

		if(flag==0)addAtBack(x);

	}

	void addBeforeKey(struct node **x, ll k){

		struct node *temp=sentinel->ptrf;
		ll flag=0;
		while(temp!=sentinel){

			if(temp->key==k){

				temp=temp->ptrb;
				(*x)->ptrf=temp->ptrf;
				(*x)->ptrb=temp;
				(temp->ptrf)->ptrb=*x;
				temp->ptrf=*x;
				flag=1;
				break;

			}

			temp=temp->ptrf;


		}
		if(flag==0)addAtFront(x);
	}

	void printForward(){

		struct node *temp=sentinel->ptrf;
		while(temp!=sentinel){

			cout<<temp->key<<" ";
			temp=temp->ptrf;

		}

		cout<<endl;

	}

};


int main(){

	linkedList l1;

	while(true){

		ll t;
		cin>>t;
		if(t==1){

			struct node *x=makeNode();
			ll t2;
			cin>>t2;
			x->key=t2;
			l1.addAtFront(&x);
			l1.printForward();
			cout<<"count: "<<l1.count()<<endl;

		} else if(t==2){

			struct node *x=makeNode();
			ll t2;
			cin>>t2;
			x->key=t2;
			l1.addAtBack(&x);
			l1.printForward();
			cout<<"count: "<<l1.count()<<endl;


		} else if(t==3){

			ll a,b;
			cin>>a>>b;
			struct node *x=makeNode();
			x->key=a;

			l1.addAfterKey(&x,b);


		} else if(t==4){


			ll a,b;
			cin>>a>>b;
			struct node *x=makeNode();
			x->key=a;
			l1.addBeforeKey(&x,b);

		}

	}


}

