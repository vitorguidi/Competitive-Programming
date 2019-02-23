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

ll cost[200200];
vector<ll> ord;

int main(){
    
	fastio;

	ll n,m,k; cin >> n >> m >> k;

	frr(i,n){
		cin >> cost[i];
		ord.pb(cost[i]);
	}

	sort(all(ord));
	reverse(all(ord));

	int tot = m;

	ll prim = ord[0];
	ll seg = ord[1];

	ll best = 0;

	ll batch = tot/(k+1);

	best+=batch*(k*prim+seg);
	tot-=(k+1)*batch;

	ll pega = min<ll>(k,tot);
	best+=pega*prim;
	tot-=pega;

	if(tot){
		tot--;
		best+=seg;
	}

	cout << best << endl;

}

