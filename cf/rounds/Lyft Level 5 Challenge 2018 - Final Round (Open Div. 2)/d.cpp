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

int vis[1010];
int hgt[1010];
vi good1;
vi good2;
vi nodes[1010];

void reset(){

	fr(i,1010)
		nodes[i].clear();
	
	ms(vis,0);
	ms(hgt,0);

	good1.clear();
	good2.clear();

}

void dfs(int v){
	
	vis[v]=1;
	
	for(auto x : nodes[v]){
		
		if(vis[x])	continue;
	
		hgt[x]=1+hgt[v];
		dfs(x);
	
	}
}

void solve(){

	int n; cin >> n;

	reset();

	fr(i,n-1){
		int a,b; cin >> a >> b;
		nodes[a].pb(b);
		nodes[b].pb(a);
	}

	int k1; cin >> k1;
	fr(i,k1){
		int x; cin >> x;
		good1.pb(x);
	}

	int k2; cin >> k2;
	fr(i,k2){
		int x; cin >> x;
		good2.pb(x);
	}


	int other_root=good2[0];
	int my_root;

	cout << "B " << other_root << endl;
	cin >> my_root;
	
	fflush(stdout);

	dfs(my_root);

	int top_me;
	int mn_me=INF;

	for(auto x : good1){
	
		if(hgt[x]>=mn_me)	continue;

		top_me=x;
		mn_me=hgt[x];	
	
	}

	int top_me_toliu;
	cout << "A " << top_me << endl;
	cin >> top_me_toliu;

	fflush(stdout);

	bool flag=false;
	for(auto x : good2){
		if(x==top_me_toliu)
			flag=true;
	}

	if(!flag)
		cout << "C -1" << endl;
	else
		cout << "C " << top_me << endl;

	fflush(stdout);


}

int main(){
    
	fastio;

	int t; cin >> t;
	while(t--)	solve();

}

