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

const int MAXN=2500;
const int MAXM=50000;

int dist[MAXN],first[MAXN],work[MAXN];
int to[MAXM],cap[MAXM],nxt[MAXM];
int ned;

int demand[1010],stock[1010];
int s,r,m;
vector<tuple<int,int,int>> edges;
int sum;

void init(){
	ned=0;
	memset(first,-1,sizeof first);
}

void add(int u, int v, int f){
	to[ned]=v,cap[ned]=f;
	nxt[ned]=first[u],first[u]=ned++;
	to[ned]=u,cap[ned]=0;
	nxt[ned]=first[v],first[v]=ned++;
}

int dfs(int u, int f, int s, int t){
	if(u==t)	return f;
	int df,v;
	for(int& e = work[u];e!=-1;e=nxt[e]){
		v=to[e];
		if(cap[e]>0 && dist[v]==1+dist[u]){
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

int dinic(int s, int t){
	int df,f=0;
	while(bfs(s,t)){
		memcpy(work,first,sizeof work);
		while(df=dfs(s,INF,s,t))	f+=df;
	}
	return f;
}

bool check(int val){

	init();

	frr(i,r)	add(0,i,stock[i]);
	frr(i,s)	add(r+i,r+s+1,demand[i]);

	for(auto x : edges){
		int st = get<0>(x);
		int re = get<1>(x);
		int t = get<2>(x);
		if(val>=t)	add(re,r+st,INF);
	}

	return dinic(0,s+r+1)==sum;

}

int main(){

	fastio;

	cin >> s >> r >> m;

	frr(i,s)	cin >> demand[i];
	frr(i,r)	cin >> stock[i];

	frr(i,s)	sum+=demand[i];

	frr(k,m){
		int i,j,t; cin >> i >> j >> t;
		edges.pb(make_tuple(i,j,t));
	}

	int best=-1;
	int ini=0;
	int end = 1e6;

	while(ini<=end){
		int mid = (ini+end)>>1;
		if(check(mid)){
			best=mid;
			end=mid-1;
		}
		else	ini=mid+1;
	}

	cout << best << endl;
	
}