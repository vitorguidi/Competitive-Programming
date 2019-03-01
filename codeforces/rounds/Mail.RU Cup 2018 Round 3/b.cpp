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

ll v[1010];
ll final[1010];

int main(){


    
	fastio;

	ll n,m; cin >> n >> m;

	for(ll i=1;i<=m;i++){
		ll val = i*i;
		val%=m;
		v[i]=val;
	}

	ll mult = n/m;

	frr(i,m)	final[v[i]]+=mult;

	frr(i,n%m){
		ll val = i*i;
		val%=m;
		final[val]++;
	}

	ll ans = 0;

	fr(i,m){
		ans+=final[i]*final[(m-i)%m];
	}

	cout << ans << endl;


}