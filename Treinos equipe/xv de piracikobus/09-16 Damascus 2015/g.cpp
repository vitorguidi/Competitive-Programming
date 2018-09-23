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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const ll mod = 1e9+7;

ll fat(ll x){
	if(x==0)
		return 1ll;
	return (x*fat(x-1))%mod;

}

ll fastxp(ll base, ll exp){

	ll ans =1 ;
	while(exp){
		if(exp%2)
			ans*=base;
		ans%=mod;
		base*=base;
		base%=mod;
		exp/=2;
	}

	return ans;

}

ll invmod(ll x){
	return fastxp(x,mod-2);
}

int main(){

	int t; cin >> t;
	while(t--){
		int x,y;
		cin >> x >> y;

		ll ans = fat(x+y);
		ans%=mod;
		ans = ans*invmod(fat(x));
		ans%=mod;
		ans = ans*invmod(fat(y));
		ans%=mod;

		cout << ans << endl;
	}


}