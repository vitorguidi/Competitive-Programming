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

ll v[100];

int main(){
    
    fastio;

    ll n,m; cin >> n >> m;

    fr(i,n){
    	ll x; cin >> x;
    	v[x]++;
    }

    ll pares = 0;

    frr(i,m){
    	frr(j,m){
    		if(i==j || !v[i] || !v[j])	continue;
    		pares+=v[i]*v[j];
    	}
    }

    cout << pares/2ll << endl;
    
}

