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

const int MAXN=10100;
const int MAXM=100100;

int work[MAXN],first[MAXN],dist[MAXN];
int to[MAXM],cap[MAXM],nxt[MAXM];
int ned,nk,np;

void init(){
	memset(first,-1,sizeof first);
	ned=0;
}

void add(int u, int v, int f){

	to[ned]=v,cap[ned]=f;
	nxt[ned]=first[u];
	first[u]=ned++;

	to[ned]=u,cap[ned]=0;
	nxt[ned]=first[v];
	first[v]=ned++;

}

int dfs(int u, int f, int s, int t){

	if(u==t)	return f;
	int df,v;

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
	int u,v;
	
	dist[s]=0;
	queue<int> q;q.push(s);
	
	while(!q.empty()){

		u=q.front();q.pop();
		
		for(int e=first[u];e!=-1;e=nxt[e]){
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
	int result=0,f;
	while(bfs(s,t)){
		memcpy(work,first,sizeof work);
		while(f=dfs(s,INF,s,t))	result+=f;
	}
	return result;
}

void solve(){

	init();

	int sum = 0;

	frr(i,np)	add(0,i,1);
	frr(i,nk){
		int val;
		cin >> val;
		sum+=val;
		add(np+i,np+nk+1,val);
	}	

	if(sum>np){
		cout << 0 << endl;
		return;
	}


	frr(i,np){
		int amt;cin >> amt;
		while(amt--){
			int cat; cin >> cat;
			add(i,np+cat,1);
		}
	}



	if(dinic(0,np+nk+1)!=sum){
		cout << 0 << endl;
		return;
	}

	cout << 1 << endl;

	vi adj[110];

	int v;
	frr(u,np){
		for(int e = first[u];e!=-1;e=nxt[e]){
			if(e&1)	continue;
			v=to[e];
			if(!cap[e]){
				adj[v-np].pb(u);
				break;
			}
		}
	}

	frr(i,nk){
		for (auto x : adj[i])	cout << x << " ";
		gnl;
	}

}

int main(){

	fastio;

	while(true){
		cin >> nk >> np;
		if(!nk)	break;
		solve();
	}

}