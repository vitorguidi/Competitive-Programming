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

ll f[] = {0,0,1,2,9};

ll calc(ll n, ll k){

	if(k==1)	return  n*f[k];
	if(k==2)	return  f[k]*((n)*(n-1ll))/2ll;
	if(k==3)	return  f[k]*( n*(n-1ll)*(n-2ll) )/6ll;
	if(k==4)	return  f[k]*( n*(n-1ll)*(n-2ll)*(n-3ll) )/24ll;
}

int main(){
    
	fastio;

	ll n,k; cin >> n >> k;

	ll ans = 1ll;

	for(ll i=1;i<=k;i++)
		ans+=calc(n,i);

	cout << ans << endl;

}

