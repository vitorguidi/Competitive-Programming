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

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

int vis[1010][1010];
int comp[1010][1010];
int ans[1100100];

char grid[1010][1010];
int n,m,q;
int clk=1;

bool valid(int x, int y){
	return x>=0 && x<n && y>=0 && y<m;
}

void dfs(int x, int y){

	vis[x][y]=1;
	comp[x][y]=clk;

	fr(i,4){

		int fx=x+dx[i];
		int fy=y+dy[i];

		if(valid(fx,fy) && grid[fx][fy]=='*')
			ans[clk]++;

		if(!valid(fx,fy))	continue;
		if(grid[fx][fy]=='*')	continue;
		if(vis[fx][fy])	continue;

		dfs(fx,fy);

	}

}

int main(){

	fastio;

	cin >> n >> m >> q;

	string s;
	getline(cin,s);

	fr(i,n){
		getline(cin,s);
		fr(j,m)
			grid[i][j]=s[j];
	}

	fr(i,n){
		fr(j,m){
			if(vis[i][j])	continue;
			if(grid[i][j]=='*')	continue;
			dfs(i,j);
			clk++;
		}
	}


	fr(i,q){
		int x,y;
		cin >> x >> y;
		x--;
		y--;
		cout << ans[comp[x][y]] << endl;
	}

}