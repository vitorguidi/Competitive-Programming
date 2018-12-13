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

ll n;
int primes[1100100];	
vector<ll> divisors;

ll fastxp(ll base, ll exp){

	ll ans =1;
	
	while(exp){
		if(exp%2)
			ans*=base;
		base*=base;
		exp/=2;
	}
	
	return ans;

}

void solve(){

	ll aux = n;
	vector<pll> caras;

	for(auto x : divisors){

		int cnt = 0;

		while(aux%x==0){
			cnt++;
			aux/=x;
		}

		if(cnt)
			caras.pb({x,cnt});

	}

	if(aux!=1)
		caras.pb({aux,1});

	ll tot = 1;

	for(auto x : caras)
		tot*=(x.fst-1ll)*fastxp(x.fst,x.snd-1);

	cout << (tot+1ll)/2ll << endl;

}

int main(){

	fastio;

	for(ll i=2;i*i<= (1ll<<31);i++){
		if(!primes[i]){
			primes[i]=1;
			divisors.pb(i);
			for(ll j=i;j*j<=(1ll<<31);j+=i)
				primes[j]=1;
		}
	}

	while(cin>>n)	solve();

}
