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

int n,m;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int dist[1010][1010],vis[1010][1010],grid[1010][1010];

bool valid(int x, int y){
	return x>=0 && x<n && y>=0 && y<m;
}

void dfs(int x, int y){

	vis[x][y]=1;

	fr(i,4){

		int xf = x+dx[i];
		int yf = y+dy[i];
	
		if(!valid(xf,yf))	continue;
		if(grid[xf][yf]==0)	continue;
		if(vis[xf][yf])		continue;
	
		dist[xf][yf] = 1 + dist[x][y];

		dfs(xf,yf);
	
	}

}

void solve(){

	cin >> m >> n;

	string s; getline(cin,s);

	int xr,yr;

	fr(i,n){
		getline(cin,s);
		fr(j,m){
			int aux;
			if(s[j]=='#')	aux=0;
			else{
				aux=1;
				xr=i;
				yr=j;
			}
			grid[i][j]=aux;
		}	
	}

	ms(dist,INF);
	ms(vis,0);
	dist[xr][yr]=0;


	dfs(xr,yr);


	int xm,ym;

	int best = -INF;


	fr(i,n){
		fr(j,m){
			if(dist[i][j]>best && dist[i][j]!=INF){
				best=dist[i][j];
				xm=i;
				ym=j;
			}
		}
	}
	
	ms(dist,INF);
	ms(vis,0);
	dist[xm][ym]=0;

	dfs(xm,ym);



	best=0;

	fr(i,n){
		fr(j,m){
			if(dist[i][j]==INF)	continue;
			best=max(best,dist[i][j]);
		}
	}


	cout << "Maximum rope length is "<< best << "." << endl;

}

int main(){

	fastio;

	int t; cin >> t;
	while(t--)	solve();

}
