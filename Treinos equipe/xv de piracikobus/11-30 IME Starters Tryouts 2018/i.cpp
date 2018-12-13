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
ll MOD;

ll fastxp(ll a,ll exp){

	if(exp == 0) return 1;
	if(exp == 1) return a%MOD;

	ll ans = fastxp(a,exp/2)%MOD;
	ans *= ans;
	ans = ans%MOD;

	if(exp%2 == 1)
		ans*=a;

	ans = ans%MOD;

	return (ans);	
}

int main(){

	fastio;

	ll n,k,q; cin >> n >> k >> q;
	MOD=n;

	fr(i,q){

		ll amt,x; cin >> amt >> x;
		ll passos = (x*fastxp(k,MOD-2ll))%MOD;

		int ans = 0;

		if(passos>amt)
			cout << 0 << endl;
		else
			cout << 1+max<ll>((amt-passos-1)/n,0) << endl;
	}

}