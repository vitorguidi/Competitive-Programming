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

int n,m;
char mat[1001][1001];
int pd[1001][1001];

int main(){

	fastio;

	cin >> n >> m;
	string s;
	getline(cin,s);
	fr(i,n){
		getline(cin,s);
		fr(j,m){
			mat[i][j] = s[j];
		}
	}

	fr(i,m){
		pd[n-1][i] = 1;
	}

	fr(i,n){
		pd[i][m-1] = 1;
	}

	for(int j = m- 2;j >=0 ; j--){
		for(int i = n -2; i>= 0; i--){
			if(mat[i][j] != mat[i][j+1]){
				pd[i][j] = 1;
			}
			else{
				int k = min(pd[i][j+1],pd[i+1][j]);
				if(mat[i+k][j+k] == mat[i+k][j+k-1]) pd[i][j] = k + 1;
				else pd[i][j] = k;
			}
		}
	}

	int ans= 1;

	for(int i =0; i < n; i++){
		for(int j = 0; j < m; j++){
			ans = max(ans,pd[i][j]);
		}
		//	gnl;
	}

	cout << ans*ans << endl;

}
