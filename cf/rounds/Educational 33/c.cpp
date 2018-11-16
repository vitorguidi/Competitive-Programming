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

vi nodes[100100];
ll cost[100100];
int vis[100100];

ll dfs(int v){
	vis[v]=1;
	ll ans = cost[v];
	for(auto x : nodes[v]){
		if(vis[x])	continue;
		ans = min<ll>(ans,dfs(x));
	}
	return ans;
}

int main(){
    
	fastio;

	int n,m; cin >> n >> m;

	frr(i,n)	cin >> cost[i];

	frr(i,m){
		int x,y;
		cin >> x >> y;
		nodes[y].pb(x);
		nodes[x].pb(y);
	}

	ll ans = 0;
	frr(i,n)
		if(!vis[i])
			ans+=dfs(i);

	cout << ans << endl;

}

