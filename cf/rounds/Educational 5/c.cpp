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

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int grid[1010][1010];
int vis[1010][1010];
int comp[1010][1010];
int sz[1100100];
int n,m;
int ans[1010][1010];

int id;

bool valid(int x, int y){
	return x>=0 && x<n && y>=0 && y<m;
}

void dfs(int x, int y){
	
	vis[x][y]=1;
	comp[x][y]=id;
	sz[id]++;
	
	fr(i,4){
		int fx=x+dx[i];
		int fy=y+dy[i];

		if(!valid(fx,fy))	continue;
		if(grid[fx][fy]==0)	continue;
		if(vis[fx][fy])		continue;
		dfs(fx,fy);
	}
}

int main(){
    
	fastio;

	cin >> n >> m;

	string s;
	getline(cin,s);

	fr(i,n){
		getline(cin,s);
		fr(j,m){
			grid[i][j]= ( s[j]=='*' ? 0 : 1 );
		}
	}

	fr(i,n){
		fr(j,m){
			if(vis[i][j] || !grid[i][j])	continue;
			dfs(i,j);
			id++;
		}
	}

	ms(ans,-1);

	fr(i,n){
		fr(j,m){

			if(grid[i][j])	continue;
			set<int> aux;
			
			fr(k,4){
				int fx=i+dx[k];
				int fy=j+dy[k];
				if(!valid(fx,fy))	continue;
				if(!grid[fx][fy])	continue;
				aux.insert(comp[fx][fy]);
			}

			int amt = 0;
			for(auto x : aux)
				amt+=sz[x];
			ans[i][j]=amt;

		}
	}

	// fr(i,n){
	// 	fr(j,m){
	// 		cout << ans[i][j]+1 << " ";
	// 	}
	// 	gnl;
	// }

	fr(i,n){
		fr(j,m){
			if(ans[i][j]==-1)
				cout << '.';
			else
				cout << (ans[i][j]+1)%10;
		}
		gnl;
	}
}

