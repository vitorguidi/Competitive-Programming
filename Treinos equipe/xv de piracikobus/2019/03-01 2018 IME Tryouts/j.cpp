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
ll n;
ll bit[1001000];

ll sum(ll k){

	ll ans = 0;

	for(ll i = k;i > 0;i-= (i&-i)){
		ans += bit[i];
	}

	return ans;
}

void upd(ll p){
	for(int i = p;i <= 1000100; i+= (i&-i)){
		bit[i]++;
	}
}

int main(){

	fastio;

	cin >> n;
	vector<ll> ans;
	fr(i,n){
		int a;
		cin >> a;
		a++;
		ll aux = sum(a-1);
		aux = i - aux;
		ans.pb(n - aux);
		upd(a);
	}

	fr(i,n) cout << ans[i] << ' ';
	gnl;


}
