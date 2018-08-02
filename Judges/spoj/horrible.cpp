#include "bits/stdc++.h"
using namespace std;
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)
#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;
typedef vector< vector<ll> > matrix;
const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;
const ll mod = 1e9+7;
	
ll segtree[400400],lazy[400400];

void update(int node, int l, int r, int a, int b, ll val){

	int lc=2*node,rc=2*node+1,mid=(l+r)/2;

	if(lazy[node]){
		segtree[node]+=lazy[node]*(r-l+1);
		if(l!=r){
			lazy[rc]+=lazy[node];
			lazy[lc]+=lazy[node];
		}
		lazy[node]=0;
	}

	if(l>b || r<a || l>r)	return;

	else if(a<=l && r<=b){
		segtree[node]+=val*(r-l+1);
		if(l!=r){
			lazy[lc]+=val;
			lazy[rc]+=val;
		}
	}

	else{
		update(lc,l,mid,a,b,val);
		update(rc,mid+1,r,a,b,val);
		segtree[node]=segtree[lc]+segtree[rc];	
	}

}

ll query(int node, int l, int r, int a, int b){

	int lc=2*node,rc=2*node+1,mid=(l+r)/2;

	if(lazy[node]){
		segtree[node]+=lazy[node]*(r-l+1);
		if(l!=r){
			lazy[rc]+=lazy[node];
			lazy[lc]+=lazy[node];
		}
		lazy[node]=0;
	}

	if(l>b || r<a || l>r)	return 0;

	else if(a<=l && r<=b)	return segtree[node];

	else return query(lc,l,mid,a,b) + query(rc,mid+1,r,a,b);

}

int main(){

	int t; cin >> t;

	while(t--){
	
		ms(lazy,0);ms(segtree,0);
		int n,c; cin >> n >> c;
		fr(i,c){
			int t,p,q; ll v; cin >> t >> p >> q;
			if(!t){
				cin >> v;
				update(1,1,n,p,q,v);
			}
			else
				cout << query(1,1,n,p,q) << endl;
		}

	}
	
}