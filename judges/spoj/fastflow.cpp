#include "bits/stdc++.h"
using namespace std;

#define dbg(x)	cout << #x << " = " << x << endl
#define olar cout << "olar" << endl

const int MAXN=100100;
const int MAXM=1001001;
const long long int llINF = 0x3f3f3f3f3f3f3f;

//roubado descaradamente do macacario ITA
//https://github.com/splucs/Competitive-Programming/blob/master/Macac%C3%A1rio/Graphs/dinic.cpp

int ned;
int first[MAXN],to[MAXM],nxt[MAXM],work[MAXN];
long long int dist[MAXN],cap[MAXM];

void init(){
	memset(first,-1,sizeof first);
	ned=0;
}

void add(int u,int v, int f){
	
	to[ned] = v, cap[ned] = f;
	nxt[ned] = first[u];
	first[u] = ned++;

	to[ned] = u, cap[ned] = 0;
	nxt[ned] = first[v];
	first[v] = ned++;

}

long long int dfs(int u, long long int f, int s, int t){

	if(u==t)	return f;
	long long int df;
	int v;

	for(int &e = work[u];e!=-1;e=nxt[e]){
	
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

long long int dinic(int s,int t){
	long long int result=0,f;
	while(bfs(s,t)){

		memcpy(work,first,sizeof work);
		while(f=dfs(s,llINF,s,t))	result+=f;
	}
	return result;
}


//spoj - Fastlow ::: https://www.spoj.com/problems/FASTFLOW/

int main(){

	int n,m; cin >> n >> m;
	long long int s,t,f;

	init();

	for(int i=0;i<m;i++){
		cin >> s >> t >> f;
		add(s,t,f);add(t,s,f);
	}

	cout << dinic(1,n) << endl;

}