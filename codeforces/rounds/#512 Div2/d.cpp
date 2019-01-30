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
#define pira cout << "pira" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int main(){
    
	fastio;

	ll n,m,k; cin >> n >> m >> k;

	if(  (2ll*n*m)%k!=0){
		cout << "NO" << endl;
		return 0;
	}

	ll x = n;
	ll y = m;

	ll aux = __gcd<ll>(n,k);
	x/=aux;
	k/=aux;

	aux=__gcd<ll>(m,k);
	k/=aux;
	y/=aux;

	if(k>2){
		cout << "NO" << endl;
		return 0;
	}

	if(k==1){
		if(x*2<=n)
			x*=2;
		else
			y*=2;
	}
	cout << "YES" << endl;
	cout << "0 0" << endl;
	cout << x << " 0" << endl;
	cout << "0 " << y << endl;

}

