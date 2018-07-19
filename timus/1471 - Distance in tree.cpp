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

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;

int n,hgt[50500],vis[50500];
ll d[50500];
int memo[50500][30],pai[50500];
vii nodes[50500];


void dfs(int x){

	vis[x]=1;

	for(auto filho : nodes[x]){
	
		int y=filho.snd;
		int wgt = filho.fst;

		if(vis[y])
			continue;

		pai[y]=x;
		hgt[y]=1+hgt[x];
		d[y]=wgt+d[x];
		dfs(y);

	}

}

void build_table(){

	fr(i,n)
		memo[i][0]=pai[i];
	for(int i=1;i<=20;i++)
		fr(j,n)
			memo[j][i] = memo[ memo[j][i-1] ][i-1];
}

int lca(int a, int b){

	if(hgt[a]<hgt[b])
		swap(a,b);

	for(int i=20;i>=0;i--)
		if(hgt[ memo[a][i] ] >= hgt[b])
			a=memo[a][i];
	
	if(a==b)
		return a;

	for(int i=20;i>=0;i--){
		if( memo[a][i] != memo[b][i]){
			a=memo[a][i];
			b=memo[b][i];
		}
	}

	return memo[a][0];

}

int main(){

	int u,v,w;

	cin >> n;

	fr(i,n-1){
		cin >> u >> v >> w;
		nodes[u].pb({w,v});
		nodes[v].pb({w,u});
	}

	dfs(0);

	build_table();

	int q; cin >> q;
		
	fr(i,q){
		int a,b;
		cin >> a >> b;
		int c = lca(a,b);
		ll ans = d[a] + d[b] - 2*d[c];
		cout << ans << endl;
 	}
 	return 0;
}