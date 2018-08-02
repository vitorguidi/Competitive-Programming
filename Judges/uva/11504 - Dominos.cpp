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

int indeg[100100],pre[100100],low[100100];
int vis[100100],comp[100100];
int clk=1,val;

vector<vi> nodes,scc;
stack<int> pilha;

void dfs(int v){

	low[v]=pre[v]=clk++;
	vis[v]=1;
	pilha.push(v);

	for (auto filho : nodes[v]){
	
		if(!vis[filho])
			dfs(filho);
		
		low[v]=min(low[filho],low[v]);	
		
	}
	
	if(pre[v]==low[v]){

		int node;
		vi temp;

		do{
			node=pilha.top();pilha.pop();
			comp[node]=val;
			low[node]=INF;
			temp.pb(node);
		}	while(node!=v && !pilha.empty());

		val++;
		scc.pb(temp);

	}


}

void reset(){

	val=0;
	nodes.clear();
	ms(comp,0);
	ms(low,0);
	ms(pre,0);
	ms(indeg,0);
	ms(vis,0);
	scc.clear();

}


int main(){

	int t;
	cin >> t;

	while(t--){
		
		int n,m;
		cin >> n >> m;
		
		reset();
		nodes.resize(n+1);

		fr(i,m){
			int x,y;
			cin >> x >> y;
			nodes[x].pb(y);
		}

		int val=0;

		frr(i,n){
			if(!vis[i]){
				dfs(i);
			}
		}

		fr(i,scc.size()){

			for(auto x : scc[i]){
				for(auto y : nodes[x]){
					if(comp[y]!=comp[x])
						indeg[ comp[y] ]++;
				}

			}

		}
		int src=0;
		fr( i,scc.size() )
			if(indeg[i]==0)
				src++;

		cout << src << endl;
	}

}