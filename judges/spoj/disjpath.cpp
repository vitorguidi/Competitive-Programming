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

const int MAXN = 1001000;
const int MAXM = 11001001;

int dist[MAXN],first[MAXN],work[MAXN];
int nxt[MAXM],to[MAXM],cap[MAXM];
int ned,k,n,clk;

vector<int> path;
int vis[100100];
int cnt;


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

int dfs(int u, int f, int s, int t){

	if(u==t)	return f;
	int df,v;

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

int dinic(int s,int t){
	int result=0,f;
	while(bfs(s,t)){
		memcpy(work,first,sizeof work);
		while(f=dfs(s,INF,s,t))	result+=f;
	}
	return result;
}

int to_num(string s){
	reverse(all(s));
	int ans=0;
	int base=1;
	for(auto x : s){
		ans+=(x-'0')*base;
		base*=10;
	}
	return ans;
}

vi transf(string s){
	string aux;
	vector<int> ans;
	for(auto x : s){
		if(x==' '){
			ans.pb(to_num(aux));
			aux.clear();
		}
		else	aux.pb(x);
	}
	ans.pb(to_num(aux));
	return ans;
}

int go(int u, int t){

	if(u%2==0)	path.pb(u/2);
	vis[u]=1;
	if(u==t){
		cnt++;
		return 1;
	}

	int v;

	for(int &e = first[u];e!=-1;e=nxt[e]){
		v=to[e];
		if(cap[e]!=0 || e&1 || vis[v])	continue;
		int aux =go(v,t);
		if(aux)	return 1;
	}

	if(u%2==0)	path.pop_back();
	return 0;

}

int in(int x){
	return 2*x-1;
}
int out(int x){
	return 2*x;
}

void solve(){

	init();
	ms(vis,0);
	cnt=0;

	for(int i=3;i<=n;i++)	add( in(i), out(i), 1);
	for(int i=1;i<=2;i++)	add( in(i), out(i), INF);

	string s;
	getline(cin,s);

	frr(i,n){
		getline(cin,s);
		vi aux =transf(s);
		for(auto x :aux){

			add( out(i), in(x), 1);
			add( out(x), in(i), 1);
		
		}
	}

	int mf = dinic(out(1),in(2));

	cout << "Case " << ++clk << ":" << endl;

	if(mf<k){
		cout << "Impossible"<< endl;
		return;
	}

	vector<vi> ans;

	while(cnt<k){
		path.clear();
		vis[ out(1) ]=vis[ in(2) ]=0;
		go( out(1) , in(2) );
		path.pb(2);
		ans.pb(path);
	}

	sort(all(ans));

	fr(i,k){
		vi x=ans[i];
		for(auto y : x)	cout << y << " ";
		gnl;
	}

}

int main(){

	fastio;
	int caso=0;
	while(true){
		cin >> k >> n;
		if(!k)	break;
		if(caso>0)	gnl;
		caso++;
		solve();
	}

}