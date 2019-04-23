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
const int MOD = 1e9+7;

ll ev[300300];
ll itv[300300];

int main(){

	fastio;

	int n,m;
	cin >> n >> m;

	fr(i,n)	cin >> ev[i];
	fr(i,m)	cin >> itv[i];

	set<ll> deltas;

	for(int i=0;i<n-1;i++)
		deltas.insert(abs(ev[i]-ev[i+1]));

	ll aux = *deltas.begin();
	deltas.erase(deltas.begin());

	while(!deltas.empty()){
		aux=__gcd(aux,*(deltas.begin()));
		deltas.erase(deltas.begin());
	}

	set<ll> cands;

	ll ans = -1;

	fr(i,m){
		if(aux%itv[i]==0){
			cands.insert(itv[i]);
			ans=i+1;
		}
	}

	if(cands.empty()){
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;
	cout << ev[0] << " " << ans << endl;

}