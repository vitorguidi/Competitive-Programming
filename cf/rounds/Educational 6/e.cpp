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
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

vi nodes[400400];
ll colors[400400];
int pre[400400],pos[400400];
ll seg[8*400400];
ll lazy[8*400400];
int vis[400400];
int clk=1;
int n,m;

void unlazy(int node, int l, int r){
	
	if(!lazy[node])	return;
	
	seg[node]=lazy[node];
	
	if(l!=r)
		lazy[2*node]=lazy[2*node+1]=seg[node];

	lazy[node]=0;
	
}

ll query(int node, int l, int r, int a, int b){

	unlazy(node,l,r);

	if(r<a || l>b)	return 0;

	if(a<=l && r<=b)	return seg[node];

	int mid = (l+r)/2;

	return query(2*node,l,mid,a,b)|query(2*node+1,mid+1,r,a,b);

}

void update(int node, int l, int r, int a, int b, ll val){

	unlazy(node,l,r);

	if(r<a || l>b)	return;

	if(a<=l && r<=b){
		seg[node]=val;
		if(l!=r)
			lazy[2*node]=lazy[2*node+1]=val;
		return;
	}

	int mid = (l+r)/2;

	update(2*node,l,mid,a,b,val);
	update(2*node+1,mid+1,r,a,b,val);

	seg[node]=seg[2*node]|seg[2*node+1];


}

void dfs(int v){
	pre[v]=clk++;
	for(auto x : nodes[v]){
		if(pre[x])	continue;
		dfs(x);
	}
	pos[v]=clk++;
}

void dfs2(int v){
	vis[v]=1;
	update(1,1,2*n,pre[v],pos[v],1ll<<(colors[v]));
	for(auto x : nodes[v]){
		if(vis[x])	continue;
		dfs2(x);
	}
}

int main(){
    

	scanf("%d %d",&n,&m);

	frr(i,n){
		scanf("%d",&colors[i]);
		colors[i]--;
	}
	
	fr(i,n-1){
		int x,y;
		scanf("%d %d",&x,&y);
		nodes[x].pb(y);
		nodes[y].pb(x);
	}

	dfs(1);
	dfs2(1);

	fr(i,m){

		int op;
		scanf("%d",&op);
	
		if(op==1){
			ll v,c;
			scanf("%I64d %I64d",&v,&c);
			c--;
			update(1,1,2*n,pre[v],pos[v],1ll<<c);
		}
		else{
			ll v;
			scanf("%I64d",&v);
			printf("%d\n",__builtin_popcountll(query(1,1,2*n,pre[v],pos[v])));
		}

	}

}