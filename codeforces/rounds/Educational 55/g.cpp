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
const int MAXN=100100;
const int MAXM=2100100;

ll ned;
ll first[MAXN],dist[MAXN],work[MAXN];
ll nxt[MAXM],to[MAXM],cap[MAXM];

void init(){
	memset(first,-1,sizeof first);
	ned=0;
}

void add(int u,int v, ll f){
	
	to[ned] = v, cap[ned] = f;
	nxt[ned] = first[u];
	first[u] = ned++;

	to[ned] = u, cap[ned] = 0;
	nxt[ned] = first[v];
	first[v] = ned++;

}

ll dfs(int u, ll f, int s, int t){

	if(u==t)	return f;
	ll df,v;

	for(ll &e = work[u];e!=-1;e=nxt[e]){
	
		v=to[e];
		if(dist[v]==dist[u]+1 && cap[e]>0){

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
	
	int u,v;
	memset(&dist,-1,sizeof(dist));
	
	dist[s]=0;
	queue<int> q;q.push(s);
	
	while(!q.empty()){

		u=q.front();q.pop();
	
		for(int e = first[u];e!=-1;e=nxt[e]){
			v=to[e];
			if(dist[v]<0 && cap[e]>0){
				dist[v]=dist[u]+1;
				q.push(v);
			}
		}

	}

	return dist[t]>=0;

}

ll dinic(int s,int t){
	ll result=0,f;
	while(bfs(s,t)){
		memcpy(work,first,sizeof work);
		while(true){
			f=dfs(s,1e18,s,t);
			result+=f;
			if(!f)	break;
		}
	}
	return result;
}

int vtx[3030];
int are[3030];

int main(){
 
	fastio;
 
	int n,m;
	cin >> n >> m;
	init();

	frr(i,n){
		cin >> vtx[i];
		add(m+i,m+n+1,vtx[i]);
	}

	frr(i,m){
		int u,v;
		cin >> u >> v;
		cin >> are[i];
		add(0,i,are[i]);
		add(i,m+u,INF);
		add(i,m+v,INF);
	}

	ll ans = 0;
	frr(i,m)
		ans+=are[i];

	cout << ans - dinic(0,n+m+1)<< endl;

}