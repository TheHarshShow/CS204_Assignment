#include <bits/stdc++.h>

#include "stack.h"

#define ll long long
#define REP(i,a,b) for(ll i=a; i<b; i++)
#define ldb long double

using namespace std;

template<typename T>
stacc<T>::stacc(){

	list=(T *)malloc(sizeof(T));
	size=1;
	curr=0;

}

template<typename T>
void stacc<T>::push(T x){

	if(curr==size){

		T *temp=(T *)malloc(2*(size)*sizeof(T));
		T *temp2=list;

		REP(i,0,size){

			temp[i]=(list)[i];

		}

		temp[curr]=x;
		curr++;
		list=temp;
		free(temp2);
		size*=2;

	} else{


		(list)[curr]=x;
		curr++;

	}

}

template<typename T>
T stacc<T>::pop(){

	if(size>=4 && curr==size/4){

		T *temp=(T *)malloc(size/2*sizeof(T));
		T *temp2=list;

		REP(i,0,curr){

			temp[i]=list[i];

		}
		size/=2;
		list=temp;
		curr--;
		free(temp2);
		return list[curr];

	}

	if(curr>0){
		
		curr--;
		return list[curr];

	} else {
		cout<<(string)NULL<<endl;
		return 0;
	}

}

template<typename T>
T stacc<T>::top(){

	if(curr>0)return (list)[curr-1];
	else {

		cout<<(string)NULL<<endl;
		return 0;

	}
}

template<typename T>
ll stacc<T>::getSize(){

	return size;

}

template<typename T>
ll stacc<T>::getNumberOfElementsInStacc(){

	return curr;

}

template<typename T>
bool stacc<T>::isEmpty(){

	if(curr==0)return true;
	return false;
}

template<typename T>
bool stacc<T>::isFull(){

	if(curr==size)return true;
	return false;

}





