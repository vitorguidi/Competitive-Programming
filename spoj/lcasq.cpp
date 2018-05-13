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
#define grtp greater<pair<int,int>
 
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define ms(x, v) memset(x, v, sizeof x)
#define all(x)	x.begin(),x.end()
 
#define dbg(x) cout << #x << " = " << x << endl
#define gnl cout << endl
#define olar() cout << "olaarr" << endl
 
const int INF = 0x3f3f3f3f;
 
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
vector<vi> nodes;
int memo[100001][30];
int pai[100001];
int hgt[100001];
int n;
int l2n;
 
int log2(int x){
	int ini=0;
	while(1<<(ini+1)<=x)	ini++;
	return ini;
}
 
void dfs(int v){
	int tam=nodes[v].size();
	fr(i,tam){
		int filho=nodes[v][i];
		pai[filho]=v;
		hgt[filho]=hgt[v]+1;
		dfs(filho);
	}
}
 
int lca(int a, int b){
	if(hgt[a]<hgt[b])	swap(a,b);
 
	for(int i=l2n; i>=0; i-- ){		//bota a e b na mesma altura
		if(hgt[a]- (1<<i) >= hgt[b])	a=memo[a][i];
	}
 
	if(a==b)	return a;	//se forem iguais, retorna o LCA
 
	for(int i=l2n; i>=0; i--){	//vai pulando ate ficarem um nivel antes do LCA
		if(memo[a][i]!=-1 && memo[a][i]!=memo[b][i]){
			a=memo[a][i];
			b=memo[b][i];
		}
	}
 
	return memo[b][0];
 
}
 
int main(){
 
	cin >> n;
	l2n=log2(n);
 
	nodes.resize(n);
	ms(memo,-1);
	fr(i,n)	pai[i]=i;
 
	fr(i,n){
 
		int m,x;
		cin >> m;
		fr(j,m){
			cin >> x;
			nodes[i].pb(x);
		}
	}
 
	dfs(0);
 
 
	fr(i,n)	memo[i][0]=pai[i];
 
	for(int i=1; 1<<i <= n;i++){										//calcula a sparse table pras potencias de 2 apropriadas
		for(int j=0;j<n;j++)	memo[j][i]=memo[ memo[j][i-1] ][i-1];	//calcula o role pra todos os vertices
		
	}
 
	int q;
	cin >> q;
	fr(i,q){
		int a,b;
		cin >> a >> b;
		cout << lca(a,b) << endl;
	}
 
}
 