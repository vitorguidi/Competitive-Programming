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
	return p;
}

int main(){

	fastio;

	int n,p,q; cin >> n >> p;

	int val; cin >> val;

	node* prev = create_node();

	prev->val=val;
	prev->l=NULL;
	prev->r=NULL;

	node* inicio = prev;

	fr(i,n-1){
		int x; cin >> x;

		node* now = create_node();
		
		now->l=prev;
		now->r=NULL;
		now->val=x;
		
		prev->r=now;
		if(i==0){
			inicio->r=now;
		}
		prev=now;
	
	}

	int pos = 1;

	while(pos!=p){
		inicio=inicio->r;
		pos++;
	}

	cin >> q;

	fr(i,q){
		string op; cin >> op;
		if(op=="print"){
		
			cout << inicio->val << endl;

		
		}
		else if(op=="moveLeft"){
		
			if(inicio->l!=NULL){
				inicio=inicio->l;
				p--;
			}
		
		}
		else if(op=="moveRight"){
		
			if(inicio->r!=NULL){
				inicio=inicio->r;
				p++;
			}
		
		}
		else if(op=="insertLeft"){

			int x; cin >> x;
		
			node* aux = create_node();
		
			aux->val=x;
		
			aux->r=inicio;
			aux->l=inicio->l;
		
			if(inicio->l!=NULL)
				inicio->l->r=aux;
		
			inicio->l=aux;
			p++;

		}
		else{
		
			int x; cin >> x;
		
			node* aux = create_node();
			aux->r=inicio->r;
			aux->val=x;
		
			if(inicio->r!=NULL)
				inicio->r->l=aux;
		
			inicio->r=aux;
		
			aux->l=inicio;

		}
	}

}
