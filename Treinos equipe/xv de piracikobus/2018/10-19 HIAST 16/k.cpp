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
#define olar cout << "pira" << endl
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll; 

const int INF = 0x3f3f3f3f;
const int MAXN=300;
const int MAXM=20000;

int quer[110][110],lugar[110][110];
int arma[110][110];

int ned;
int to[MAXM],cap[MAXM],nxt[MAXM];
int dist[MAXN],first[MAXN],work[MAXN];

void init(){
	memset(first,-1,sizeof first);
	ned=0;
}

void add(int u, int v, int f){
	to[ned]=v,cap[ned]=f;
	nxt[ned]=first[u],first[u]=ned++;
	to[ned]=u,cap[ned]=0;
	nxt[ned]=first[v],first[v]=ned++;
}

int dfs(int u, int f,int s, int t){
	if(u==t)	return f;
	int v,df;
	for(int& e=work[u];e!=-1;e=nxt[e]){
		v=to[e];
		if(dist[v]==1+dist[u] && cap[e]>0){
			df=dfs(v,min(f,cap[e]),s,t);
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
	memset(dist,-1,sizeof dist);
	dist[s]=0;
	queue<int> q;q.push(s);
	int u,v;
	while(!q.empty()){
		u=q.front();q.pop();
		for(int e =first[u];e!=-1;e=nxt[e]){
			v=to[e];
			if(dist[v]<0 && cap[e]>0){
				dist[v]=1+dist[u];
				q.push(v);
			}
		}
	}
	return dist[t]>=0;
}

int dinic(int s, int t){
	int f=0,df;
	while(bfs(s,t)){
		memcpy(work,first,sizeof work);
		while(df=dfs(s,INF,s,t))	f+=df;
	}
	return f;
}


void go(){

	int n,m,w;
	cin >> n >> m >> w;

	ms(lugar,0);
	ms(quer,0);
	ms(arma,0);
	init();

	frr(i,n){
		int k; cin >> k;
		frr(j,k){
			int x; cin >> x;
			lugar[i][x]=1;
		}
	}

	frr(i,n){
		int k; cin >> k;
		frr(j,k){
			int x; cin >> x;
			quer[i][x]=1;
		}
	}

	frr(i,m){
		int k; cin >> k;
		frr(j,k){
			int x; cin >> x;
			arma[i][x]=1;
		}
	}

	frr(i,n){
		frr(j,m){
			frr(k,w){
				if(lugar[i][j] && quer[i][k] && arma[j][k])	add(i,n+j,1);
			}
		}
	}

	frr(i,n)	add(0,i,1);
	frr(i,m)	add(i+n,n+m+1,1);

	cout << dinic(0,n+m+1) << endl;


}

int main(){

	fastio;

	int t; cin >> t;
	while(t--)	go();
	
}