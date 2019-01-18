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

int id[100100];
int sz[100100];
vii nodes[100100];

int pai[100100][20];
ll pesos[100100][20];
int vis[100100];
int hgt[100100];


int find(int x){
	if(id[x]==x)	return x;
	return id[x]=find(id[x]);
}

void join(int a, int b){
	a= find(a);
	b= find(b);
	if(a==b)	return;
	if(sz[a]<sz[b])	swap(a,b);
	id[b]=a;
	sz[a]+=sz[b];
}

void dfs(int v){
	
	vis[v]=1;
	
	for(auto x : nodes[v]){

		if(vis[x.snd])	continue;
		
		pai[x.snd][0]=v;
		pesos[x.snd][0]=x.fst;
		hgt[x.snd]=1+hgt[v];

		for(int i=1;i<20;i++){
			pai[x.snd][i]=pai[pai[x.snd][i-1]][i-1];
			pesos[x.snd][i]=min<ll>(pesos[x.snd][i-1],pesos[pai[x.snd][i-1]][i-1]);
		}

		dfs(x.snd);

	}
}

int lca(int a, int b){

	if(hgt[a]<hgt[b])	swap(a,b);

	for(int i=19;i>=0;i--){
		if( hgt[pai[a][i]]>=hgt[b] )
			a=pai[a][i];
	}

	if(a==b)	return a;

	for(int i=19;i>=0;i--){
		if(pai[a][i]!=pai[b][i]){
			a=pai[a][i];
			b=pai[b][i];
		}
	}

	return pai[a][0];

}

int main(){

	fastio;

	int n,m,s;
	cin >> n >> m >> s;

	frr(i,n){
		id[i]=i;
		sz[i]=1;
	}

	vector<tuple<int,int,int>> edges;

	fr(i,m){
		int a,b,w;
		cin >> a >> b >> w;
		edges.pb(make_tuple(w,a,b));
	}

	sort(all(edges));
	reverse(all(edges));

	for(auto x : edges){
		int a = get<1>(x);
		int b = get<2>(x);
		int wgt = get<0>(x);

		if( find(a)!=find(b) ){
			join(a,b);
			nodes[a].pb({wgt,b});
			nodes[b].pb({wgt,a});
		}

	}

	fr(i,20){
		pai[1][i]=1;
		pesos[1][i]=llINF;
	}

	dfs(1);

	fr(i,s){
		
		int l,h;
		cin >> l >> h;

		int x = lca(l,h);
		ll ans = llINF;

		for(int i=19;i>=0;i--){
			if(hgt[pai[l][i]]>=hgt[x]){
				ans=min<ll>(ans,pesos[l][i]);
				l=pai[l][i];
			}
		}

		for(int i=19;i>=0;i--){
			if(hgt[pai[h][i]]>=hgt[x]){
				ans=min<ll>(ans,pesos[h][i]);
				h=pai[h][i];
			}
		}

		cout << ans << endl;

	}

}
