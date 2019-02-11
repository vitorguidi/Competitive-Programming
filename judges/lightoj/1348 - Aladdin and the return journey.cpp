#include "bits/stdc++.h"
using namespace std;

#define olar cout << "Olar" << endl
#define dbg(x)	cout << #x << " == " << x << endl
#define frr(i,n)	for(int i=1;i<=n;i++)
#define gnl cout << endl

// roubado descaradamente do LoppA mais uma vez
// https://github.com/LoppA/RepGod/blob/master/data_structures/hld_vertex.cpp
// indexados do 1

const int MAXN = 30300;

vector<int> nodes[MAXN];
int v[MAXN],data[MAXN];
int bit[MAXN];

int hgt[MAXN],pai[MAXN],sz[MAXN];		
int chain[MAXN],heavy[MAXN],top[MAXN],id[MAXN];
int ind,ch,n;										
int clk;
int cnt=1;

int query(int ind){
	int ans=0;
	for(int i=ind;i>0;i-=i&-i)	ans+=bit[i];
	return ans;
}
void update(int ind,int val){
	int old_val=query(ind)-query(ind-1);
	for(int i=ind;i<=n;i+=i&-i)	bit[i]+=val-old_val;
}

int dfs(int u){			

	sz[u]=1;

	for(auto x : nodes[u]){

		if(x==pai[u])	continue;
		
		hgt[x]=1+hgt[u];
		pai[x]=u;
		sz[u]+=dfs(x);
		
		if(sz[x]>sz[heavy[u]])
			heavy[u]=x;		
	
	}

	return sz[u];

}

void hld(int u){		

	id[u]=ind++;

	if(heavy[u]){					
		chain[ heavy[u] ] = chain[u];
		hld(heavy[u]);
	}

	for(auto x : nodes[u]){			

		if(x==pai[u] || x==heavy[u])	continue;
	
		top[ch]=x;
		chain[x]=ch++;
		hld(x);
	
	}

}

void build_hld(){
	
	memset(heavy,0,sizeof heavy);
	memset(bit,0,sizeof bit);

	pai[1]=1;	
	dfs(1);		
		
	ind=ch=1;
	chain[1]=ch++;
	top[1]=1;	
	hld(1);
	

}

int go(int u, int v){			
								
	int ans = 0;

	while(chain[u]!=chain[v]){	

		if(hgt[ top[chain[u]] ] < hgt[ top[chain[v]] ])	
			swap(u,v);

		int sobe = top[ chain[u] ];
		
		ans+=query(id[u])-query(id[sobe]-1); 
		u=pai[sobe];

	}

	if(id[u]>id[v])	swap(u,v);	

	ans+=query(id[v])-query(id[u]-1);
	return ans;

}

int main(){

	int t;
	scanf("%d",&t);
	
	while(t--){

		for(int i=1;i<=n;i++)	nodes[i].clear();

		scanf("%d",&n);
		for(int i=1;i<=n;i++)	scanf("%d",&data[i]);	

		for(int i=1;i<n;i++){
			int a,b;scanf("%d%d",&a,&b);
			a++;b++;
			nodes[a].push_back(b);
			nodes[b].push_back(a);
		}


		build_hld();

		for(int i=1;i<=n;i++)	update(id[i],data[i]);

		int q;scanf("%d",&q);

	
		printf("Case %d:\n",++clk);

		while(q--){

			int op,x;
			int y;
			scanf("%d%d%d",&op,&x,&y);
		
			if(!op)	printf("%d\n",go(++x,++y));
			else	update(id[++x],y);	

		}	

	}
	
}