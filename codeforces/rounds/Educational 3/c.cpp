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

int main(){
    
    fastio;

    ll n; cin >> n;
    vector<ll> v;

    ll sum = 0;

    fr(i,n){
    	ll x; cin >> x;
    	v.pb(x);
    	sum+=x;
    }

    sort(all(v));

    ll piso = sum/n;
    ll teto = (sum+n-1ll)/n;

    if(piso==teto){

    	ll ans = 0;
    	for(auto x : v)
    		ans+=abs(x-piso);
    	cout << ans/2ll << endl;
    	return 0;

    }

    ll quantos_piso = n*teto - sum;
    ll quantos_teto = n-quantos_piso;

    ll ans = 0;

    fr(i,n){
    	if(i<quantos_piso)
    		ans+=abs(v[i]-piso);
    	else
    		ans+=abs(v[i]-teto);
    }

    cout << ans /2ll<< endl;

}

