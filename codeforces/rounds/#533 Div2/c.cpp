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

ll memo[200200][5];

ll n,l,r;
ll m0,m1,m2;

ll get0(ll x){
	return x/3ll;
}
ll get1(ll x){
	return (x+2ll)/3ll;
}
ll get2(ll x){
	return (x+1ll)/3ll;
}

ll pd(int ind,int mod){

	if(ind==n){
		if(mod==0)	return 1ll;
		return 0;
	}

	ll &pdm = memo[ind][mod];
	if(pdm!=-1)	return pdm;

	pdm = 0;

	pdm+=m0*pd(ind+1,mod);
	pdm%=MOD;
	pdm+=m1*pd(ind+1,(mod+1)%3);
	pdm%=MOD;
	pdm+=m2*pd(ind+1,(mod+2)%3);
	pdm%=MOD;
	
	return pdm;
}

int main(){
    
	fastio;

	cin >> n >> l >> r;

	m0 = get0(r)-get0(l-1);
	m1 = get1(r)-get1(l-1);
	m2 = get2(r)-get2(l-1);

	ms(memo,-1);

	cout << pd(0,0) << endl;

}