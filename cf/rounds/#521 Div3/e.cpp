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

map<int,int> freq;

int main(){
    
	fastio;

	int n; cin >> n;

	frr(i,n){
		int x; cin >> x;
		freq[x]++;
	}

	vi repo;

	for(auto it = freq.begin();it!=freq.end();it++)
		repo.pb(it->snd);

	multiset<ll> m1;

	ll mx = -INF;

	for(auto x : repo){
		m1.insert(x);
		mx=max<ll>(x,mx);
	}

	ll best = 0;

	for(ll i=1;i<=mx;i++){

		multiset<ll> m2;
		
		for(auto y : m1)
			m2.insert(y);

		ll ans = 0;

		for(ll j=0;j<18;j++){

			ll mult = 1ll<<j;
			ll val = i*mult;

			auto it = m2.lower_bound(val);

			if(it == m2.end())
				break;

			ans+=val;
			m2.erase(it);

		}

		best=max<ll>(best,ans);

	}

	cout << best << endl;


}

