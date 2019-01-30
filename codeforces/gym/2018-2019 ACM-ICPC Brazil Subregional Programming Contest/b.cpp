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
const ll MOD = 998244353;

int grundy[110][110];


bool valid(int x,int y){
	return x>0 && y>0;
}

void printa(){

	fr(i,8){
		fr(j,8){
			if(i==0 || j==0 || i==j)
				cout << "X" << " ";
			else
				cout << grundy[i][j] << " ";
		}
		gnl;
	}

}

int main(){

	for(int i=0;i<=100;i++)
		grundy[i][0]=grundy[0][i]=grundy[i][i]=INF;

	for(int i=1;i<=100;i++){
		for(int j=1;j<=100;j++){

			set<int> mex;

			if(i==j)	continue;

			for(int k=0;k<i;k++)
				mex.insert(grundy[k][j]);

			for(int k=0;k<j;k++)
				mex.insert(grundy[i][k]);

			for(int k=1;k<=100;k++)
				if(valid(i-k,j-k))
					mex.insert(grundy[i-k][j-k]);
	
			int cnt=0;
			
			while(mex.find(cnt)!=mex.end())
				cnt++;

			grundy[i][j]=cnt;
	
		}	
	}


	int n; cin >> n;

	int ans=0;

	fr(i,n){
		
		int x,y; cin >> x >> y;
		
		if(x==y || x==0 || y==0){
			puts("Y");
			return 0;
		}

		ans^=grundy[x][y];
	
	}

	// dbg(ans);

	if(!ans)
		puts("N");
	else
		puts("Y");

}