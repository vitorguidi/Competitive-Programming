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
#define olar cout << "pira" << endl

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int primes[100100];

ll fastxp(ll base, ll exp){

	ll ans = 1;
	while(exp){
		if(exp%2)
			ans=ans*base;
		base=base*base;
		exp=exp/2;
	}

	return ans;

}

int main(){
	    
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	

	ll n;
	while(cin >> n){


		vector<pll> div;
		ms(primes,0);

		for(ll i=2;i*i<=n;i++){

			if(!primes[i]){

				for(ll j=i;j*j<=n;j+=i)
					primes[j]++;
				ll cnt=0;
				
				while(n%i==0){
					n=n/i;
					cnt++;
				}

				if(cnt!=0)
					div.pb({i,cnt});
			}

		}


		if(n!=1)
			div.pb({n,1});

		ll tot = 1ll;

		for(auto x : div){
			ll base=x.fst;
			ll exp=x.snd;
			ll aux = fastxp(base,exp-1);
			aux=aux*(base-1);
			tot=tot*aux;
		}


		cout << (tot+1)/2 << endl;

	}
	

}