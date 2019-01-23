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
typedef vector<ll> vl;
typedef vector<pll> vll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

int grid[110];
int memo[110][1<<17];
int n,m;

int clk;

int pd(int ind, int mask){

	if(ind==m){
		if(__builtin_popcount(mask)==0)	return 0;
		return INF;
	}

	int& pdm = memo[ind][mask];
	if(pdm!=-1)	return pdm;

	pdm=pd(ind+1,mask);

	int new_mask=mask^grid[ind];

	pdm=min(pdm,1+pd(ind+1,new_mask));

	return pdm;

}


void solve(){

	cin >> n >> m;
	ms(memo,-1);

	fr(i,m){
		int msk = 0;
		fr(j,n){
			int x; cin >> x;
			msk+=x<<j;
		}
		grid[i]=msk;
	}

	int ans = pd(0,(1<<n)-1);

	cout <<"Case " << ++clk << ": ";

	if(ans>=INF)
		cout << "IMPOSSIBLE" << endl;
	else
		cout << ans << endl;



}

int main(){

	fastio;

	int t; cin >> t;
	while(t--)	solve();

}