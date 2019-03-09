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

ll n,s;
vector<ll> v;

bool check(ll val){

	ll bebe = 0;

	for(auto x : v){
		if(x<val)	return false;
		bebe+=abs(x-val);
	}

	return bebe>=s;

}

int main(){
    
	fastio;

	cin >> n >> s;

	ll tot = 0;

	frr(i,n){
		ll x; cin >> x;
		v.pb(x);
		tot+=x;
	}	

	if(tot<s){
		cout << -1 << endl;
		return 0;
	}

	sort(all(v));

	ll ini=0;
	ll end=1e9;

	ll best = -INF;

	while(ini<=end){
		ll mid = (ini+end)>>1;
		if(check(mid)){
			best=max(best,mid);
			ini=mid+1;
		}
		else	end=mid-1;
	}

	cout << best << endl;

}