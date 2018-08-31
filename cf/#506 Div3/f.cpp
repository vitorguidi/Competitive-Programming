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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

vi div1;
ll a,b;

ll solve(ll x){

	vi div2;

	for(ll i=1;i*i<=x;i++)
		if(x%i==0)
			div2.pb(i);

	ll ans = llINF;

	for(auto c : div1){

		ll d = (a+b)/c;

		auto it = upper_bound(all(div2),c);
		it--;

		ll e = *it;
		ll f = x/e;

		if(d>=f)
			ans = min(ans,2*(c+d));

	}

	return ans;

}

int main(){

	fastio;

	cin >> a >> b;

	for(ll i=1;i*i<=a+b;i++){
		if((a+b)%i==0)
			div1.pb(i);
	}

	ll ans = solve(a);
	ans = min(solve(b),ans);

	cout << ans << endl;


}