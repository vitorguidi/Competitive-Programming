#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;

char grid[550][550];
int comp[550][550];
int n,m;
	
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int diagx[4]= {-1,-1,1,1};
int diagy[4] = {-1,1,1,-1};

bool in_grid(int x, int y){

	if(x<0 || x>=n)
		return false;
	
	if(y<0 || y>=m)
		return false;
	
	return true;
}

void dfs(pii v, int id){

	comp[v.fst][v.snd]=id;

	fr(i,4){
	
		int fx = v.fst+dx[i];
		int fy = v.snd+dy[i];
	
		if(!in_grid(fx,fy))
			continue;

		if(grid[fx][fy]=='.')
			continue;
		
		if(!comp[fx][fy])
			dfs(mp(fx,fy),id);

	}

}

bool check(){

	fr(i,n){
		fr(j,m){

			if(grid[i][j]=='.')
				continue;

			fr(k,4){
				
				int px=i+diagx[k];
				int py=j+diagy[k];
				
				if(!in_grid(px,py))
					continue;
				
				if(grid[px][py]!='.')
					return false;
			}

			fr(k,4){

				int px = i + dx[k];
				int py = j + dy[k];
				
				if(!in_grid(px,py))
					continue;

				if(grid[px][py]=='.')
					continue;

				int ref = comp[px][py];

				if(k%2==1){	//estou em lados, quero ver se da bosta em cima ou baixo

					pii bag1 = mp(i+dx[0],j+dy[0]);
					if( in_grid(bag1.fst,bag1.snd) && grid[bag1.fst][bag1.snd]!='.' )
						return false;
					
					pii bag2 = mp(i+dx[2],j+dy[2]);
					if( in_grid(bag2.fst,bag2.snd) && grid[bag2.fst][bag2.snd]!='.')
						return false;

				}

				if(k%2==0){	//estou em cima/baixo, quero ver se da bosta em lados

					pii bag1 = mp(i+dx[1],j+dy[1]);
					if( in_grid(bag1.fst,bag1.snd) && grid[bag1.fst][bag1.snd]!='.' )
						return false;
					
					pii bag2 = mp(i+dx[3],j+dy[3]);					
					if( in_grid(bag2.fst,bag2.snd) && grid[bag2.fst][bag2.snd]!='.')
						return false;
	
				}



			}

		}
	}

	return true;

}

int main(){

	string s;

	cin >> n >> m;
	getline(cin,s);

	fr(i,n){
		getline(cin,s);
		fr(j,m)
			grid[i][j]=s[j];
	}

	int valor =1;

	fr(i,n){
		fr(j,m){
			if(!comp[i][j] && grid[i][j]!='.'){
				dfs(mp(i,j),valor);
				valor++;
			}
		}
	}

	if(!check())
		cout << "Reorganize o tabuleiro" << endl;
	else
		cout << "Comece a partida" << endl;

}