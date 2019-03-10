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

int grid[1010][1010];

int id[2010];
int sz[2010];
int ans[2020];
vi nodes[2020];
int vis[2020];
int deg[2020];

bool flag = false;

void dfs(int v){

	vis[v]=1;

	for(auto x : nodes[v]){
		if(vis[x]==1)	flag=true;
		if(vis[x])		continue;
		dfs(x);
	}

	vis[v]=2;

}

int find(int a){
	if(id[a]==a)	return a;
	return id[a]=find(id[a]);
}

void join(int a, int b){
	a=find(a);b=find(b);
	if(a==b)	return;
	if(sz[a]<sz[b])	swap(a,b);
	id[b]=id[a];
	sz[a]+=sz[b];
}

int main(){
    
	fastio;

	int n,m;
	cin >> n >> m;

	fr(i,n+m){
		id[i]=i;
		sz[i]=1;
	}
	string lol;
	getline(cin,lol);

	fr(i,n){
	
		getline(cin,lol);

		fr(j,m){
			if(lol[j]=='=')
				grid[i][j]=0;
			if(lol[j]=='<')
				grid[i][j]=-1;
			if(lol[j]=='>')
				grid[i][j]=1;
		}
	
	}

	fr(i,n)
		fr(j,m)
			if(grid[i][j]==0)	join(i,j+n);


	fr(i,n){
		fr(j,m){

			if(grid[i][j]==1){
				nodes[find(j+n)].pb(find(i));
				deg[find(i)]++;
			}

			else if(grid[i][j]==-1){
				nodes[find(i)].pb(find(j+n));
				deg[find(j+n)]++;
			}

		}
	}

	fr(i,n+m){
		if(vis[find(i)])	continue;
		dfs(find(i));
	}

	if(flag){
		cout << "No" << endl;
		return 0;
	}

	fr(i,n+m)
		if(!deg[find(i)])	ans[find(i)]=1;


	set<int> s;

	fr(i,n+m)
		if(!deg[find(i)])
			s.insert(find(i));

	while(!s.empty()){

		int pai = *s.begin();
		s.erase(s.begin());

		for(auto x : nodes[pai]){

			deg[x]--;
			ans[x]=max(ans[x],1+ans[pai]);

			if(!deg[x])	s.insert(x);

		}

	}

	cout << "Yes" << endl;
	fr(i,n)	cout << ans[find(i)] << " ";
	gnl;
	fr(i,m)	cout << ans[find(n+i)] << " ";
	gnl;



}