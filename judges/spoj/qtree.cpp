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
const int MAXN=10100;

int hgt[MAXN],pai[MAXN],sz[MAXN];
int chain[MAXN],top[MAXN],id[MAXN],heavy[MAXN];
int ind,ch;

int n,ned;
int seg[4*MAXN];
int v[MAXN],data[MAXN];
vector<tuple<int,int,int>> edges;
vi nodes[MAXN];

void build(int node, int l, int r){
	if(l==r){seg[node]=v[l];return;}
	int mid = (l+r)/2;
	build(2*node,l,mid);
	build(2*node+1,mid+1,r);
	seg[node]=max(seg[2*node],seg[2*node+1]);
}
int query(int node, int l, int r, int a, int b){
	if(l>b || r<a || l>r)	return -INF;
	if(a<=l && r<=b)	return seg[node];
	int mid = (l+r)/2;
	return max(query(2*node,l,mid,a,b),query(2*node+1,mid+1,r,a,b));
}
void update(int node, int l, int r, int ind, int val){
	if(l==r){seg[node]=v[ind]=val;return;}
	int mid = (l+r)>>1;
	if(ind<=mid)	update(2*node,l,mid,ind,val);
	else			update(2*node+1,mid+1,r,ind,val);
	seg[node]=max(seg[2*node],seg[2*node+1]);
}

int dfs(int u){
	sz[u]=1;
	for(auto x : nodes[u]){
		if(x==pai[u])	continue;
		hgt[x]=1+hgt[u];
		pai[x]=u;
		sz[u]+=dfs(x);
		if(sz[x]>sz[heavy[u]])	heavy[u]=x;
	}
	return sz[u];
}
void hld(int u){
	id[u]=ind++;
	if(heavy[u]){
		chain[heavy[u]]=chain[u];
		hld(heavy[u]);
	}
	for(auto x : nodes[u]){
		if(pai[u]==x || heavy[u]==x)	continue;
		top[ch]=x;
		chain[x]=ch++;
		hld(x);
	}
}

void build_hld(){
	memset(heavy,0,sizeof heavy);
	pai[1]=1;
	chain[1]=0;
	top[0]=1;
	ind=ch=1;
	ned=0;
	dfs(1);
	hld(1);
}

int go(int u, int v){

	int ans = -INF;

	bool flag=false;
	
	while(chain[u]!=chain[v]){
	
		if(hgt[ top[chain[u]] ] < hgt[top[chain[v]]])
			swap(u,v);
	
		int sobe = top[chain[u]];
		ans=max(ans,query(1,1,n,id[sobe],id[u]));
	
		u=pai[sobe];
	}
	if(id[u]>id[v])	swap(u,v);
	return ans = max(ans, query(1,1,n,id[u]+1,id[v]) );
}


void solve(){

	scanf("%d",&n);

	for(int i=1;i<=n;i++)	nodes[i].clear();
	edges.clear();

	fr(i,n-1){
		int a,b,cost;
		scanf("%d %d %d",&a,&b,&cost);
		edges.pb(make_tuple(a,b,cost));
		nodes[a].pb(b);
		nodes[b].pb(a);
		ned++;
	}

	build_hld();

	for(auto x : edges){
		int a = get<0>(x);
		int b = get<1>(x);
		int cost = get<2>(x);
		if(hgt[a]<hgt[b])	swap(a,b);
		v[id[a]]=cost;
	}

	build(1,1,n);
	char op[60];

	while(true){
	
		scanf("%s",op);
	
		if(strcmp(op,"DONE")==0)	break;
	
		int x,y;
		scanf("%d%d",&x,&y);
	
		if(strcmp(op,"CHANGE")==0){
			int a = get<0>(edges[x-1]);
			int b = get<1>(edges[x-1]);
			if(hgt[a]<hgt[b])	swap(a,b);
			update(1,1,n,id[a],y);
		}
		else	printf("%d\n",go(x,y));
	}

}

int main(){

	int t; scanf("%d",&t);
	while(t--)	solve();

	
}