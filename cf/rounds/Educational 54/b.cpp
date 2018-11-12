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

ll primes[100100];

ll n;

vector<ll> guys;


ll solve(){

	if(n%2==0){
		ll amt = n/2ll;
		n-=amt*2ll;
		return amt;
	}

	ll x= -1;
	for(auto y : guys)
		if(n%y==0){
			x=y;
			break;
		}

	if(x==-1){
		n=0;
		return 1;
	}

	n-=x;
	return 1;
}

int main(){
    
	fastio;

	cin >> n;


	for(int i=2;i<=100000;i++){
		if(!primes[i]){
			primes[i]=i;
			guys.pb(i);
			for(int j=i;j<=100000;j+=i)
				if(!primes[j])
					primes[j]=i;
		}
	}

	ll cnt = 0;
	
	while(n)
		cnt+=solve();

	cout << cnt << endl;

}

