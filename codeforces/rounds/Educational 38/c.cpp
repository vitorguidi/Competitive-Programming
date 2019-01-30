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

int main(){
    
	fastio;

	int t; cin >> t;

	while(t--){

		ll x; cin >> x;

		if(x==0){
			cout << "1 1" << endl;
			continue;
		}
		if(x==1){
			cout << "-1" << endl;
			continue;
		}

		ll nmax = 2ll*(ll)(sqrt(x));

		bool flag=false;
		ll a,b;

		for(ll i=2;i<=nmax;i++){

			ll n=i;
			ll k = n;
			ll aux = ((ll)sqrt(n*n-x));
			
			if(!aux)	continue;
			
			k/=aux;

			if(!k)		continue;

			ll val = n*n- (n/k)*(n/k); 

			if(val==x){
				flag=true;
				a=n;
				b=k;
			}

		}

		if(!flag)
			cout << -1 << endl;
		else
			cout << a << " " << b << endl;


	}

}

