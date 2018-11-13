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
int v[222345];
int n;
int p,q;

void solve(){
	ll mx = 0;
	fr(i,n)
		if(v[i] > mx)
			mx = v[i];

	cout << (mx + p - 1)/p << endl;

}

bool boo (ll s){
	ll ct = 0;
	fr(i,n){
		if(v[i] <= s*q) continue;
		ct+= (v[i] - s*q + p - q -1)/(p-q);
	}

	if(ct<= s) return (true);
	return (false);
}

int main(){

	fastio;

	cin >> n >> p >>q;
	

	fr(i,n)
		cin >> v[i];

	if(p==q){
		solve();
		return(0);
	}

	ll ini = 1;
	ll fim = 1e9;
	ll best = 1e9;

	while(ini <= fim){
		ll mid = (ini + fim)/2;

		if(boo(mid)){
			best = mid;
			fim = mid-1;
		}
		else
			ini = mid + 1;
	}

	cout << best << endl;


}