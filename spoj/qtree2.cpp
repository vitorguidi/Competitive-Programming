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

vector<vii> nodes;
int vis[10100],hgt[10100];
int memo[10100][20];
ll d[10100];

int n;

void dfs(int v){
	vis[v]=1;
	for(auto filho : nodes[v]){
		int id=filho.snd; 
		int cost = filho.fst;
		if(vis[id])	continue;
		memo[id][0]=v;	
		hgt[id]=1+hgt[v];
		d[id]=d[v]+cost;
		dfs(id);
	}
}

void build_table(){
	frr(i,15)
		frr(j,n)	memo[j][i] = memo[ memo[j][i-1] ][i-1];
}

int lca(int a, int b){

	if(hgt[a]<hgt[b])
		swap(a,b);

	for(int i=15;i>=0;i--){
		if(hgt[ memo[a][i] ] >= hgt[b])
			a=memo[a][i];
	}

	if(a==b)	return a;

	for(int i = 15;i>=0;i--){
		if(memo[a][i]!=memo[b][i]){
			a=memo[a][i];b=memo[b][i];
		}
	}

	return memo[a][0];

}

ll dist(int a, int b){
	return d[a]+d[b]-2*d[lca(a,b)];
}

int kth(int a, int b, int k){

	int c = lca(a,b);
	int step=k-1;

	// dbg(c);
	// dbg(a);dbg(b);

	int ate_pai = hgt[a]-hgt[c];

	if(step>hgt[a]-hgt[c]){
		swap(a,b);
		step = hgt[c] + step - ate_pai;
	}
	else
		step=hgt[a]-step;

	for(int i = 15; i>=0; i--)
		if(hgt[ memo[a][i] ] >= step )
			a=memo[a][i];

 	return a;
}

int main(){

	int t;
	cin >> t;

	while(t--){
	
		cin >> n;
	
		nodes.clear();nodes.resize(n+1);
		ms(vis,0);ms(hgt,0);ms(d,0);ms(memo,0);

		fr(i,n-1){
			int a,b,c; cin >> a >> b >> c;
			nodes[a].pb({c,b}); nodes[b].pb({c,a});
		}

		string op;

		memo[1][0]=1;
		dfs(1);

		build_table();

		while(cin >> op){
			
			if(op=="DONE")
				break;

			int a,b,k;	cin >> a >> b;

			if(op=="DIST")
				cout << dist(a,b) << endl;
			else{
				cin >> k; cout << kth(a,b,k) << endl;
			}

		}	

	}

}