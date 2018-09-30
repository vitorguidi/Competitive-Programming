
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
typedef vector<pll> vll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

vi primes;
int check[2010];


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

void solve(){
	
	ll m; cin >> m;
	vll div;

	ll aux = m;

	for(auto x : primes){
		if(m%x==0){
			ll amt=0;
			while(m%x==0){
				amt++;
				m/=x;
			}
			div.pb({x,amt});
		}
	}

	if(m!=1)
		div.pb({m,1});

	ll ans = 1;
	for(auto x : div)
		ans*=(fastxp(x.fst,x.snd-1))*(x.fst-1);
	
	cout << ans*(aux-1) << endl;

}

int main(){

	fastio;

	int tot = (int)1e6+10;

	for(int i=2;i*i<=tot;i++){
		if(!check[i]){
			primes.pb(i);
			for(int j=i;j*j<=tot;j+=i)
				check[j]=1;
		}
	}

	int t; cin >> t;
	while(t--)	solve();

}