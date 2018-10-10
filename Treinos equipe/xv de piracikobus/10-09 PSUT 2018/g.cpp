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

	ll v[1000000];
	frr(i,n){
		ll x; cin >> x;
		v[i] = x;
	}

	sort(v+1,v+n+1);
	reverse(v+1,v+n+1);

	ll ans = 0;
	//frr(i,n)
	//	cout << v[i] << endl;

	int k = n;

	while(k!=1){
		int p,q;
		p = 1;
		q = k;
		while(p < q){
			ans += v[p] - v[q];
	//		dbg(ans);
			p++;
			q--;
		}
		

		k = k/2;
	}


	cout << ans << endl;

}