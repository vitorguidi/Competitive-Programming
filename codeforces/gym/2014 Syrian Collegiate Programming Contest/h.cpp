#include <bits/stdc++.h>
using namespace std;

#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define INF 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define fst first
#define snd second
#define fastcin ios_base::sync_with_stdio(false);
#define ll long long
#define endl "\n"
#define MAX 

ll dx[]={1,0};
ll dy[]={0,1};

ll memo[1010][1010];
ll grid[1010][1010];

int n,m;
int clk=1;

bool valid(int x, int y){
	return x>=1 && x<=n && y>=1 && y<=m;
}

ll pd(int i, int j){

	if(!valid(i,j))	return -INF;
	if(i==n && j==m)	return grid[i][j];

	ll &pdm = memo[i][j];
	if(pdm!=-INF)	return pdm;

	return pdm= grid[i][j] + max<ll>( pd(i+dx[0],j+dy[0]) , pd(i+dx[1],j+dy[1]) );

}

void solve(){
	
	 cin >> n >> m;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin >> grid[i][j];

	for(int i=0;i<1010;i++)
		for(int j=0;j<1010;j++)
			memo[i][j]=-INF;

	ll ans = pd(1,1);

	cout << "Case " << clk++ << ": " <<ans << endl;

}

int main()
{	
	fastcin;
	int t; cin >> t;
	while(t--)	solve();

}