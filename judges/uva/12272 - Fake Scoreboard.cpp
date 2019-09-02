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
const int MAXN=10100;
const int MAXM=101000;

int t,p;

int ned;
int first[MAXN],work[MAXN],dist[MAXN];
int to[MAXM],cap[MAXM],nxt[MAXM];

int solved[1010];	//quantos cada time reslveu
int amount[1010];	//quantos problemas de cada tipo foram resolvidos
int id[1010][1010];	//da o numero da aresta correspondente ao link i,j

void init(){
	ned=0;
	memset(first,-1,sizeof first);
}

void add(int u, int v, int f){

	id[u][v]=ned;
	
	to[ned]=v,cap[ned]=f;
	nxt[ned]=first[u],first[u]=ned++;
	
	to[ned]=u,cap[ned]=0;
	nxt[ned]=first[v],first[v]=ned++;

}

int dfs(int u, int s, int t, int f){
	if(u==t)	return f;
	int df,v;
	for(int& e = work[u];e!=-1;e=nxt[e]){
		v=to[e];
		if(dist[v]==1+dist[u] && cap[e]>0){
			df=dfs(v,s,t,min(cap[e],f));
			if(df>0){
				cap[e]-=df;
				cap[e^1]+=df;
				return df;
			}
		}
	}
	return 0;
}

bool bfs(int s, int t){
	int u,v;
	queue<int> q;q.push(s);
	memset(dist,-1,sizeof dist);
	dist[s]=0;
	while(!q.empty()){
		u=q.front();q.pop();
		for(int e=first[u];e!=-1;e=nxt[e]){
			v=to[e];
			if(cap[e]>0 && dist[v]==-1){
				dist[v]=1+dist[u];
				q.push(v);
			}
		}
	}
	return dist[t]>=0;
}

int dinic(int s, int t){
	int df,result;
	result=0;
	while(bfs(s,t)){
		memcpy(work,first,sizeof first);
		while(df=dfs(s,s,t,INF))
			result+=df;
	}
	return result;
}

void go(){

	init();
	ms(id,0);

	int source = 0;
	int sink = t+p+1;

	int tot = 0;
	int tot2=0;

	frr(i,t){	
		cin >> solved[i];
		tot+=solved[i];
	}

	frr(i,p){	
		cin >> amount[i];
		tot2+=amount[i];
	}

	if(tot!=tot2){
		cout << "Impossible" << endl;
		return;
	}
	frr(i,t){
		add(source,i,solved[i]);
		frr(j,p)
			add(i,t+j,1);
	}

	frr(i,p)
		add(t+i,sink,amount[i]);

	int mf = dinic(source,sink);

	if(mf<tot){
		cout << "Impossible" << endl;
		return;
	}

	
	frr(i,t){
		frr(j,p){

			dinic(source,sink);

			// frr(i,t){
			// 	frr(j,p){
			// 		cout << cap[id[i][j+t]^1] << " ";
			// 	}
			// 	gnl;
			// }
			// gnl;

			int from = id[source][i];
			int meio = id[i][j+t];
			int fim = id[t+j][sink];


			//se nao usou, deleta a aresta e continua
			if(cap[meio^1]==0){
				//olar;
				cap[meio]=cap[meio^1]=0;
				continue;
			}

			//desliga a aresta e tenta passar outra unidade de fluxo
			cap[from]++;
			cap[from^1]--;

			cap[meio]=cap[meio^1]=0;
			
			cap[fim]++;
			cap[fim^1]--;

			if(dinic(source,sink)){
				//cout << "tentei tirar e foi de boa" << endl;
				//olar;
				continue;
			}

			//se estou aqui eh pq a aresta eh indispensavel
			//religa a aresta

			cap[meio]=1;
			cap[meio^1]=0;
		

		}
	}

	dinic(source,sink);


	frr(i,t){
		frr(j,p){
			int edg = id[i][j+t]^1;
			cout << (cap[edg] ? "Y" : "N");
		}
		gnl;
	}
	

}

int main(){
 
	fastio;
	bool flag=false;
	int clk=1;
	while(true){
		cin >> t >> p;
		if(!t || !p)	break;
		if(flag)	gnl;
		//cout << "case " << clk++ << endl;
		go();
		flag=true;
		
	}
 
}