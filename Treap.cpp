#include<time.h>
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
using namespace std; 

struct NODE {

    ll key;
    ll priority; 

    struct NODE *left;
    struct NODE *right; 

};

struct NODE *rightRotate(struct NODE *y) 
{ 
    struct NODE *x = y->left;
    struct NODE *z = x->right;
    x->right = y;
    y->left = z;

    return x;
}

struct NODE *leftRotate(struct NODE *x) { 

    struct NODE *y = x->right;
    struct NODE *z = y->left;
    y->left = x;
    x->right = z;

    return y;
}

struct NODE* newNode(ll key) { 

    struct NODE* temp = new struct NODE;
    temp->key = key;
    temp->priority = rand()%100;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

struct NODE* search(struct NODE* root, ll key) {

    if (root == NULL || root->key == key) return root;
    if (root->key < key) return search(root->right, key);

    return search(root->left, key);
} 

struct NODE* insertNodeWithKey(struct NODE* root, ll key) {
	
    if (!root) return newNode(key);
    if (key <= root->key) 
    {

        root->left = insertNodeWithKey(root->left, key);
        if (root->left->priority > root->priority) root = rightRotate(root); 

    } 
    else
    {

        root->right = insertNodeWithKey(root->right, key);
        if (root->right->priority > root->priority) root = leftRotate(root); 

    } 

    return root;
}

struct NODE* deleteNode(struct NODE* root, ll key) 
{ 
    if (root == NULL) return root;
  
    if (key < root->key) root->left = deleteNode(root->left, key);
    else if (key > root->key) root->right = deleteNode(root->right, key);
    else if (root->left == NULL) {
        struct NODE *temp = root->right; 
        delete(root);
        root = temp;
    }
    else if (root->right == NULL) { 
        struct NODE *temp = root->left; 
        delete(root);
        root = temp;
    } else if (root->left->priority < root->right->priority) { 
        root = leftRotate(root); 
        root->left = deleteNode(root->left, key); 
    } 
    else { 
        root = rightRotate(root); 
        root->right = deleteNode(root->right, key); 
    } 
  
    return root; 
} 

void inorderPrint(struct NODE* root) 
{ 
    if (root) { 
        inorderPrint(root->left); 
        cout<<root->key<<" "<<root->priority; 
        if (root->left) cout<<" l: " <<root->left->key; 
        if (root->right) cout<<" r: "<<root->right->key; 
        cout << endl; 

        inorderPrint(root->right); 
    } 
} 

int main() { 

    srand(time(NULL));
  
    struct NODE *root = NULL;
    root = insertNodeWithKey(root, 50);
    root = insertNodeWithKey(root, 30);
    root = insertNodeWithKey(root, 20);
    root = insertNodeWithKey(root, 40);
    root = insertNodeWithKey(root, 70); 
    root = insertNodeWithKey(root, 60);
    root = insertNodeWithKey(root, 80);
  
    inorderPrint(root); 
  
  	cout<<endl;

    root = deleteNode(root, 50);
    inorderPrint(root); 
   
  	cout<<endl;

    root = deleteNode(root, 20); 
    inorderPrint(root); 
  
   	cout<<endl;

    root = deleteNode(root, 30);
    inorderPrint(root); 
  
    cout<<endl;

    root=deleteNode(root, 70);
    inorderPrint(root);

    cout<<endl;

    ll n;
    cin>>n;
    while(n--){

    	ll x;
    	cin>>x;
    	struct NODE *temp=search(root, x);
    	if(temp)cout<<"found"<<endl;
    	else cout<<"not found"<<endl;


    }
  
    return 0; 
}