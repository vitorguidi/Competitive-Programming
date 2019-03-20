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
#define olar cout << "pira" << endl
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll; 

const int INF = 0x3f3f3f3f;

vector<pair<ll,ll>> nodes[100100];
ll when[100100];
int vis[110110];
int clk=1;
vi leaf;

void dfs(int u, int p,ll t){

	ll mn = INF;
	vis[u]=clk;
	int nf=0;
	when[u]=t;

	for(auto x : nodes[u]){
		if(vis[x.snd]==clk)	continue;
		mn=min(mn,x.fst);
		nf++;
	}		

	if(!nf)	leaf.pb(u);

	for(auto x : nodes[u]){
		if(vis[x.snd]==clk)	continue;
		ll aux = t +mn + (x.fst-mn)*2ll;
		dfs(x.snd,u,aux);
	}

}

///bananas de piajasmdasdas

void go(){

	int n; cin >> n;
	leaf.clear();

	frr(i,n)	nodes[i].clear();

	for(int i=2;i<=n;i++){
		int p,w;
		cin >> p >> w;
		nodes[p].pb({w,i});
		nodes[i].pb({w,p});
	}

	dfs(1,1,0);
	clk++;

	vector<ll> coiso;

	for(auto x : leaf)	coiso.pb(when[x]);
	sort(all(coiso));

	int q; cin >> q;
	while(q--){
		ll x; cin >> x;
		auto it = upper_bound(all(coiso),x);
		cout << it - coiso.begin() << endl;
	}

	

}

int main(){

	fastio;

	int t; cin >> t;
	while(t--)	go();

	
}