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
#define olar cout << "LAW" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

vector<vi> nodes,nodes2;
map<pii,int> bridges;

int vis[100100];
int pre[100100],low[100100],comp[100100];
int dist[100100];
int amt=0;int pontes=0;int clk=0;
int n,m;

void dfs(int v, int caller){

	vis[v]=1;
	low[v]=pre[v]=clk++;

	fr(i,nodes[v].size()){

		int filho = nodes[v][i];

		if(filho==caller)
			continue;

		else if(!vis[filho]){
		
			dfs(filho,v);
		
			if(low[filho]>pre[v]){
				bridges[mp(v,filho)]=1;
				bridges[mp(filho,v)]=1;
				pontes++;
			}

			low[v]=min(low[v],low[filho]);

		}
		else
			low[v]=min(low[v],pre[filho]);

	}	

}

void dfs_connect(int v, int val){

	vis[v]=1;
	comp[v]=val;

	fr(i,nodes[v].size()){
		
		int filho = nodes[v][i];
		
		if(vis[filho])
			continue;
		
		if(bridges[mp(v,filho)])
			continue;
		
		dfs_connect(filho,val);
	
	}

}

void dfs2(int v){

	vis[v]=1;

	fr(i,nodes2[v].size()){

		int filho = nodes2[v][i];
		
		if(!vis[filho]){
			dist[filho]=1+dist[v];
			
			dfs2(filho);
		}

	}

}

void reseta(){

		
		nodes.resize(n+1);
		nodes2.resize(n+1);
		nodes.clear();
		nodes2.clear();
		ms(vis,0);
		ms(low,0);
		ms(pre,0);
		ms(dist,0);
		ms(comp,0);
		clk=0;		
		pontes=0;
		bridges.clear();

}

int main(){

	int t;
	cin >> t;
	
	while(t--){

		cin >> n >> m;
		reseta();

		fr(i,m){
			int x,y;
			cin >> x >> y;
			nodes[x].pb(y);
			nodes[y].pb(x);
		}


		dfs(1,1);

		ms(vis,0);
	
		int cnt=1;
		frr(i,n){
			if(!vis[i])
				dfs_connect(i,cnt++);
		}



		cnt--;

		frr(i,n){
			fr(j,nodes[i].size()){
				int x = nodes[i][j];
				nodes2[comp[i]].pb(comp[x]);
			}
		}


		ms(vis,0);

		dfs2(1);

		int d=0;
		int id=-1;

		// frr(i,n)
		// 	dbg(dist[i]);

		frr(i,n){
			if(dist[i]>=d){
				d=dist[i];
				id=i;
			}
		}

		// dbg(id);
		// dbg(d);
		// dbg(pontes);	


		ms(dist,0);
		ms(vis,0);

		dfs2(id);

		frr(i,n)
			d=max(d,dist[i]);
		
		cout << pontes-d << endl;

	}

}