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
const ll MOD = 1e9+9;

ll fat[200200];

ll fastxp(ll base, ll exp){

	ll ans = 1;
	while(exp){
		if(exp%2)
			ans*=base;
		base*=base;
		base%=MOD;
		ans%=MOD;
		exp/=2ll;
	}
	return ans;

}

ll invmod(ll x){
	return fastxp(x,MOD-2ll);
}

ll comb(ll n, ll k){
	ll ans = fat[n];
	ans*=invmod(fat[k]);
	ans%=MOD;
	ans*=invmod(fat[n-k]);
	ans%=MOD;
	return ans;
}

int main(){

	fastio;

	ll n; cin >> n;

	fat[0]=1ll;

	for(ll i=1;i<=200000;i++)
		fat[i]=(i*fat[i-1])%MOD;

	ll ans = 0;

	for(int i=1;i<n;i++){
		ans+=comb(n,i)*( fastxp(2ll,n-i)-1ll );
		ans%=MOD;
	}

	cout << ans << endl;

}
