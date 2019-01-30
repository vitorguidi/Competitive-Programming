#include "bits/stdc++.h"
using namespace std;
 
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define pq priority_queue	
#define vi vector<int>
#define vii vector<pair<int,int>>
#define pq priority_queue
#define fr(i,n)	for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
 
#define ms(x, v) memset(x, v, sizeof x)
#define all(x)	x.begin(),x.end()
 
#define dbg(x) cout << #x << " = " << x << endl
#define olar() cout << "olaarr" << endl
 
const int INF = 0x3f3f3f3f;
 
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
ll dist[100001];
int pai[100001];
int hgt[100001];
int memo[100001][25];
vector<vii> nodes;
 
int n,ini;
 
void dfs(int v){
		
	for(int i=0;i<nodes[v].size();i++){
		
		int filho=nodes[v][i].snd;
		if(hgt[filho]!=-1)	continue;	//se ja tem altura eh pq nao deveria ser filho de ninguem, so pai
 
		pai[filho]=v;
		hgt[filho]=hgt[v]+1;	
 
		dist[filho]+=dist[v]+nodes[v][i].fst;	//distancia da raiz ate ele eh a distancia da raiz ate o pai dele mais peso da aresta
		dfs(filho);
	}
 
}
 
void build_table(int n){		//sparse table padraozinha
	
	for(int i=0;i<n;i++)	memo[i][0]=pai[i];
	for(int i=1; (1<<i)<=n;i++ ){
		for(int j=0;j<n;j++)	memo[j][i]=memo[ memo[j][i-1] ][i-1];
	}
 
}
 
int lca(int a, int b){		//lca padraozinho
 
	if(hgt[a]<hgt[b])	swap(a,b);
 
	for(int i=ini;i>=0;i--){
		if(hgt[a] - (1<<i) >=hgt[b])	a=memo[a][i];
	}
 
	if(a==b)	return a;
 
	for(int i=ini;i>=0;i--){
		if(memo[a][i]!=memo[b][i] && memo[a][i]!=-1){
			a=memo[a][i];
			b=memo[b][i];
		}
	}
 
	return memo[a][0];
 
}
 
void cases(){
 
	for(int i=0;i<n;i++){
		for(int j=0;j<=ini;j++)	memo[i][j]=-1;
	}
 
	fr(i,n)	hgt[i]=-1;
	fr(i,n)	dist[i]=0;
 
	nodes.clear();
	nodes.resize(n);
	
	for(int i=1;i<=n-1;i++){
		int x;
		ll y;
		cin >> x >> y;
		nodes[i].pb(mp(y,x));
		nodes[x].pb(mp(y,i));	//guarda o peso da aresta(y) e a aresta de destino
	}
 
	hgt[0]=0;
	pai[0]=0;
	dfs(0);			//enraiza arvore no vertice 0
	
	build_table(n);
 
	int q;
	cin >> q;
 
	for(int i=0;i<q;i++){	//faz as queries 
		int a,b,c;
		cin >> a >> b;
		c=lca(a,b);
		cout << dist[a]+dist[b]-2*dist[c];
		if(i!=q-1)	cout << " ";		//pega a distancia da raiz ate a e b, subtrai 2x a distancia da raiz ate o lca(redundancia)
	}
 
	cout << endl;
 
}
 
int main(){
	n=-1;
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
 
	while(n!=0){
		cin >> n;
		if(n==0)	break;
		ini=0;				//computa log2n
		while( 1<<(ini+1) <=n )	ini++;
		cases();
	}
}