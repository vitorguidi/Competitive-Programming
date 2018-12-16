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
const ll MOD = 998244353;

vi nodes[300300];
int vis[300300];
int tag[300300];

ll black,white;

ll fastxp(ll base, ll exp){

	ll ans = 1;

	while(exp){
		if(exp%2)
			ans*=base;
		base*=base;
		base%=MOD;
		ans%=MOD;
		exp/=2;
	}

	return ans;

}

int dfs(int v, int color){

	vis[v]=1;
	tag[v]=color;

	if(color==1)	black++;
	else			white++;

	int flag = 1;

	for(auto x : nodes[v]){

		if(tag[x]!=-1 && tag[x]==tag[v])
			return 0;

		if(!vis[x])
			flag=flag&dfs(x,!color);
	}

	return flag;

}

void solve(){

	int n,m; cin >> n >> m;

	frr(i,n){
		vis[i]=0;
		tag[i]=-1;
		nodes[i].clear();
	}

	if(n==1){
		cout << 3 << endl;
		return;
	}

	fr(i,m){
		int x,y; cin >> x >> y;
		nodes[x].pb(y);
		nodes[y].pb(x);
	}

	ll ans = 1;

	frr(i,n){
		
		if(vis[i])	continue;
		black=white=0;
		
		int aux =dfs(i,1);
		
		if(!aux)
			ans=0;

		if(black+white==1){
			ans=(3ll*ans)%MOD;
			continue;
		}

		ll coiso = fastxp(2ll,black) + fastxp(2ll,white);
		coiso%=MOD;

		ans=(ans*coiso)%MOD;

	}	

	cout << ans << endl;

}

int main(){
    
	fastio;

	int t; cin >> t;
	while(t--)	solve();

}

