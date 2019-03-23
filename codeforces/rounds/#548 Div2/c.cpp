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
const ll MOD = 1e9+7;

ll fastxp(ll base, ll exp){
	ll ans = 1;
	while(exp){
		if(exp%2)	ans*=base;
		base*=base;
		base%=MOD;
		ans%=MOD;
		exp/=2;
	}
	return ans;
}

int cnt[100100];
int cmp[100100];
int clk=1;

vi nodes[100100];
int vis[100100];

void dfs(int u){
	vis[u]=1;
	cmp[u]=clk;
	cnt[clk]++;
	for(auto x : nodes[u]){
		if(vis[x])	continue;
		dfs(x);
	}
}

int main(){
    
	fastio;

	int n,k; cin >> n >> k;
	frr(i,n-1){
		int u,v,w;
		cin >> u >> v >> w;
		if(w)	continue;
		nodes[u].pb(v);
		nodes[v].pb(u);
	}

	vi coiso;

	frr(i,n){
		if(vis[i])	continue;
		dfs(i);
		coiso.pb(cnt[clk++]);
	}

	ll ans = fastxp(n,k);

	for(auto x : coiso){
		ans-=fastxp(x,k);
		if(ans<0)	ans+=MOD;
		ans%=MOD;
	}

	cout << ans << endl;

}