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

int v[200200], segtree[800800];

void build(int node, int l, int r){

	if(l==r){
		segtree[node]=v[l];
		return;
	}

	int mid = (l+r)/2;

	build(2*node,l,mid);
	build(2*node+1,mid+1,r);
	segtree[node] = segtree[2*node] + segtree[2*node+1];

}

int query(int node, int l, int r, int a, int b){

	if(l>b || r<a)
		return 0;

	if(l==r)
		return v[l];

	if(l>=a && r<=b)
		return segtree[node];

	int mid = (l+r)/2;

	int left = query(2*node,l,mid,a,b);
	int right = query(2*node+1,mid+1,r,a,b);

	return left + right;

}

void update(int node, int l, int r, int id, int val){

	if(l==r){
		segtree[node]=val;
		v[id]=val;
		return;
	}


	int mid = (l+r)/2;

	if(id<=mid)
		update(2*node,l,mid,id,val);

	else
		update(2*node+1,mid+1,r,id,val);

	segtree[node]=segtree[2*node]+segtree[2*node+1];

}


int main(){

	
	fastio;
	int n,cnt=0;

	while(cin >> n){

		if(!n)
			break;
		if(cnt!=0)
			gnl;

		cnt++;
		frr(i,n)
			cin >> v[i];

		build(1,1,n);

		string op;
		int x,y;
		cout << "Case " << cnt << ":" << endl;
		
		while(cin >> op){
			if(op=="END")
				break;
			cin >> x >> y;
			if(op=="M")
				cout << query(1,1,n,x,y) << endl;
			else
				update(1,1,n,x,y);
		}
		
	}

}