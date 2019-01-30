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

	ll n,m;
	cin >> n >> m;

	ll sum = 0;
	ll mx=0;

	vector<ll> v;
	v.pb(0);

	fr(i,n){
		ll x; cin >> x;
		v.pb(x);
		sum+=x;	
		mx=max<ll>(mx,x);
	}

	sort(all(v));
	reverse(all(v));
	
	ll cnt = 0;

	ll ans = 0;

	fr(i,n){
		if(v[i]<=v[i+1])
			v[i+1]=v[i]-1;
		ans+=v[i]-v[i+1];
	}

	
	cout << sum-ans << endl;

}

