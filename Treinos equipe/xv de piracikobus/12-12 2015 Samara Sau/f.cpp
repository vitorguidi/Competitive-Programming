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

ll ans[100100];

int main(){

	fastio;

	int n,m; cin >> n >> m;

	vector<vi> grid;

	grid.resize(n+2);
	
	fr(i,n+2)
		grid[i].resize(m+2);

	fr(i,n+2)
		grid[i][0]=grid[i][m+1]=1;
	fr(i,m+2)
		grid[0][i]=grid[n+1][i]=1;

	string s; getline(cin,s);

	frr(i,n){
		getline(cin,s);
		frr(j,m){
			if(s[j-1]=='+')
				grid[i][j]=1;
			else
				grid[i][j]=0;
		}
	}

	vector<vi> coldown,colup,rowleft,rowright;

	coldown.resize(m+2);
	colup.resize(m+2);

	rowleft.resize(n+2);
	rowright.resize(n+2);

	fr(i,n+2){
		rowleft[i].resize(m+2);
		rowright[i].resize(m+2);
	}

	fr(i,m+2){
		colup[i].resize(n+2);
		coldown[i].resize(n+2);
	}


	fr(i,m+2)
		colup[i][n+1]=coldown[i][n+1]=n+1;


	fr(i,n+2)
		rowleft[i][m+1]=rowright[i][m+1]=m+1;


	frr(i,n){	//calcula o rowleft
		frr(j,m){
			if(grid[i][j]==1)
				rowleft[i][j]=j;
			else
				rowleft[i][j]=rowleft[i][j-1];
		}	
	}

	frr(i,n){	//calcula rowright
		for(int j=m;j>0;j--){
			if(grid[i][j]==1)
				rowright[i][j]=j;
			else
				rowright[i][j]=rowright[i][j+1];
		}
	}

	frr(i,m){	//calcula colup
		frr(j,n){
			if(grid[j][i]==1)
				colup[i][j]=j;
			else
				colup[i][j]=colup[i][j-1];
		}
	}

	frr(i,m){	//calcula coldown
		for(int j=n;j>0;j--){
			if(grid[j][i]==1)
				coldown[i][j]=j;
			else
				coldown[i][j]=coldown[i][j+1];
		}	
	}	

	frr(i,n){
		frr(j,m){

			//int up = abs(colup[j][i]-i);
			//if(up)	ans[up]++;

			int down = abs(coldown[j][i]-i);
			if(down)	ans[down]++;
			
			//int left = abs(rowleft[i][j]-j);
			//if(left)	ans[left]++;
			
			int right = abs(rowright[i][j]-j);
			if(right)	ans[right]++;
			if(right && down) ans[1]--;

			//cout<<i <<' '<<j <<':' << up<<endl;

		}
	}

	//	frr(i,n){
	//	frr(j,m){
	//		cout << rowright[i][j] << " ";
	//	}
//	gnl;gnl;
//	}

	int len = max(m,n);

	for(int i = len;i>0;i--)
		ans[i]+=ans[i+1];

	frr(i,len)
		cout << ans[i] << " ";
	gnl;


}
