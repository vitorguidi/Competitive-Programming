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

vi nodes[300300];
int hgt[300300];
ll bit[300300];
int vis[300300];
ll ans[300300];
int pai[300300];
vector<pll> queries[300300];

void update(int ind, ll val){
	for(ll i=ind;i<300300;i+=i&-i)
		bit[i]+=val;
}

ll query(int ind){
	ll ans = 0;
	for(int i=ind;i>0;i-=i&-i)
		ans+=bit[i];
	return ans;
}

void dfs(int v){

	vis[v]=1;

	for(auto x : queries[v]){

		ll h = x.fst;
		ll val = x.snd;
		
		update(hgt[v],val);
		update(hgt[v]+h+1,-1ll*val);
	
	}


	ll cnt = query(hgt[v]);

	for(auto x : nodes[v]){

		if(vis[x])
			continue;
		
		pai[x]=v;
		hgt[x]=1+hgt[v];
		
		dfs(x);
	
	}


	for(auto x : queries[v]){
		
		ll h = x.fst;
		ll val = x.snd;
		
		update(hgt[v],-1ll*val);
		update(hgt[v]+h+1,val);
	
	}

	ans[v]=cnt;

}

int main(){

	fastio;

	int n; cin >> n;
	
	fr(i,n-1){
		int x,y;
		cin >> x >> y; 
		nodes[x].pb(y);
		nodes[y].pb(x);
	}

	int q; cin >> q;

	fr(i,q){
		ll v,d,x;
		cin >> v >> d >> x;
		queries[v].pb({d,x});
	}

	hgt[1]=pai[1]=1;
	dfs(1);

	frr(i,n)	cout << ans[i] << " ";
	gnl;
		
}