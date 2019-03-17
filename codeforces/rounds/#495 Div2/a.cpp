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

map<ll,ll> vis;

int main(){
    
	fastio;

	ll n,d;
	cin >> n >> d;	

	vector<ll> v;

	fr(i,n){
		ll x; cin >> x;
		v.pb(x);
	}

	set<ll> repo;

	for(auto x : v){
		vis[x]=1;
		repo.insert(x-d);
		repo.insert(x+d);
	}

	set<ll> ans;

	for(auto x : repo){
		if(vis[x])
			continue;
		ll low = 3*1e9;
		for(auto y : v)
			low=min(low,abs(x-y));
		if(low!=d)
			continue;
		ans.insert(x);
		
	}

	cout << ans.size() << endl;

}