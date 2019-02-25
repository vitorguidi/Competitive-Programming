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

int n,m,k;
int good[100100];
int vis[100100],amt[100100];
vii nodes[100100];
vii nodes2[100100];
int sz[100100],id[100100];
int best[100100],hgt[100100];
int pai[100100];

int find(int a){
	if(a==id[a])	return a;
	return id[a]=find(id[a]);
}

void join(int a, int b){
	a=find(a);b=find(b);
	if(a==b)	return;
	if(sz[a]<sz[b])	swap(a,b);
	id[b]=a;
	sz[a]+=sz[b];
}

void dfs(int u){

	vis[u]=1;
	amt[u]=good[u];

	for(auto x : nodes2[u]){
		if(vis[x.snd])	continue;
		pai[x.snd]=u;
		dfs(x.snd);
		amt[u]+=amt[x.snd];
		hgt[x.snd]=1+hgt[u];
		if(amt[x.snd])	best[u]=max({best[u],x.fst,best[x.snd]});
	}

}

int main(){
    
	fastio;

	cin >> n >> m >> k;

	frr(i,n){sz[i]=1;id[i]=i;}

	frr(i,k){
		int x; cin >> x;
		good[x]++;
	}

	vector<tuple<int,int,int>> are;

	fr(i,m){
		int u,v,w;
		cin >> u >> v >> w;
		are.pb(make_tuple(w,v,u));
	}

	sort(all(are));

	for(auto x : are){
		int u,v,w;
		w = get<0>(x);
		u = get<1>(x);
		v = get<2>(x);
		if(find(u)==find(v))	continue;
		join(u,v);
		nodes2[u].pb({w,v});
		nodes2[v].pb({w,u});
	}

	pai[1]=1;
	dfs(1);

	int h = 0;
	int raiz;
	frr(i,n){
		if(hgt[i]>=h && amt[i]==k){
			h=hgt[i];
			raiz=i;
		}
	}

	frr(i,k)	cout << best[raiz] << " ";
	gnl;

}