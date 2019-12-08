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

ll n,m;
vi adj[2200];
ll memo[2200];
int vis[2200];

ll dp(int ind){
	if(ind > m){
		vis[ind] = 1;
		return 1;
	}
	ll& pdm = memo[ind];
	if(pdm != -1ll) return pdm;
	pdm = 0ll;

	fr(i,adj[ind].size()){
		pdm += dp(adj[ind][i]);
		pdm = pdm%MOD;
	}

	return pdm;
}

int main(){

	fastio;
	cin >> n >> m;

	frr(i,m){
		int a;
		cin >> a;
		fr(j,a){
			int k;
			cin >> k;
			adj[i].pb(k);
		}
	}

	ms(memo,-1ll);

	cout << dp(1) << ' ';

	ll sum = 0ll;
	frr(i,n){
		sum += vis[i];
	}

	cout << sum << endl;



}
