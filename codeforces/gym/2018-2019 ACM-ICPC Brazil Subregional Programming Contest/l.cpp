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

int n,q;
vi adj[100100];
int hgt[100100],pai[100100][30],vis[101101];

void dfs(int u){

	vis[u]=1;
	
	for(int i=1;i<25;i++)
		pai[u][i]=pai[pai[u][i-1]][i-1];
	
	for(auto x : adj[u]){
		if(vis[x])	continue;
		pai[x][0]=u;
		hgt[x]=1+hgt[u];
		dfs(x);
	}

}

int lca(int a, int b){

	if(hgt[a]<hgt[b])
		swap(a,b);

	for(int i=24;i>=0;i--){
		if(hgt[pai[a][i]]>=hgt[b])
			a=pai[a][i];
	}

	if(a==b)
		return a;

	for(int i=24;i>=0;i--){
		if(pai[a][i]!=pai[b][i])
			a=pai[a][i], b=pai[b][i];
	}

	return pai[a][0];

}

int dist(int a, int b){
	return hgt[a]+hgt[b]-2*hgt[lca(a,b)];
}

int main(){
 
	fastio;

	cin >> n >> q;

	fr(i,n-1){
		int a,b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	pai[1][0]=1;
	dfs(1);

	while(q--){
		
		int a,b,c,d;
		cin >> a >> b >> c >> d;

		int ans = dist(a,b) + dist(c,d);
		ans-= min(dist(a,c)+dist(b,d), dist(a,d) + dist(b,c));

		cout << max(ans/2 + 1,0) << endl;

	}
 
}