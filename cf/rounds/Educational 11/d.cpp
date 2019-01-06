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
const ll MOD = 1e9+7;

int main(){

	fastio;

	int n; cin >> n;
	vii v;

	fr(i,n){
		
		int x,y;
		cin >> x >> y;

		v.pb({x,y});

	}

	map<pii,int> cnt;

	fr(i,n){
		for(int j=i+1;j<n;j++){
			int x = v[i].fst+v[j].fst;
			int y = v[i].snd + v[j].snd;
			cnt[{x,y}]++;
		}
	}

	ll ans = 0;

	for(auto x : cnt)
		ans+=(x.snd*(x.snd-1ll))/2ll;
	
	cout << ans << endl;
	
}