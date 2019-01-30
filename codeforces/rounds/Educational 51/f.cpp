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
typedef vector<vector<ll>> matrix;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

vector<pll> nodes[100100];
map<pii,int> used;

set<int> caras;
int vis[100100];
int hgt[100100];

ll dist[100100];
ll d[50][100100];

int memo[100100][30];
vi repo;
int clk;

void dfs(int v){
	
	vis[v]=1;

	for(auto x : nodes[v]){
	
		if(vis[x.snd])	continue;

		used[{x.snd,v}]=used[{v,x.snd}]=1;
	
		memo[x.snd][0]=v;
		for(int i=1;i<30;i++)
			memo[x.snd][i]=memo[ memo[x.snd][i-1] ][i-1];
	
		hgt[x.snd]=1+hgt[v];
		dist[x.snd]=x.fst+dist[v];
	
		dfs(x.snd);
	}

}

int lca(int a, int b){

	if(hgt[a]<hgt[b])
		swap(a,b);

	for(int i=29;i>=0;i--)
		if(hgt[memo[a][i]]>=hgt[b])
			a=memo[a][i];
	
	if(a==b)	return a;


	for(int i=29;i>=0;i--){
		if(memo[a][i]!=memo[b][i]){
			a=memo[a][i];
			b=memo[b][i];
		}
	}

	return memo[a][0];

}

void dijkstra(int v){

	fr(i,100100)
		d[clk][i]=(ll)1e18;

	d[clk][v]=0;

	set<pll> fila;
	fila.insert({0,v});

	while(!fila.empty()){

		pll pai = *fila.begin();
		fila.erase(fila.begin());

		for(auto x :  nodes[pai.snd]){

			int filho = x.snd;
			ll wgt = x.fst;
			
			if( d[clk][filho] > d[clk][pai.snd] + wgt ){

				fila.erase( {d[clk][filho],filho} );
				d[clk][filho]=d[clk][pai.snd]+wgt;
				fila.insert({d[clk][filho],filho});
			
			}

		}

	}

}

int main(){

	fastio;

	int n,m;
	cin >> n >> m;

	fr(i,30)
		memo[1][i]=1;

	vii edg;


	frr(i,m){
		ll x,y,w;
		cin >> x >> y >> w;
		nodes[x].pb({w,y});
		nodes[y].pb({w,x});
		edg.pb({x,y});
	}

	dfs(1);

	for(auto x : edg){
		if(!used[{x.fst,x.snd}]){
			caras.insert(x.fst);
			caras.insert(x.snd);
		}
	}


	for(auto x : caras)
		repo.pb(x);

	for(auto x : repo){
		dijkstra(x);
		clk++;
	}

	int q; cin >> q;
	int len = repo.size();
	
	fr(i,q){

		int x,y;
		cin >> x >> y;
	
		ll ans = dist[x]+dist[y];
		ans-=2ll*dist[lca(x,y)];

		fr(a,len)
			ans=min<ll>(ans,d[a][x]+d[a][y]);
		
		cout << ans << endl;

	}

}