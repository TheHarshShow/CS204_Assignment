#import<bits/stdc++.h>

#define ll long long
#define REP(i,a,b) for(ll i=a; i<b; i++)

using namespace std;

class cue{


private:
	ll * list;
	ll p1;
	ll curr;
	ll size;

public:


	cue(){

		list=(ll *)malloc(1*sizeof(ll));
		p1=0;
		curr=0;
		size=1;

	}

	void enqueue(ll x){

		if(curr%size!=p1%size){

			list[curr%size]=x;
			curr++;
		}
		else{

			if(curr==p1){

				list[curr%size]=x;
				curr++;

			} else{

				ll *temp=(ll *)malloc(2*(size)*sizeof(ll));
				ll *temp2=list;


				REP(i,0,size){

					temp[i]=list[(i+p1)%size];

				}

				p1=0;
				curr=size;
				size*=2;
				list=temp;
				list[curr%size]=x;
				curr++;
				free(temp2);

			}

		}

	}

	ll dequeue(){

		if(size >= 4 && (curr-p1)==size/4){


			ll *temp=(ll *)malloc(size/2*sizeof(ll));
			ll *temp2=list;

			REP(i,0,size/4){

				temp[i]=list[(i+p1)%size];

			}

			p1=0;
			curr=size/4;
			size/=2;
			list=temp;
			p1++;
			free(temp2);

			return list[0];

		}


		if(p1%size!=curr%size){p1++;return list[(p1-1)%size];}
		else{

			if(curr==p1){

				return -1;

			} else{

				p1++;
				return list[p1%size];

			}

		}


	}

	ll front(){

		if(curr==p1)return -1;
		return list[p1%size];

	}

	ll back(){

		if(curr==p1)return -1;
		return list[(curr-1)%size];

	}

	ll getSize(){
		return size;
	}

};


int main(){


	cue q1;
	ll t;

	while(cin>>t){

		if(t==1){

			ll t2;
			cin>>t2;
			q1.enqueue(t2);
			cout<<q1.getSize()<<" "<<q1.front()<<" "<<q1.back()<<endl;

		} else if(t==2){

			cout<<q1.dequeue()<<" "<<q1.getSize()<<" "<<q1.front()<<" "<<q1.back()<<endl;


		}

	}

}
