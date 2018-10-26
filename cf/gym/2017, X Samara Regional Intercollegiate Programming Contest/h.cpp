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

int main(){

	fastio;

	int n,m; cin >> n >> m;
	int grid[1010][1010];

	vi out;

	int x,y;
	int mx = -INF;

	fr(i,n){
		fr(j,m){

			cin >> grid[i][j];
			
			if(grid[i][j]>mx){
				mx=grid[i][j];
				x=i;
				y=j;
			}

		}
	}

	//fixa linha x pra tirar e acha a melhor coluna

	int ans1 = -INF;
	int idc;

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){

			if(i==x)	continue;

			if(grid[i][j]>ans1){
				ans1=grid[i][j];
				idc=j;
			}

		}
	}

	ans1=-INF;

	//fixada a linha (x) e escolhida a coluna (idc), pego o max q n ta la

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){

			if(i==x || j == idc)	continue;
			ans1=max(ans1,grid[i][j]);

		}
	}

	out.pb(ans1);

	int idl;
	ans1=-INF;

	//exclui coluna y e tenta achar a melhor linha pra excluir

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){

			if(j==y)	continue;
		
			if(grid[i][j]>ans1){
				ans1=grid[i][j];
				idl=i;
			}

		}
	}

	//acha maior cara excluindo linha idl e coluna y

	ans1=-INF;

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){

			if(j==y || i==idl)	continue;
			ans1=max(ans1,grid[i][j]);

		}
	}

	out.pb(ans1);


	x++;y++;idl++;idc++;

	if(out[0]<=out[1])
		cout << x << " " << idc << endl;
	else
		cout << idl << " " << y << endl;

}
