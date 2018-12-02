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

vi adj[112345];
int memo[112345][2];

int pd (int v,int pint,int pai){

	int &pdm = memo[v][pint];

	if (pdm != -1) return (pdm);

	int ans = 1;
	for(int i = 0;i< adj[v].size();i++){
		if (adj[v][i] == pai) continue;
		ans += pd(adj[v][i],1,v);
	}

	int ans2 = INF;

	if (pint == 1){
		ans2 = 0;
		for(int i = 0;i< adj[v].size();i++){
			if(adj[v][i] == pai) continue;
			ans2 += pd(adj[v][i],0,v);
		}
	}

	ans = min (ans,ans2);
	//dbg(v);
	//dbg(ans);

	pdm = ans;
	return (pdm);


}

int main(){

	fastio;
	int n,k;
	cin >> n >> k;

	fr(i,k){
		int a,b;
		cin >> a >> b;

		adj[a].pb(b);
		adj[b].pb(a);
	}

	ms (memo,-1);

	cout << n - pd(1,1,0)<<endl;


}