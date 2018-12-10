#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()

#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;
struct node{
	struct node* l;
	struct node* r;
	int val;
};
typedef struct node node;

node* create_node(){
	node* p = (node*)malloc(sizeof(node));
	p -> r = NULL;
	p -> l = NULL;
	return p;
}

ll add(int k,node* pai){
	if(k<pai->val){
		if(pai->l ==NULL){
			node* novo=create_node(); 
			novo->val=k; 
			pai->l=novo;
			return 1;
		} 
		return 1+ add(k,pai->l);
	}

	if(k>pai->val){
		if(pai->r ==NULL){
			node* novo=create_node(); 
			novo->val=k; 
			pai->r=novo;
			return 1;
		} 
		return 1+ add(k,pai->r);
	}

}


int main(){
	fastio;
	int n;
	cin >> n;
	int v[212345];
	fr(i,n) cin >> v[i];

	node* raiz;
	raiz = create_node();
	raiz -> val = v[0];

	ll x=0;
	for(int i =1;i<n;i++){
		x+= add(v[i],raiz);
	}
	cout<<x<<endl;
}
