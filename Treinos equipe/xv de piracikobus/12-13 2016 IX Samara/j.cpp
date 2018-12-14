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

vector<vi> grid;
vector<vi> deg;
vector<vi> vis;
vector<vii> pai;
int n,m;

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

map<tuple<int,int,int,int>,int> block;

bool valid(int x, int y){
	return x>=0 && x<n && y>=0 && y<m;
}

void dfs(int x, int y){

	vis[x][y]=1;

	fr(i,4){
	
		int fx = x+dx[i];
		int fy = y+dy[i];
	
		if(!valid(fx,fy)) 	continue;
		if(vis[fx][fy])		continue;
		if(grid[fx][fy]==0)	continue;

		pai[fx][fy]={x,y};

		dfs(fx,fy);

	}

}

void dfs2(int x, int y){
	
	vis[x][y]=1;

	fr(i,4){
	
		int fx = x+dx[i];
		int fy = y+dy[i];
	
		if(!valid(fx,fy)) 	continue;
		if(vis[fx][fy])		continue;
		if(grid[fx][fy]==0)	continue;
		if(block[make_tuple(x,y,fx,fy)])
			continue;

		dfs2(fx,fy);

	}



}

int dfs3(int x, int y){

	int ans = (deg[x][y]>2);
	vis[x][y]=1;

	fr(i,4){

		int fx=x+dx[i];
		int fy=y+dy[i];

		if(!valid(fx,fy)) 	continue;
		if(vis[fx][fy])		continue;
		if(grid[fx][fy]==0)	continue;

		ans=max(ans,dfs3(fx,fy));

	}

	return ans;

}

int main(){

	fastio;

	cin >> n >> m;

	int x1,y1,x2,y2;

	grid.resize(n);
	vis.resize(n);
	deg.resize(n);
	pai.resize(n);

	fr(i,n){
		grid[i].resize(m);
		vis[i].resize(m);
		deg[i].resize(m);
		pai[i].resize(m);
	}

	string s; getline(cin,s);

	fr(i,n){
		getline(cin,s);
		fr(j,m){
			if(s[j]=='#')
				grid[i][j]=0;
			else if(s[j]=='.')
				grid[i][j]=1;
			else if(s[j]=='1'){
				x1=i;
				y1=j;
				grid[i][j]=1;
			}
			else{
				x2=i;
				y2=j;
				grid[i][j]=1;
			}
		}
	}


	pai[x1][y1]={x1,y1};
	dfs(x1,y1);

	if(!vis[x2][y2]){
		puts("NO");
		return 0;
	}

	fr(i,n){
		fr(j,m){
			if(grid[i][j]==0)	continue;
			fr(k,4){
				if(valid(i+dx[k],j+dy[k]) && grid[i+dx[k]][j+dy[k]]==1){
					deg[i][j]++;
				}
			}
		}
	}


	pii cara = {x2,y2};

	vii path;

	while(pai[cara.fst][cara.snd]!=cara){
		path.pb(cara);
		cara=pai[cara.fst][cara.snd];
	}

	path.pb({x1,y1});

	
	int len = path.size();

	fr(i,n)
		fr(j,m)
			vis[i][j]=0;

	int flag = dfs3(x1,y1);

	if(flag){
		puts("YES");
		return 0;
	}

	pii primeiro = path[0];
	pii segundo = path[1];

	tuple<int,int,int,int> aux;

	get<0>(aux)=primeiro.fst;
	get<1>(aux)=primeiro.snd;
	
	get<2>(aux)=segundo.fst;
	get<3>(aux)=segundo.snd;
	
	block[aux]=1;
	
	get<2>(aux)=primeiro.fst;
	get<3>(aux)=primeiro.snd;
	
	get<0>(aux)=segundo.fst;
	get<1>(aux)=segundo.snd;
	
	block[aux]=1;

	fr(i,n)
		fr(j,m)
			vis[i][j]=0;

	dfs2(x1,y1);

	if(!vis[x2][y2])
		puts("NO");
	else
		puts("YES");
	

}