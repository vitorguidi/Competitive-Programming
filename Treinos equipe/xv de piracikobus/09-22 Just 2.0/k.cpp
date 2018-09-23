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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int grid[3][3];
int used[9];
vi perm;
vi ind;
vi cafe;

int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};

bool in_grid(int x, int y){
	return x>=0 && x<3 && y>=0 && y<3;
}

bool check(){

	fr( i, ind.size() ){
		int id = ind[i];
		int x = id/3;
		int y = id%3;
		grid[x][y]=cafe[i];
	}

	fr(i,3){
		fr(j,3){

			int val = grid[i][j];
			bool aux = false;

			if(val==9)	continue;

			fr(k,8){

				int xf = i+dx[k];
				int yf = j + dy[k];
			
				if(!in_grid(xf,yf))	continue;
				
				if(grid[xf][yf]==val+1)
					aux = true;

			}

			if(aux==false)	return false;

		}
	}

	return true;

}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);    

	string aux;
	string lol="";
	fr(i,3){
		getline(cin,aux);
		lol+=aux;
	}
    
	fr(i,9){
		int val = lol[i]-'0';
		used[val]=1;
		int x = i/3;
		int y = i%3;
		grid[x][y]=val;
		if(!val)
			ind.pb(i);
	}


	frr(i,9)
		if(!used[i])
			cafe.pb(i);

	ll ans = 0;

	do{
		if(check())
			ans++;
	}while(next_permutation( all(cafe) ) );

	cout << ans << endl;

}