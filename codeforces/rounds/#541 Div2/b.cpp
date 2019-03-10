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

int main(){
    
	fastio;

	int n; cin >> n;

	set<pll> s;

	s.insert({0,0});
	
	frr(i,n){
		ll x,y;
		cin >> x >> y;
		s.insert({x,y});
	}

	if(s.size()==1){
		cout << 1 << endl;
		return 0;
	}

	vector<pll> v;

	for(auto x : s)	v.pb(x);

	int len = s.size();
	
	ll ans = 1;

	for(int i=1;i<len;i++){
		ll delta = min(v[i].fst,v[i].snd)-max(v[i-1].fst,v[i-1].snd) + 1;
		if(v[i-1].fst==v[i-1].snd)	delta--;
		delta=max(delta,0ll);
		ans+=delta;

	}

	cout << ans << endl;

}