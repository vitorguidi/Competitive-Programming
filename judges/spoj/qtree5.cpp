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

vector<int> nodes[MAXN];
int sz[MAXN],pai[MAXN];
multiset<int> ans[MAXN];
int tag[MAXN];
int memo[MAXN][25],hgt[MAXN];

int dfs(int u, int p){
	for(auto x : nodes[u]){
		if(x==p)	continue;
		memo[x][0]=u;
		hgt[x]=1+hgt[u];
		for(int i=1;i<=20;i++)	memo[x][i]=memo[memo[x][i-1]][i-1];
		dfs(x,u);
	}
}
int lca(int a, int b){
	if(hgt[a]<hgt[b])	swap(a,b);
	for(int i=20;i>=0;i--)
		if(hgt[memo[a][i]]>=hgt[b])	a=memo[a][i];
	if(a==b)	return a;
	for(int i=20;i>=0;i--)
		if(memo[a][i]!=memo[b][i])
			a=memo[a][i],b=memo[b][i];
	return memo[a][0];
}
int get_size(int u,int p){
	sz[u]=1;
	for(auto x : nodes[u]){
		if(p==x || pai[x])	continue;
		sz[u]+=get_size(x,u);
	}
	return sz[u];
}
int get_centroid(int u,int p,int tam){
	for(auto x : nodes[u]){
		if(pai[x] || x==p)	continue;
		if(sz[x]>tam/2)	return get_centroid(x,u,tam);
	}
	return u;
}
void build(int u,int p){

	int tam = get_size(u,p);
	int centroid = get_centroid(u,p,tam);
	pai[centroid]=p;

	for(auto x : nodes[centroid]){
		if(pai[x])	continue;
		build(x,centroid);
	}

}
int get_dist(int a, int b){
	return hgt[a]+hgt[b]-2*hgt[lca(a,b)];
}

int main(){

	fastio;

	int n; cin >> n;

	fr(i,n-1){
		int a,b;
		cin >> a >> b;
		nodes[a].pb(b);
		nodes[b].pb(a);
	}

	fr(i,21)	memo[1][i]=1;
	dfs(1,-1);	build(1,-1);

	frr(i,n)	ans[i].insert(INF);
	int q; cin >> q;

	while(q--){
	
		int op,node;
		cin >> op >> node;

		if(op==0){

			if(tag[node]==1){
				int root = node;
				while(root!=-1){
					int tmp = get_dist(node,root);
					auto it = ans[root].find(tmp);
					ans[root].erase(it);
					root=pai[root];
				}
				ans[node].erase(ans[node].begin());
			}

			if(tag[node]==0){

				int root = node;
				ans[root].insert(0);
				while(root!=-1){
					int tmp = get_dist(node,root);
					ans[root].insert(tmp);
					root=pai[root];
				}

			}

			tag[node]=!tag[node];

		}

		else{

			int resp = INF;
			int root = node;

			while(root!=-1){
				int val = *ans[root].begin();
				resp=min(resp,val+get_dist(root,node));
				root=pai[root];
			}

			cout << (resp==INF ? -1 : resp) << endl;

		}
	}

}