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

int v[100100],segtree[400400];

void build(int node, int l, int r){

	if(l==r){
		segtree[node]=v[l];
		return;
	}

	int mid = (l+r)/2;

	build(2*node,l,mid);
	build(2*node+1,mid+1,r);

	segtree[node]=min(segtree[2*node],segtree[2*node+1]);

}

int query(int node, int l, int r, int a, int b){

	if(r<a || l>b)
		return INF;

	if(l==r)
		return v[l];


	if (a<=l && r<=b)
		return segtree[node];

	int mid = (l+r)/2;

	int left = query(2*node,l,mid,a,b);
	int right = query(2*node+1,mid+1,r,a,b);

	return min(left,right);

}

int main(){
	int cnt=0;
	int t; cin >> t;
	
	while(t--){
		cnt++;
	
		int n,q;
		cin >> n >> q;
	
		frr(i,n)
			cin >> v[i];

		build(1,1,n);

		cout << "Scenario #" << cnt << ":" << endl;
	
		fr(i,q){
			int a,b; cin >> a >> b;
			cout << query(1,1,n,a,b) << endl;
		}

	}

}