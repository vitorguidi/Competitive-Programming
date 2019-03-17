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

int n,m;
int grid[1010][1010];
vi row[1010],col[1010];
set<int> auxr[1010],auxc[1010];
int ans[1010][1010];

int main(){
    
	fastio;

	cin >> n >> m;
	fr(i,n){
		fr(j,m){
			cin >> grid[i][j];
			int x = grid[i][j];
			auxr[i].insert(x);
			auxc[j].insert(x);
		}
	}

	fr(i,n)
		for(auto x : auxr[i])	row[i].pb(x);
	
	fr(i,m)
		for(auto x : auxc[i])	col[i].pb(x);

	fr(i,n){
		fr(j,m){

			auto it = lower_bound(all(row[i]),grid[i][j]);
			int rank_row = it - row[i].begin() + 1;

			it = lower_bound(all(col[j]),grid[i][j]);
			int rank_col = it - col[j].begin() + 1;

			int rank = max(rank_col,rank_row);

			int lenr = row[i].size();
			int lenc = col[j].size();

			ans[i][j] = max(rank + lenr - rank_row, rank+lenc - rank_col);


		}
	}

	fr(i,n){
		fr(j,m){
			cout << ans[i][j] << " ";
		}
		gnl;
	}

}