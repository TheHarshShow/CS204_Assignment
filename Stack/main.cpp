#include <bits/stdc++.h>
#include "stack.h"
#include "stack.cpp"

#define ll long long
#define REP(i,a,b) for(ll i=a; i<b; i++)
#define ldb long double

using namespace std;

int main(){

	stacc<string> s1;
	while(true){

		ll t;
		cin>>t;
		if(t==0){

			string t1;
			cin>>t1;
			s1.push(t1);
			cout<<s1.getSize()<<endl;

		} else if(t==1){

			if(!s1.isEmpty())cout<<s1.pop()<<" "<<s1.getSize()<<endl;
			

		} else if(t==2){

			if(!s1.isEmpty())cout<<s1.top()<<" "<<s1.getSize()<<endl;

		}

	}

}