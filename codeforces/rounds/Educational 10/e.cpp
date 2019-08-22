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
const int MOD = 1e9+7;
 
vi adj[300300];
int pre[300300],low[300300];		//vetores de preorder number e low
int vis[300300],clk,root;			//clk eh tempo globa, root eh a raiz da arvore
map<pii,int> bridge;
map<pii,int> treasure;
void dfs(int v, int caller){		//v eh o vertice que estou visitando,
 
	low[v]=pre[v]=clk++;
	vis[v]=1;	
	int nf=0;	bool any=false;	//numero de filhos do node e flag pra dizer se V eh de corte ou nao

	for(auto filho : adj[v]){
	
		if(filho==caller)
			continue;

		else if( !vis[filho] ){			//situação em que estou lidando com uma tree edge

			dfs(filho,v);	
			nf++;

			if(low[filho]>=pre[v])
				any=true;		//o filho nao conseguiu escapar da subtree, entao eh vertice de corte

			if(low[filho]>pre[v]){
				bridge[{filho,v}]=1;
				bridge[{v,filho}]=1;
			}	
	
			low[v]=min(low[v],low[filho]);	//atualizo o low do vertice atual com o de seus filhos
		}
		
		else
			low[v]=min(low[v],pre[filho]);	//lida com a situação de back edge. low do atual = min( low[atual],pre[filho])
											//nao pode ser min com low[filho] pq senao eu pego arestas de retorno de segunda ordem
	}

}

int id[300300],sz[300300];

int find(int x){
	if(id[x]==x)
		return x;
	return id[x]=find(id[x]);
}

void join(int a, int b){
	a=find(a);b=find(b);
	if(a==b)	return;
	if(sz[a]<sz[b])
		swap(a,b);
	id[b]=a;
	sz[a]+=sz[b];
}

vi adj2[300300];

int hasTreasure[300300];
int pai[300300];

void go(int v){
	vis[v]=1;
	for(auto x : adj2[v]){
		if(vis[x])	continue;
		pai[x]=v;
		go(x);
	}
}

int main(){
 
	fastio;

	int n,m;
	cin >> n >> m;

	frr(i,n){
		id[i]=i;
		sz[i]=1;
	}

	fr(i,m){
		int a,b,x;
		cin >> a >> b >> x;
		adj[a].pb(b);
		adj[b].pb(a);
		if(x){
			treasure[{a,b}]=1;
			treasure[{b,a}]=1;
		}
	}


	dfs(1,-1);


	frr(i,n){
		for(auto x : adj[i]){
			if(!bridge[{i,x}])
				join(i,x);
		}
	}

	frr(i,n){
		for(auto x : adj[i]){
			
			int u = find(i);
			int v = find(x);
			
			if(u==v){
				if(treasure[{i,x}])
					hasTreasure[u]=1;
				continue;
			}
			
			adj2[u].pb(v);
			adj2[v].pb(u);
			
			if(treasure[{i,x}]){
				treasure[{u,v}]=1;
				treasure[{v,u}]=1;
			}
		}
	}

	int s,t;
	cin >> s >> t;

	s=find(s);
	t=find(t);

	bool flag = false;
	
	if(hasTreasure[s] || hasTreasure[t])
		flag=true;

	pai[s]=-1;

	ms(vis,0);
	go(s);

	int ini = t;

	while(pai[ini]!=-1){
		if(treasure[{pai[ini],ini}] || hasTreasure[pai[ini]])
			flag=true;
		ini=pai[ini];
	}

 	cout << (flag ? "YES" : "NO") << endl;

}