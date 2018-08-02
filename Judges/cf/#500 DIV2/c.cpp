#include "bits/stdc++.h"
using namespace std;
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)
#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;
typedef vector< vector<ll> > matrix;
const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;
const ll mod = 1e9+7;

int main(){

	int n;
	vi seq;

	cin >> n;
	fr(i,2*n){
		int x; cin >> x;
		seq.pb(x);
	}

	sort(all(seq));

	ll ans = abs(seq[0]-seq[n-1]);
	ll ans2 =abs(seq[n]-seq[2*n-1]);
	
	ans=ans*ans2;
	ll base = abs(seq[0]-seq[2*n-1]);
	
	for(int i=1;i<n;i++){
		ll novo = abs( seq[i] - seq[i+n-1] );
		ans = min(ans,base*novo);
	}

	cout << ans << endl;

}