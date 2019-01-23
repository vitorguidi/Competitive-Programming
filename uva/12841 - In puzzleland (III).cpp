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

vi adj[110];
map<char,int> id;
map<int,char> rid;
string memo[1<<17][17];
int n,m;
int clk;

string go(int mask, int pivot){

	if(__builtin_popcount(mask)==n){
		if(pivot==n-1)	return "";
		return "ZZZZZZZZZZZZZZZZZZ";
	}

	string& pdm = memo[mask][pivot];
	if(pdm!="-1")	return pdm;

	pdm="ZZZZZZZZZZZZZZZZZZ";

	for(auto x : adj[pivot]){

		if( (1<<x)&mask )	continue;

		int new_mask=mask|(1<<x);
		string nxt = go(new_mask,x);

		if(nxt=="ZZZZZZZZZZZZZZZZZZ")	continue;

		string lol;
		lol.pb(rid[x]);
		lol+=nxt;

		pdm=min(pdm, lol );
	
	}

	return pdm;
}

void solve(){

	id.clear();
	rid.clear();

	fr(i,110)
		adj[i].clear();

	cin >> n >> m;

	fr(i,1<<n)
		fr(j,n)
			memo[i][j]="-1";
	
	fr(i,n){

		char x; cin >> x;
		id[x]=i;
		rid[i]=x;

	}

	fr(i,m){
		char x,y;
		cin >> x >> y;
		adj[id[x]].pb(id[y]);
		adj[id[y]].pb(id[x]);
	}

	string ans = go(1,0);
	ans=rid[0]+ans;

	cout << "Case " << ++clk << ": ";

	if(ans.size()>n)
		cout << "impossible" << endl;
	else
		cout << ans << endl;
}

int main(){

	int t;
	cin >> t;
	while(t--)	solve();

}