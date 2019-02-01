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
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

int ned,first[10000],work[10000];
int cap[10000],to[10000],nxt[10000],dist[10000];
int n;

int v1[100];
int v2[100];

int clk;

void init(){
	memset(first,-1,sizeof(first));
	ned=0;
}

void add(int u, int v, int f){
	
	to[ned]=v;
	cap[ned]=f;
	nxt[ned] = first[u];
	first[u]=ned++;

	to[ned] = u;
	cap[ned]=0;
	nxt[ned] = first[v];
	first[v]=ned++;

}

int dfs(int u, int f, int s, int t){

	if(u==t)	return f;
	int v;
	int df;

	for(int & e = work[u];e!=-1;e=nxt[e]){
	
		v=to[e];
	
		if(dist[v] == dist[u] + 1 && cap[e] > 0){
			df = dfs(v,min(f,cap[e]),s,t);
			if(df > 0){
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
	memset(&dist,-1,sizeof dist);
	dist[s]=0;
	queue<int>q;q.push(s);
	while(!q.empty()){
		u = q.front();q.pop();
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

int dinic(int s, int t){
	int result = 0;
	int f;
	while(bfs(s,t)){
		memcpy(work,first,sizeof work);
		while(f=dfs(s,INF,s,t))	result+=f;
	}
	return result;
}

bool check(int lobo){

	init();

	int votos_lobo=0;
	int votos_totais = n;

	frr(i,n){

		int voto=1;
		
		if(v1[i]==lobo || v2[i]==lobo){
			votos_lobo++;
			votos_totais--;
			continue;
		}

		if(i==lobo){
			votos_totais--;
			continue;
		}

		add(i,n+v1[i],1);
		add(i,n+v2[i],1);
		add(0,i,1);
	
	}

	int cara1=v1[lobo];
	int cara2=v2[lobo];

	frr(i,n){

		int cost = votos_lobo-1;
		if(i==cara1 || i==cara2)
			cost--;
		add(n+i,2*n+1,max(cost,0));

	}

	int magia = dinic(0,2*n+1);

	return magia<votos_totais;

}

void solve(){
	
	int ans = 0;

	frr(i,n){
		cin >> v1[i];
		cin >> v2[i];
	}

	
	frr(i,n)	ans+=check(i);		

	cout << ans << endl;


}

int main(){

	fastio;

	while(cin >> n)	solve();

}