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
typedef tuple<ll,ll,ll> edg;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

ll adj[550][550];
int c[550];
int id[100100];
int sz[100100];
map<int,int> quem;

int find(int x){
	if(id[x]==x)	return x;
	return id[x]=find(id[x]);
}

void join(int a, int b){
	a=find(a);
	b=find(b);
	if(a==b)	return;
	if(sz[a]<sz[b])	swap(a,b);
	sz[a]+=sz[b];
	id[b]=a;
}

int main(){

	fastio;

	fr(i,550)
		fr(j,550)
			adj[i][j]=llINF;

	fr(i,100100){
		id[i]=i;
		sz[i]=1;
	}

	int n,m,k;

	cin >> n >> m >> k;

	frr(i,k){
		cin >> c[i];
		c[i]+=c[i-1];
	}

	vector<edg> are;

	int cara=1;
	int ini=1;
	int end =c[1];

	while(cara<=k){
		for(int i=ini;i<=end;i++)
			quem[i]=cara;
		ini=c[cara]+1;
		end=c[++cara];
	}

	frr(i,m){
		ll u,v,x;
		cin >> u >> v >> x;
		if(x==0)	join(u,v);
		u=quem[u];
		v=quem[v];
		if(adj[u][v]>x)	adj[u][v]=x;
		if(adj[v][u]>x)	adj[v][u]=x;
	}

	cara=1;
	ini=1;
	end=c[1];

	while(cara<=k){
		set<int> aux;
	
		for(int i=ini;i<=end;i++)
			aux.insert(find(i));

		if(aux.size()>1){
			cout << "No" << endl;
			return 0;
		}
		ini=c[cara]+1;
		end=c[++cara];
	}

	frr(i,k)	adj[i][i]=0;

	frr(l,k){

		frr(i,k)
			frr(j,k)
				adj[i][j]=min<ll>(adj[i][l]+adj[l][j],adj[i][j]);

	}

	frr(i,k){
		frr(j,k){
			if(adj[i][j]==llINF)
				adj[i][j]=-1;
		}
	}

	cout << "Yes" << endl;
	frr(i,k){
		frr(j,k){
			cout << adj[i][j] << " ";
		}
		gnl;
	}

}
