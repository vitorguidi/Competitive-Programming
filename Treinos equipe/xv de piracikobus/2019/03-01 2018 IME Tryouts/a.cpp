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
int n;
int memo[4][7];


int main(){

	fastio;
	
	cin >> n;
	//ms(memo,0);

	memo[0][0] = 1;
	memo[0][3] = 1;
	memo[0][6] = 1;

	memo[1][1] = 1;
	memo[1][4] = 1;

	int j = 2;

	for(int i = 2;j<= n; j++){
		memo[i][0] = (memo[i-2][0] + memo[i-1][1])%(MOD) + memo[i-1][4];
		memo[i][1] = memo[i-1][0] + memo[i-1][6];
		memo[i][2] = memo[i-1][5];
		memo[i][3] = memo[i-1][4]; 
		memo[i][4] = memo[i-1][3] + memo[i-1][0];
		memo[i][5] = memo[i-1][2];
		memo[i][6] = memo[i-1][1];
		fr(k,7){
			memo[i][k] %= MOD;
		}

		fr(k,7){
			memo[0][k] = memo[1][k];
			memo[1][k] = memo[2][k];
		}
	}

	cout << memo[2][0] << endl;


}