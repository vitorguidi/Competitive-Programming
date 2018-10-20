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

ll calc(ll n){

	if(!n)	return 1;
	
	ll ans = 0;
	while(n){
		ans++;
		n/=10;
	}

	return ans;
}

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

void solve(){

	ll n,m; cin >> m >> n;
	ll x = calc(n);

	ll ans=n;

	ans*=(fastxp(10,m*x)-1);
	ans%=MOD;

	ans*=fastxp( fastxp(10,x)-1,MOD-2 );
	ans%=MOD;
	
	cout << ans << endl;

}

int main(){

	fastio;
	int t; cin >> t;
	while(t--)	solve();


}