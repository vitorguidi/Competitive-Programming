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
#define olar cout << "pira" << endl
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

	ll n,a,b; cin >> n >> a >> b;

	vector<ll> aux1,aux2;

	fr(i,n/2){
		ll x; cin >> x;
		aux1.pb(x);
	}

	for(int i=n/2;i<n;i++){
		ll x; cin >> x;
		aux2.pb(x);
	}

	vector<ll> v1,v2;

	int len = aux1.size();

	for(ll i=0;i<(1<<len);i++){
		ll sum = 0;
		for(int j = 0;j<len;j++)
			if((1ll<<j)&i)
				sum+=aux1[j];
		v1.pb(sum);
	}

	len = aux2.size();

	for(ll i=0;i<(1<<len);i++){
		ll sum = 0;
		for(int j = 0;j<len;j++)
			if((1ll<<j)&i)
				sum+=aux2[j];
		v2.pb(sum);
	}	

	sort(all(v2));

	ll ans = 0;

	for(auto x : v1){

		ll left = a-x;
		ll right = b-x;

		auto r = upper_bound(all(v2),right);
		auto l = lower_bound(all(v2),left);

		ans+=r-l;

	}

	cout << ans << endl;

}