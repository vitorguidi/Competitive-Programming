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
#define pira cout << "pira" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

char v[55][55];
int vis[55][55];
int n,m;
	
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

bool in_grid(int x, int y){

	if(x<1 || x>n)
		return false;
	if(y<1 || y>m)
		return false;
	return true;

}

void dfs(int x, int y){

	vis[x][y]=1;

	fr(i,4){

		int xf = x+dx[i];
		int yf = y+dy[i];
		
		if(!in_grid(xf,yf))
			continue;
		
		if(vis[xf][yf])
			continue;
		
		if(v[xf][yf]=='W')
			continue;

		// dbg(xf);
		// dbg(yf);
		// gnl;
		dfs(xf,yf);
	
	}

}

int main(){
    
	cin >> n >> m;    
	string s;
	getline(cin,s);

	frr(i,n){
		getline(cin,s);
		frr(j,m){
			v[i][j]=s[j-1];
		}
	}

	int comp=0;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){

			if(!vis[i][j] && v[i][j]=='L'){
				comp++;
				dfs(i,j);
			}


		}
	}

	cout << comp << endl;


}

