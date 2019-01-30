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

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

vi nodes[200200];
int hgt1[200200];
int hgtx[200200];
int d1[200200];
int dx[200200];
int vis[200200];

int dfs1(int v){

	vis[v]=1;

	int best=hgt1[v];

	for(auto x : nodes[v]){

		if(vis[x])	continue;
	
		hgt1[x]=1+hgt1[v];
		best=max(best,dfs1(x));
	
	}

	return d1[v]=best;

}

int dfs2(int v){

	vis[v]=1;

	int best=hgtx[v];

	for(auto x : nodes[v]){
	
		if(vis[x])	continue;
	
		hgtx[x]=1+hgtx[v];
		best=max(best,dfs2(x));
	
	}

	return dx[v]=best;

}


int main(){
    
	fastio;

	int n,x; cin >> n >> x;

	fr(i,n-1){
		int a,b; cin >> a >> b;
		nodes[a].pb(b);
		nodes[b].pb(a);
	}

	dfs1(1);
	ms(vis,0);
	dfs2(x);

	int best=0;

	frr(i,n){

		int dalice=hgt1[i];
		int dbob=hgtx[i];

		if(dalice<=dbob)
			best=max(best,2*d1[x]);
		else
			best=max(best,2*d1[i]);
	}

	cout << best << endl;

}

