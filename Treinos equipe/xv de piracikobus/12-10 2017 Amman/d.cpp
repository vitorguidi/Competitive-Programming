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

ll fat[100100];

ll fastxp(ll base, ll exp){

	ll ans = 1ll;

	while(exp){
		if(exp%2ll)
			ans*=base;
		base*=base;
		ans%=MOD;
		base%=MOD;
		exp/=2ll;
	}
	return ans%MOD;

}

ll invmod(ll x){
	return fastxp(x,MOD-2ll);
}

void solve(){
	ll a,b;
	cin >> a >> b;
	ll ans = fat[a-1];
	ans*=invmod(fat[a-b-1ll]);
	ans%=MOD;
	ans*=invmod(fat[b]);
	ans*=2ll;
	ans%=MOD;

	cout << ans << endl;
}

int main(){

	fastio;
	int T;
	cin >> T;

	fat[0]=1;

	for(ll i=1;i<=100000;i++)	fat[i]=(i*fat[i-1ll])%MOD;

	while(T--)
		solve();	
	

}
