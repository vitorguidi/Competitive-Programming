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

ll n,k;

ll mex(ll a, ll b){

	if(a!=0 && b!=0)	return 0;
	if(a!=1 && b!=1)	return 1;
	return 2;

}

ll grundy(ll x, ll k){

	if(k%2==0)
		return (x<=2 ? x : !(x%2));
	
	if(x<=3)			return x%2;
	if(x==4 || x==6)	return 2;
	if(x==5)			return 0;
	
	if(x%2)	return 0;

	return mex( grundy(x-1,k), grundy(x/2,k) );


}

int main(){

	fastio;

	cin >> n >> k;

	ll ans = 0;

	frr(i,n){
		ll x; cin >> x;
		ans^=grundy(x,k);
	}

	if(ans)	puts("Kevin");
	else	puts("Nicky");

}
