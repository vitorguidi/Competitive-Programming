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
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;
typedef pair<double, double> point;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

vii cycle;
vi nodes[550];
int vis[550];
int pai[550];

int dfs2(int v, int p1, int p2){

	vis[v]=1;

	int ans = 0;

	for(auto x : nodes[v]){

		if(vis[x]==2 || (x==p1 && v==p2) || (x==p2 && v==p1))	continue;

		else if(vis[x]==1)	ans++;

		else if(!vis[x])	ans+=dfs2(x,p1,p2);
	}

	vis[v]=2;

	return ans;

}

void dfs(int v){

	vis[v]=1;

	for(auto x : nodes[v]){

		if(vis[x]==2)
			continue;
		
		else if(vis[x]==1 && cycle.empty()){

			cycle.pb({x,v});
			int y = v;

			while(y!=x){
				cycle.pb({y,pai[y]});
				y=pai[y];
			}
		
		}

		else if(vis[x]==0){
			pai[x]=v;
			dfs(x);
		}


	}

	vis[v]=2;

}


int main(){

	fastio;

	int n,m;
	cin >> n >> m;

	fr(i,m){
		int x,y;
		cin >> x >> y;
		nodes[x].pb(y);
	}

	frr(i,n)
		if(!vis[i])
			dfs(i);

	if(cycle.empty()){
		puts("YES");
		return 0;
	}

	// for(auto x : cycle){
	// 	dbg(x.fst);
	// 	dbg(x.snd);
	// 	gnl;
	// }

	for(auto x : cycle){
		ms(vis,0);
		int amt=0;
		frr(i,n)
			if(!vis[i])
				amt+=dfs2(i,x.fst,x.snd);
		if(!amt){
			puts("YES");
			return 0;
		}
	}

	puts("NO");


}