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

ll memo[100][100][2];
ll v[11234];
int n;

ll pd(int l,int rod,int jog){
	int r = n - 1 + l - 2*rod;
	if(l > r) return 0;

	ll& pdm = memo[l][rod][jog];

	if(pdm != -llINF) return (pdm);

	if (jog == 1)
		pdm = max(v[l] + pd(l + 1,rod,0),v[r] + pd(l,rod,0));
	else
		pdm = min(pd(l+1,rod+1,1),pd(l,rod+1,1));

	return (pdm);
}

int main(){

	fastio;

	vector<ll> res;

	while(cin >> n){
		
		fr(i,n)
			cin >> v[i];

		fr(i,10002){
			fr(j,5002){
				fr(k,2){
					memo[i][j][k]= -llINF;
				}
			}
		}

		res.pb(pd(0,0,1));
	}

	fr(i,res.size()){
		cout << res[i];
		if(i != res.size() - 1)
			gnl;
	}

}
