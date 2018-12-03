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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll; 

const int INF = 0x3f3f3f3f;
const int MAXL = 25;

vector<pll> nodes[200200],nodes2[200200];
ll id[200200],sz[200200];
ll vis[200200],hgt[200200];
ll pai[200200][MAXL+3];
ll mx[200200][MAXL+3];
map<pii,int> check;
int n,m;

int find(int x){
	if(id[x]==x)
		return x;
	return id[x]=find(id[x]);
}

void join(int a, int b){
	a=find(a);b=find(b);
	if(a==b)	return;
	if(sz[b]>sz[a])	swap(a,b);
	id[b]=a;
	sz[a]+=sz[b];
}

void dfs(int v){
	
	vis[v]=1;

	for(auto x : nodes[v]){
	
		int filho = x.snd;
		if(vis[filho])	continue;
	
		pai[filho][0]=v;
		mx[filho][0]=x.fst;

		hgt[filho]=1+hgt[v];
	
		dfs(filho);
	}

}

void build_table(){

	for(int i=1;i<=MAXL;i++){
		for(int j=1;j<=n;j++){

			int midway = pai[j][i-1];

			pai[j][i] = pai[midway][i-1];
			mx[j][i] = max( mx[midway][i-1], mx[j][i-1] );
			
		}
	}

}

ll lca(int a, int b){
	
	if(hgt[a]<hgt[b])	swap(a,b);
	ll peso = 0;

	for(int i=MAXL;i>=0;i--){
	
		if(hgt[pai[a][i]]>=hgt[b]){
			peso=max(peso,mx[a][i]);
			a=pai[a][i];
		}

	}

	if(a==b)	return peso;

	for(int i=MAXL;i>=0;i--){

		if( pai[a][i] != pai[b][i] ){
			peso=max(peso,mx[a][i]);
			peso=max(peso,mx[b][i]);
			a=pai[a][i];
			b=pai[b][i];
		}

	}

	peso=max(peso,mx[a][0]);
	peso=max(peso,mx[b][0]);

	return peso;

}

int main(){

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;

	vector<pair<int,pii> > edges,edges2;

	fr(i,m){
		ll w,x,y;
		cin >> x >> y >> w;
		edges.pb( mp( w , mp(x,y) ) );
		edges2.pb( mp(w , mp(x,y) ) );
	}

	sort(all(edges2));
	
	frr(i,n)
		id[i]=i;

	ll wgt = 0;

	for(auto k : edges2){
		
		int w = k.fst;
		int x = k.snd.fst;
		int y = k.snd.snd;

		if(find(x)!=find(y)){
			join(x,y);
			wgt+=w;
			nodes[x].pb(mp(w,y));
			nodes[y].pb(mp(w,x));
			check[{x,y}]=check[{y,x}]=1;
		}
	}

	hgt[1]=0;
	pai[1][0]=1;
	mx[1][0]=0;

	dfs(1);

	build_table();

	fr(i,m){

		ll w = edges[i].fst;
		ll x= edges[i].snd.fst;
		ll y = edges[i].snd.snd;
		
		ll aux = wgt;
		aux-=lca(x,y);
		aux+=w;
		
		if(check[{x,y}])
			cout << wgt << endl;
		else
			cout << aux << endl;
	}


}

