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
#define endl "\n"
 
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;

#define MAXN 40000
#define MAXM 100000

int ned, first[MAXN], work[MAXN];
int cap[MAXM], to[MAXM], nxt[MAXM], dist[MAXN];

int n;

void init() {
   memset(first, -1, sizeof first);
   ned = 0;
}

void add(int u, int v, int f) {
    to[ned] = v, cap[ned] = f;
    nxt[ned] = first[u];
    first[u] = ned++;
    
    to[ned] = u, cap[ned] = 0;
    nxt[ned] = first[v];
    first[v] = ned++;
}

int dfs(int u, int f, int s, int t) {
	if (u == t) return f;
	int v, df;
	for(int & e = work[u]; e!=-1; e = nxt[e]) {
        v = to[e];
		if (dist[v] == dist[u] + 1 && cap[e] > 0) {
			df = dfs(v, min(f, cap[e]), s, t);
			if (df > 0) {
				cap[e] -= df;
				cap[e^1] += df;
				return df;
			}
		}
	}
	return 0;
}

bool bfs(int s, int t) {
	int u, v;
	memset(&dist, -1, sizeof dist);
	dist[s] = 0;
	queue<int> q; q.push(s);
	while (!q.empty()) {
		u = q.front(); q.pop();
		for(int e = first[u]; e!=-1; e = nxt[e]) {
			v = to[e];
			if (dist[v] < 0 && cap[e] > 0) {
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
	return dist[t] >= 0;
}

int dinic(int s, int t) {
	int result = 0, f;
	while (bfs(s, t)) {
		memcpy(work, first, sizeof work);
		while (f = dfs(s, INF, s, t)) result += f;
	}
	return result;
}

int grid[110][110];
int idv[110][110];
int idh[110][110];
int clk=1;

bool valid(int i, int j){
	return i>0 && i<=n && j>0 && j<=n;
}

void go(){

	string s;

	init();
	clk=1;

	fr(i,n){
		cin >> s;
		fr(j,n){
			grid[i+1][j+1] = (s[j]=='.' ? 1 : 0);
		}
	}

	ms(idv,-1);
	ms(idh,-1);

	//varre vertical fixando coluna
	for(int i=1;i<=n;i++){
		int ini=1;
		while(ini<=n){
			while(ini<=n && grid[ini][i]==0)
				ini++;
			if(ini>n)	break;
			while(ini<=n && grid[ini][i]==1){
				idv[ini][i]=clk;
				ini++;
			}
			clk++;
		}
	}

	//varre horizontal fixando linha
	for(int i=1;i<=n;i++){
		int ini=1;
		while(ini<=n){
			while(ini<=n && grid[i][ini]==0)
				ini++;
			if(ini>n)	break;
			bool flag = false;
			while(ini<=n && grid[i][ini]==1){
				idh[i][ini]=clk;
				ini++;
			}
			clk++;
		}
	}

	// frr(i,n){
	// 	frr(j,n){
	// 		cout << idv[i][j] << " ";
	// 	}
	// 	gnl;
	// }
	// gnl;

	// frr(i,n){
	// 	frr(j,n){
	// 		cout << idh[i][j] << " ";
	// 	}
	// 	gnl;
	// }
	// gnl;

	int ans = 0;

	set<pii> are;

	frr(i,n){
		frr(j,n){

			if(grid[i][j]==0)
				continue;

			are.insert({idv[i][j],idh[i][j]});

			//olha esquerda
			if(valid(i,j-1) && grid[i][j-1]==1)
				are.insert({idv[i][j],idh[i][j-1]});

			//olha direita
			if(valid(i,j+1) && grid[i][j+1]==1)
				are.insert({idv[i][j],idh[i][j+1]});

		}
	}

	set<int> vert,hor;

	frr(i,n){
		frr(j,n){
			if(idv[i][j]!=-1)
				vert.insert(idv[i][j]);
			if(idh[i][j]!=-1)
				hor.insert(idh[i][j]);
		}
	}

	for(auto x : vert){
		add(0,x,1);
	}

	for(auto x : hor)
		add(x,clk,1);

		for(auto x : are){
			//cout << "adicionando " << x.fst << " - " << x.snd << endl;
			add(x.fst,x.snd,1);
		}

	ans+=dinic(0,clk);

	cout << ans << endl;


}

int main(){
	
	fastio;
	while(cin>>n)
		go();
	return 0;
}