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
#define otp(x) cout << x << endl
#define gnl cout << endl
#define pira cout << "pira" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int primes[11001000];

ll fastxp(ll base, ll exp){

	ll aux = 1;
	while(exp){
		if(exp%2)
			aux = aux*base;
		base=base*base;
		exp=exp/2;
	}
	return aux;

}

int main(){
    
	ll n; cin >> n;

	vi lista;

	if(n==1){
		otp(0);
		return 0;
	}

	ll cnt = 0;

	for(ll i=2;i*i<=n;i++){

		if(!primes[i]){
			
			for(ll j = i; j*j<=n;j+=i)
				primes[j]=1;

			if(n%i==0){
				cnt++;
				while(n%i == 0) n = n/i;
			}

		}

	}
    ll ans;
    if(cnt == 0){
    	otp(0);
    	return 0;
    }
    if(n != 1) cnt++;
    ans = fastxp(2,cnt)-cnt-1;
    cout << ans << endl;

}

