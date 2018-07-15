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

struct are{
	int x,y,z;
};

int n,m,vis[1010],low[1010],pre[1010],clk;
vector<vi> scc, nodes,nodes2;
map<pii,int> bridges,colinha;
stack<int> pilha;

void reset(){
	ms(vis,0);
	ms(pre,0);
	ms(low,0);
}

void strong_reset(int n){
	nodes.clear();
	nodes2.clear();
	scc.clear();
	nodes.resize(n+1);
	nodes2.resize(n+1);
	bridges.clear();
	colinha.clear();
}

void tarjan(int v){

	low[v]=pre[v]=clk++;
	vis[v]=1;
	pilha.push(v);

	for(auto filho : nodes[v]){
		if(!vis[filho])
			tarjan(filho);
		low[v]=min(low[v],low[filho]);
	}

	if(low[v]!=pre[v])
		return;

	int node;vi tmp;
	do{
		node=pilha.top();pilha.pop();
		low[node]=INF;
		tmp.pb(node);
	}	while(!pilha.empty() && node!=v);
	scc.pb(tmp);

}

void dfs(int v,int caller){

	low[v]=pre[v]=clk++;
	vis[v]=1;

	for(auto filho : nodes2[v]){

		if(filho==caller)
			continue;

		if(!vis[filho]){
			
			dfs(filho,v);

			if(low[filho]>pre[v]){
				bridges[{v,filho}]=1;
				bridges[{filho,v}]=1;
			}

			low[v]=min(low[v],low[filho]);
		}

		else
			low[v]=min(low[v],pre[filho]);
	}

}

int main(){

	int n,m;

	while(cin >> n){

		cin >> m;

		reset();
		strong_reset(n);

		fr(i,m){
			int x,y,z;
			cin >> x >> y >> z;

			if(i==0)
				continue;
			
			nodes2[x].pb(y);	//grafo bidirecional sem a aresta cagada
			nodes2[y].pb(x);

			nodes[x].pb(y);		//preciso checar sccs no grafo direcionado sem a aresta removida
			if(z==2)
				nodes[y].pb(x);

			colinha[{x,y}]=z;
			colinha[{y,x}]=z;

		}

		int comp=0;
		frr(i,n){
			if(!vis[i]){
				dfs(i,i);
				comp++;
			}
		}

		if(comp>1){					//grafo bidirecionado sem a aresta eh desconexo, nada salva
			cout << "*" << endl;
			continue;
		}

		reset();

		frr(i,n){
			if(!vis[i])
				tarjan(i);
		}

		if(scc.size()==1){			//nao precisa faze nada, grafo dirigido sem a aresta eh fortemente conexo
			cout << '-' << endl;
			continue;
		}

		int flag=0;
		for(auto x : bridges){		//procura pontes de mao unica
			// dbg(x.fst.fst);
			// dbg(x.fst.snd);
			if(colinha[x.fst]==1){
				flag=1;
			}
		}

		if(flag==1)
			cout << 2 << endl;	//se no grafo bidirecionado sem a aresa tem ponte nao bidirecional preciso fazer duas maos
		else
			cout << 1 << endl;	//senao eh de boa soh inverter sentidos

	}


}