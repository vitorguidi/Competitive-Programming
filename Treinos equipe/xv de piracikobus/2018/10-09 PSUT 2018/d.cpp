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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

int v[100100],id[100100],sz[100100];
vi nodes[100100];

int ans[100100];
int pai[100100];

vi roots;
int amt;

void dfs(int v){

	ans[v]=amt--;

	for(auto x : nodes[v]){

		dfs(x);
		pai[x]=v;
	}

}

void dfs2(int v){

	
	cout << ans[v] << " ";

	for(auto x : nodes[v])
			dfs2(x);

}

int find(int x){
	
	if(id[x]==x)
		return x;

	return id[x]=find(id[x]);

}

void join(int a, int b){
	
	a=find(a);b=find(b);

	if(a==b)	return;

	if(sz[a]<sz[b])
		swap(a,b);

	sz[a]+=sz[b];
	id[b]=a;

}

int main(){

	fastio;

	int n; cin >> n;

	fr(i,n){
		id[i]=i;
		sz[i]=1;
	}

	frr(i,n){
		
		cin >> v[i];

		if(!v[i])
			roots.pb(i);

		nodes[ v[i] ].pb(i);

		if(v[i])
			join(i,v[i]);
	
	}

	int last=0;

	frr(i,n){
		sort(all(nodes[i]));
		reverse(all(nodes[i]));
	}

	for(auto x : roots){

		last+=sz[find(x)];
		amt=last;
		dfs(x);

	}

	frr(i,n)
		reverse(all(nodes[i]));
		
	for(auto x : roots)
		dfs2(x);
	gnl;

}