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

ll n,q;
ll cost;
int v1,v2;

vector<pll> nodes[100100];

ll memo[100100][20];
ll vis[100100];
ll hgt[100100];
ll d[100100];
bool flag;

void find_cycle(int v, int pai){

	vis[v]++;

	for(auto x : nodes[v]){

		if(vis[x.snd]==1 && x.snd!=pai){
			cost=x.fst;
			v1=x.snd;
			v2=v;
		}

		else if(!vis[x.snd])
			find_cycle(x.snd,v);
	
	}

	vis[v]++;

}

void dfs(int v){

	vis[v]=1;
	
	for(auto x : nodes[v]){

		if(vis[x.snd])	continue;
		
		if(x.snd==v1 && v==v2)	continue;

		if(x.snd==v2 && v==v1)	continue;

		d[x.snd] = x.fst+d[v];
		hgt[x.snd] = 1 + hgt[v];

		memo[x.snd][0] = v;
	
		for(int i=1;i<20;i++)
			memo[x.snd][i] = memo[ memo[x.second][i-1] ][i-1];
	
		dfs(x.snd);
	
	}


}

int lca(int a, int b){

	if(hgt[a]<hgt[b])	swap(a,b);

	for(int i=19;i>=0;i--)
		if(hgt[memo[a][i]]>=hgt[b])
			a=memo[a][i];

	if(a==b)	return a;

	for(int i=19;i>=0;i--){
		if(memo[a][i]!=memo[b][i]){
			a=memo[a][i];
			b=memo[b][i];
		}
	}
	
	return memo[a][0];

}


ll dist(int a, int b){
	return d[a]+d[b]-2ll*d[lca(a,b)];
}

ll calc(int a, int b){
	ll d1 = dist(a,b);
	ll d2 = dist(a,v1) + cost + dist(v2,b);
	ll d3 = dist(a,v2) + cost + dist(v1,b);
	return min<ll>({d1,d2,d3});
}

void solve(){
	
	cin >> n >> q;
		
	frr(i,n)	vis[i]=0;
	frr(i,n)	hgt[i]=0;

	fr(i,100100)	nodes[i].clear();

	fr(i,n){
		int x,y,w;
		cin >> x >> y >> w;
		nodes[x].pb({w,y});
		nodes[y].pb({w,x});
	}

	fr(i,20)	memo[1][i]=1;

	find_cycle(1,1);
	
	ms(vis,0ll);

	dfs(1);
	
	fr(i,q){		
		int x,y;
		cin >> x >> y;		
		cout << calc(x,y) << endl;
	}

}

int main(){

	fastio;

	int t; cin >> t;
	while(t--)	solve();

}