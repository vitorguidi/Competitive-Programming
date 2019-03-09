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
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int check[1100100];

int main(){
    
	fastio;

	ll n,b;
	cin >> n >> b;

	vector<pll> factors;

	for(ll i=2;i*i<=b;i++){

		if(check[i])	continue;

		check[i]=1;
		
		if(b%i)	continue;

		
		int cnt=0;
		while(b%i==0){
			cnt++;
			b/=i;
		}
		factors.pb({i,cnt});

		for(ll j=i;j*j<=b;j+=i){
			//dbg(j);
			check[j]=1;
		}

	}


	if(b!=1)	factors.pb({b,1});


	ll ans = 7*1e18;

	for(auto x : factors){

		ll base = x.fst;

		ll tem = 0;

		ll coiso = n;

		//dbg(x.fst);
		while(coiso>=x.fst){
			tem+=n/base;
			//dbg(base);
			base*=x.fst;
			coiso/=x.fst;
		}

		// dbg(n);
		// dbg(x.fst);
		// dbg(tem);
		// gnl;

		ans=min<ll>(ans,tem/x.snd);

	}

	cout << ans << endl;


}