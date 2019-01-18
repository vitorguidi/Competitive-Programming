
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
const ll MOD = 1e9+7;

ll memo[200200];

ll fat(ll x){
	return memo[x];
}

ll fastxp(ll base,ll exp){
	
	ll ans =1ll;
	
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


ll invmod(ll base){
	return fastxp(base,MOD-2)%MOD;
}

ll comb(ll a, ll b){

	ll ans = 1;
	ans*=fat(a);

	ll baixo1 = fat(b);
	baixo1=invmod(baixo1);
	ans*=baixo1;
	ans%=MOD;

	ll baixo2 = fat(a-b);
	baixo2 = invmod(baixo2);
	ans*=baixo2;
	ans%=MOD;

	return ans;

}

void solve(){

	ll n,m; cin >> n >> m;

	if( (n+m)%2 || (n-m)%2 || (m-n<0) || (m+n<0) ){
		cout << 0 << endl;
		return;
	}

	ll l = abs<ll>( (m-n)/2 );

	ll ans = comb(m,l);
	ll aux = fastxp(2,m);
	aux = invmod(aux);
	ans*=aux;
	ans%=MOD;

	cout << ans << endl;

}

int main(){

	fastio;

	memo[0]=1;
	frr(i,2*(ll)1e5)
		memo[i]=(memo[i-1ll]*i)%MOD;

	int t; cin >> t;
	while(t--)	solve();

}
