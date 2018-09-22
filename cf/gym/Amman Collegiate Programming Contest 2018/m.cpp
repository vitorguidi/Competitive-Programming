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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int hgt[100100],vis[100100];
int du[100100],dd[100100];
int pai[100100][26];

map<pii,int> cost;
vector< pair<int,pii> > nodes[100100];

int n;
int clk=1; 

void reset(){
	pai[1][0]=1;
	hgt[1]=0;
	dd[1]=du[1]=0;
}

void dfs(int v){
	
	vis[v]=clk;
	
	for(auto x : nodes[v]){
	
		int filho = x.fst;
		int c1 = x.snd.fst;
		int c2 = x.snd.snd;
		
		if(vis[filho]==clk)
			continue;
		
		hgt[filho] = 1+hgt[v];
		pai[filho][0] = v;
		
		dd[filho] = dd[v] + c1;
		du[filho] = du[v] + c2;
		
		dfs(filho);
		
	}

}

void build_table(){
	
	dfs(1);
	
	for(int i=1;i<=18;i++)
		for(int j=1;j<=n;j++)
			pai[j][i] = pai[ pai[j][i-1] ][i-1]; 

}

int lca(int a, int b){

	if(hgt[a]<hgt[b])
		swap(a,b);
		
	for(int i=18;i>=0;i--){
		if( hgt[ pai[a][i] ] >=hgt[b])
			a=pai[a][i];
	}
	
	if(a==b)	return a;
	
	for(int i=18;i>=0;i--){
		if( pai[a][i] != pai[b][i] ){
			a=pai[a][i];
			b=pai[b][i];
		}
	}
	
	return pai[a][0];
	
}


void solve(){

	scanf("%d",&n);
	reset();
	
	frr(i,n)
		nodes[i].clear();
	
	ll base =0;
	
	fr(i,n-1){
		
		int x,y,c1,c2; 
		scanf("%d%d%d%d",&x,&y,&c1,&c2);
		
		nodes[x].pb( mp(y , mp(c1,c2)) );
		nodes[y].pb( mp(x , mp(c2,c1)) );
		
		base+=c2;
		base+=c1;
		
	}
	
	build_table();
	clk++;
	

	int q;
	scanf("%d",&q);
	
	while(q--){
	
		int x,y;
		scanf("%d%d",&x,&y);
	
	
		int z=lca(x,y);
		
		ll ans = 0;
		
		ans+=du[y];
		ans-=du[z];
		
		ans+=dd[x];
		ans-=dd[z];
		printf("%lld\n", (long long)(base - ans));
		//cout << base-ans << endl;
		
	}

}

int main(){
	
	int t; scanf("%d",&t);
	
	while(t--) solve();   
    

}