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
const ll llINF = 0x3f3f3f3f3f3f3f;

const int MAXN = 100100;
const int MAXM = 500500;

int work[MAXN],first[MAXN],dist[MAXN];
int to[MAXM],nxt[MAXM];
ll cap[MAXM];
int vis[MAXN];
int ned;
int n,m;

void init(){
	ned=0;
	memset(first,-1,sizeof first);
}

void add(int u, int v, ll f){

	cap[ned]=f,to[ned]=v;
	nxt[ned]=first[u];
	first[u]=ned++;

	cap[ned]=0,to[ned]=u;
	nxt[ned]=first[v];
	first[v]=ned++;

}

ll dfs(int u, ll f, int s, int t ){

	if(u==t)	return f;
	int v;
	ll df;

	for(int &e = work[u];e!=-1;e=nxt[e]){
		v=to[e];
		if(dist[v]==dist[u]+1 && cap[e]>0){
			df=dfs(v,min<ll>(f,cap[e]),s,t);
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
	memset(dist,-1,sizeof dist);
	dist[s]=0;
	queue<int> q;q.push(s);
	while(!q.empty()){
		u=q.front();
		q.pop();
		for(int e = first[u];e!=-1;e=nxt[e]){
			v=to[e];
			if(dist[v]<0 && cap[e]>0){
				dist[v]=1+dist[u];
				q.push(v);
			}
		}
	}
	return dist[t]>=0;
}

ll dinic(int s, int t){
	ll result=0,f;
	while(bfs(s,t)){
		memcpy(work,first,sizeof work);
		while(f=dfs(s,llINF,s,t))	result+=f;
	}
	return result;
}

void go(int u){

	int v;
	vis[u]=1;

	for(int e = first[u];e!=-1;e=nxt[e]){
		v=to[e];
		if(!vis[v] && cap[e])	go(v);
	}

}

void solve(){

	init();

	frr(i,m){
		int a,b;
		ll cost;
		cin >> a >> b >> cost;
		add(a,b,cost);
		add(b,a,cost);
	}

	ll flow = dinic(1,2);

	ms(vis,0);
	go(1);
	ll cut=0;
				
	for(int u=1;u<=n;u++){
		for(int e = first[u];e!=-1;e=nxt[e]){
			int v=to[e];
			if(vis[u]==1 && vis[v]==0 && !(e&1)){
				cout << u << " " << v << endl;
				cut+=cap[e]+cap[e^1];
			}

		}
	}
	gnl;

}

int main(){

	fastio;

	while(true){
		cin >> n >> m;
		if(!n)	break;
		solve();
	}

}