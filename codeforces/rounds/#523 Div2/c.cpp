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
const ll MOD = 1e9+7;
ll memo[100100];

int main(){
    
	fastio;

	int n; cin >> n;

	memo[0]=1;

	frr(i,n){
		
		ll x; cin >> x;		//isso contribui com memo[j] onde j sao todos os divisores de x
		
		vector<ll> aux;

		for(ll j=1;j*j<=x;j++){

			if(x%j)	continue;

			aux.pb(j);
			if(x/j !=j)	aux.pb(x/j);
		}


		sort(all(aux));
		reverse(all(aux));

		for(auto x : aux){
			if(x>n)	continue;
			memo[x]+=memo[x-1];
			memo[x]%=MOD;
		}

	}

	ll sum = 0;

	frr(i,n)	sum=(sum+memo[i])%MOD;

	cout << sum << endl;



}

