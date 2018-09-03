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

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;

vi nodes[200200];
int vis[200200],pre[200200],post[200200];
int clk;
vii check;

void dfs(int v){

	pre[v]=clk++;
	vis[v]=1;

	for(auto filho : nodes[v]){
		if(vis[filho])
			continue;
		dfs(filho);
	}

	post[v]=clk++;

	check.pb(mp(pre[v],v));

}

int main(){

	int n,q;

	cin >> n >> q;

	for(int i=2;i<=n;i++){
		int x;
		cin >> x;
		nodes[x].pb(i);
	}

	frr(i,n)
		sort(all(nodes[i]));

	dfs(1);

	sort(all(check));
	
	fr(i,q){

		int src,tgt;
		cin >> src >> tgt;

		auto left = lower_bound(all(check),mp(pre[src],0));
		int ini = left - check.begin();

		auto right = lower_bound(all(check),mp(post[src],0));
		right--;
		int end = right - check.begin();


		if(tgt>end-ini+1)
			cout << -1 << endl;
		else
			cout << check[ini+tgt-1].snd << endl;
		//cout << local[tgt] - local[src] + 1 << endl;

	}

}