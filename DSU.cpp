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


ll find(ll k, ll parent[]){

	if(k==parent[k])return k;
	else return parent[k]=find(parent[k], parent);

}

void uni(ll k1, ll k2, ll parent[], ll size[]){

	k1=find(k1, parent);
	k2=find(k2, parent);

	cout<<k1<<" "<<k2<<endl;

	if(k1==k2)return;

	if(size[k1]>size[k2])swap(k1,k2);

	parent[k1]=k2;
	size[k2]+=size[k1];


}

int main(){

	ll parent[11];
	ll size[11];

	REP(i,1,11){

		size[i]=1;
		parent[i]=i;

	}

	uni(1,10, parent, size);
	cout<<find(1, parent)<<endl;
	cout<<find(10, parent)<<endl;

	uni(8,9, parent, size);
	cout<<find(9, parent)<<endl;
	cout<<find(8, parent)<<endl;

	uni(2,8, parent, size);
	cout<<find(2, parent)<<endl;
	cout<<find(8, parent)<<endl;



	uni(2,1, parent, size);
	cout<<find(1, parent)<<endl;
	cout<<find(10, parent)<<endl;






}




