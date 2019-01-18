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
const ll MOD = 1e9+7;

ll memo[100100];

ll fastxp(ll base, ll exp){

	ll ans = 1ll;

	while(exp){
	
		if(exp%2ll)
			ans*=base;
	
		base*=base;
		base%=MOD;
	
		ans%=MOD;
		exp/=2ll;
	}

	return ans%MOD;

}

ll invmod(ll x){
	return fastxp(x,MOD-2ll);
}

ll fat(ll x){
	return memo[x];
}

ll comb(ll n, ll k){

	ll ans = fat(n);

	ll x = fat(k);
	x=invmod(x);
	ans*=x;
	ans%=MOD;

	x=fat(n-k);
	x=invmod(x);
	ans*=x;
	ans%=MOD;

	return ans%MOD;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);    

	ll m,n,k; cin >> m >> n >> k;

	string s; cin >> s;

	memo[0]=1;
	frr(i,100100)
		memo[i]=(memo[i-1]*i)%MOD;

	string aux;
	for(int i=2;i<s.size();i++)
		aux.pb(s[i]);

	ll base = 100ll;
	ll p = 0ll;
	
	fr(i,3ll){
		p+=(aux[i]-'0')*base;
		base/=10;
	}

	if(s=="1.000")	p=1000ll;

	ll ans;

	ans=comb(n-1ll,k-1ll);
	ans%=MOD;
	
	ans*=fastxp(1000ll-p,n-k);
	ans%=MOD;

	ans*=fastxp(p,k);
	ans%=MOD;

	ll lol = fastxp(1000ll,n);
	lol=invmod(lol);

	ans*=lol;
	ans%=MOD;

	cout << ans << endl;

}