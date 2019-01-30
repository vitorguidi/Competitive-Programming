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

int main(){
    
	fastio;

	ll x,y,l,r;
	cin >> x >> y >> l >> r;

	double maxx = log2(r)/log2(x);
	double maxy = log2(r)/log2(y);

	ll mx = (ll)maxx;
	ll my = (ll)maxy;

	vector<ll> repox;
	vector<ll> repoy;

	ll base=1;

	for(ll i=0;i<=mx;i++){
		repox.pb(base);
		base*=x;
	}

	base=1;

	for(ll i=0;i<=my;i++){
		repoy.pb(base);
		base*=y;
	}

	vector<ll> v;

	for(auto x : repox){
		for(auto y : repoy){
			ll aux = x+y;
			if(l<=aux && aux<=r)
				v.pb(aux);
		}
	}


	v.pb(r+1ll);
	v.pb(l-1ll);

	sort(all(v));

	map<ll,ll> id;

	vector<ll> v2;

	for(auto x : v)
		if(!id[x]){
			id[x]=1;
			v2.pb(x);
		}

	swap(v,v2);

	int len = v.size();
	
	ll best = 0;

	fr(i,len-1){
		ll amt = v[i+1]-v[i]+1ll-2ll;
		best=max<ll>(amt,best);
	}

	cout << best << endl;

}

