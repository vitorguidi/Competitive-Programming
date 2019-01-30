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

vector<vi> nodes,scc;

int clk,val;
int pre[MAXN],vis[MAXN],low[MAXN];
int indeg[MAXN],outdeg[MAXN],comp[MAXN];

stack<int> pilha;

void dfs(int v){

	low[v]=pre[v]=clk++;
	pilha.push(v);
	vis[v]=1;

	for (auto filho : nodes[v] ){

		if(!vis[filho])
			dfs(filho);
		
		low[v]=min(low[filho],low[v]);
	}

	if(low[v]!=pre[v])
		return;

	vi temp;
	int node;
	do{
		node = pilha.top();pilha.pop();
		comp[node]=val;
		temp.pb(node);
		low[node]=INF;
	}	while(node!=v && !pilha.empty());

	val++;
	scc.pb(temp);

}

int main(){
	
	int t;
	cin >> t;
	
	while(t--){
		
		int n,m;
		cin >> n >> m;
	
		nodes.clear();
		nodes.resize(n+1);
		scc.clear();
		val=0;

		ms(vis,0);ms(pre,0);ms(comp,0);
		ms(low,0);ms(outdeg,0);ms(indeg,0);

		fr(i,m){
			int x,y;
			cin >> x >> y;
			nodes[x].pb(y);
		}

		frr(i,n){
			if(!vis[i]){
				dfs(i);
			}
		}

		fr(i,scc.size()){

			for(auto x : scc[i]){
				for(auto y : nodes[x]){

					if(comp[x]!=comp[y]){
						indeg[comp[y]]++;
						outdeg[comp[x]]++;
					}

				}
			}

		}

		int src=0,sink=0;
		fr(i,scc.size()){
			if(!indeg[i])
				src++;
			if(!outdeg[i])
				sink++;
		}
		if(scc.size()==1)
			cout << 0 << endl;
		else
			cout << max(src,sink) << endl;

	}
}