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
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;
const ll MOD=1e9+7;
const int LMAXN = 20;

ll fat[300100];

ll fastxp(ll base, ll exp){
	ll ans = 1;
	while(exp){
		if(exp%2)
			ans*=base;
		base*=base;
		ans%=MOD;
		base%=MOD;
		exp/=2;
	}
	return ans;
}

ll invmod(ll x){
	return fastxp(x,MOD-2);
}

ll calc(ll x, ll y,ll a, ll b){
	ll dx =abs<ll>(x-a);
	ll dy =abs<ll>(y-b);
	ll ans = 1;
	ans*=fat[dx+dy];
	ans*=invmod(fat[dx]);
	ans%=MOD;
	ans*=invmod(fat[dy]);
	ans%=MOD;
	return ans;

}

void solve(){

	ll n,m,x,y;
	cin >> n >> m >> x >> y;
	ll ans = calc(1,1,n,m);
	ans-=(calc(1,1,x,y)*calc(x,y,n,m))%MOD;
	ans=(ans+MOD)%MOD;
	cout << ans << endl;
}

int main(){
	fastio;
	int t; cin >> t;
	fat[0]=1;
	for(ll i=1;i<300100;i++)
		fat[i]=(fat[i-1]*i)%MOD;
	while(t--)	solve();
}