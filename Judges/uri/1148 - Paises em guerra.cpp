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
int low[510],pre[510],dist[510][510],vis[510],comp[510];
int clk,val;
stack<int> pilha;

void dfs(int v){

	low[v]=pre[v]=clk++;
	pilha.push(v);
	vis[v]=1;

	for(auto filho: nodes[v]){
		if(!vis[filho.snd])
			dfs(filho.snd);
		low[v]=min(low[v],low[filho.snd]);
	}

	if(low[v]!=pre[v])
		return;

	int node;
	do{
		node=pilha.top();pilha.pop();
		low[node]=INF;
		comp[node]=val;
	} while(!pilha.empty() && node!=v);
	val++;

}

void reset(int n){
	ms(low,0);
	ms(pre,0);
	ms(dist,INF);
	ms(vis,0);
	ms(comp,0);
	nodes.clear();
	nodes.resize(n+1);
	val=0;
}

int main(){

	int n,e;

	while(cin >> n){

		cin >> e;
		if(!n)
			break;

		reset(n);
		fr(i,e){
			int x,y,h;
			cin >> x >> y >> h;
			nodes[x].pb({h,y});
		}

		frr(i,n)
			if(!vis[i])
				dfs(i);

		fr(i,n+1)
			dist[i][i]=0;
	
		frr(i,n){
			fr(j,nodes[i].size()){
				if(comp[i]==comp[ nodes[i][j].snd ])
					continue;
				dist[ comp[i] ][ comp[nodes[i][j].snd] ]=min( dist[ comp[i] ][ comp[nodes[i][j].snd] ],nodes[i][j].fst );
			}
		}

		
		
		fr(k,val){
			fr(i,val){
				fr(j,val){
					dist[i][j] = min( dist[i][j], dist[i][k] + dist[k][j] );
				}
			}
		}


		int k;
		cin >> k;

		fr(i,k){
			int a,b;
			cin >> a >> b;
			int d = dist[ comp[a] ][ comp[b] ];
			if(d==INF)
				cout << "Nao e possivel entregar a carta" << endl;
			else
				cout << d << endl;

		}
		gnl;

	}

}