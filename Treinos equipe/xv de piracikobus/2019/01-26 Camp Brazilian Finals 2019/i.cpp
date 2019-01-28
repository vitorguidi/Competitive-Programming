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

ll acuma[100100],acumb[100100];

int main(){

	fastio;

	int n,m; cin >> n >> m;
	vector<ll> a,b,c;
	
	fr(i,n){
		ll x; cin >> x;
		a.pb(x);c.pb(x);
	}
	
	fr(i,m){
		ll x; cin >> x;
		b.pb(x);c.pb(x);
	}

	sort(all(a));
	sort(all(b));
	sort(all(c));

	ll ans = llINF;

	frr(i,n)
		acuma[i]=a[i-1]+acuma[i-1];
	frr(i,m)
		acumb[i]=b[i-1]+acumb[i-1];


	for(auto x : c){

		ll na = upper_bound(all(a),x) - a.begin();
		ll nb = upper_bound(all(b),x) - b.begin();
		nb=b.size()-nb;

		ll aux = 0;

		aux+=na*x-acuma[na];
		aux+=acumb[m]-acumb[m-nb]-nb*x;	

	
		ans=min<ll>(ans,aux);

	}

	cout << ans << endl;

}
