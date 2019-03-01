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

int pai[100100];
vi nodes[100100];
int vis[100100];
int sz[100100];

void dfs(int v){

	vis[v]=1;
	int nf=0;
	int best = 1;

	for(auto x: nodes[v]){
		if(vis[x])	continue;
		nf++;
		dfs(x);
		sz[v]+=sz[x];
	}

	if(!nf)	sz[v]=1;

}

int main(){
    
	fastio;

	int n; cin >> n;

	for(int i=2;i<=n;i++){
		int x; cin >> x;
		nodes[x].pb(i);
		nodes[i].pb(x);
	}

	dfs(1);

	vi ans;
	frr(i,n){
		ans.pb(sz[i]);
	}

	sort(all(ans));

	fr(i,n)	cout << ans[i] << " ";
	gnl;

}