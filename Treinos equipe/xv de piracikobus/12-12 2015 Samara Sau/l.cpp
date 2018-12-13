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
const int MOD = 1e9+7;

ll fastxp(ll base, ll exp){
	ll ans = 1;
	while(exp){
		if(exp%2)
			ans*=base;
		base*=base;
		exp/=2;
	}
	return ans;
}

ll fastxp2(ll base, ll exp,ll modzin){
	ll ans = 1;
	while(exp){
		if(exp%2)
			ans*=base;
		base*=base;
		exp/=2;
		base%=modzin;
		ans%=modzin;
	}
	return ans;
}


ll tot(ll x){

	int primes[100100];
	ms(primes,0);

	vector< pair<ll,ll> > pares;

	for(ll i=2;i*i<=x;i++){

		if(!primes[i]){
			primes[i]=1;
			for(ll j=i*i;j*j<=x;j++)
				primes[j]=1;
		}

		int cnt = 0;

		while(x%i==0){
			cnt++;
			x/=i;
		}

		if(cnt)
			pares.pb({i,cnt});

	}

	if(x!=1)
		pares.pb({x,1});

	ll tot = 1;

	for(auto caras : pares){
		tot*=fastxp(caras.fst,caras.snd-1ll);
		tot*=caras.fst-1ll;
	}

	return tot;

}

int main(){

	fastio;

	ll m,n; cin >> n >> m;
	
	ll ans = (m*n)/__gcd(m,n);

	if(__gcd(m,n)!=1){
		cout << ans << endl;
		return 0;
	}

	if(m==1 && n==1){
		cout << max<ll>(m,n) << endl;
		return 0;
	}

	if(m==1 || n==1){
		cout << 2 << endl;
		return 0;
	}

	ll ans1 = fastxp2(m,tot(n)-1,n);
	ans1*=m;


	ll ans2 = fastxp2(n,tot(m)-1,m);
	ans2*=n;

	ans=min<ll>(ans,ans1);
	ans=min<ll>(ans,ans2);

	cout << ans << endl;

}
