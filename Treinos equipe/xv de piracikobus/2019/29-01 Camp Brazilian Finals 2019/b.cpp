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

int grundy[115][115];

int mex(set<int>& x){

	for(int i=0;i<10100;i++)
		if(x.find(i)==x.end())
			return i;

}

bool valid(int x, int y){
	return x>=0 && y>=0;
}

int main(){

	fastio;

	fr(i,110){
		grundy[i][i]=INF;
		grundy[0][i]=INF;
		grundy[i][0]=INF;
	}

	int n; cin >> n;

	for(int i=1;i<110;i++){
		for(int j=1;j<110;j++){

			if(grundy[i][j]==INF)	continue;

			set<int> aux;

			frr(k,120){
				if(valid(i-k,j-k))	aux.insert(grundy[i-k][j-k]);;
				if(valid(i-k,j))	aux.insert(grundy[i-k][j]);
				if(valid(i,j-k))	aux.insert(grundy[i][j-k]);
			}

			grundy[i][j]=mex(aux);

		}
	}


	int ans = 0;

	frr(i,n){

		int x,y;
		cin >> x >> y;

		if(x==y || !y || !x){
			puts("Y");
			return 0;
		}

		ans^=grundy[x][y];

	}

	// fr(i,10){
	// 	fr(j,10){
	// 		if(grundy[i][j]==INF)	grundy[i][j]=-1;
	// 		cout << grundy[i][j] << " ";
	// 	}
	// 	gnl;
	// }

	if(ans)	puts("Y");
	else	puts("N");

}
