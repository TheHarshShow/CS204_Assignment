#include<bits/stdc++.h>
#include "queue.h"
#include "queue.cpp"
#define ll long long
#define REP(i,a,b) for(ll i=a; i<b; i++)


int main(){

	cue c1;
	while(true){

		ll x;
		cin>>x;
		if(x==0){

			ll y;
			cin>>y;
			c1.enqueue(y);
			cout<<c1.isEmpty()<<" "<<c1.front()<<" "<<c1.back()<<" "<<c1.getSize()<<endl;

		} else if(x==1){

			c1.dequeue();

			cout<<c1.isEmpty()<<" "<<c1.front()<<" "<<c1.back()<<" "<<c1.getSize()<<endl;

		} else if(x==2){

			cout<<c1.isEmpty()<<" "<<c1.front()<<" "<<c1.back()<<" "<<c1.getSize()<<endl;


		}

	}


}