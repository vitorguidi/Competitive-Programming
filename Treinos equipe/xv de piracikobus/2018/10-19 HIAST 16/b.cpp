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
typedef vector<vector<ll>> matrix;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

matrix base = { {1,4,7},{2,5,8},{3,6,9} };
matrix id = {{1,0,0},{0,1,0},{0,0,1}};

matrix operator*(matrix a, matrix b){

	matrix aux;
	aux.resize(3);
	fr(i,3)
		aux[i].resize(3);

	fr(i,3){
		fr(j,3){
			ll ans = 0;
			fr(k,3){
				ans+=(a[i][k]*b[k][j]);
				ans%=MOD;
			}
			aux[i][j]=ans;
		}
	}

	return aux;

}

matrix fastxp(matrix base, ll exp){

	matrix ans = id;

	while(exp){

		if(exp%2)
			ans=ans*base;
		base=base*base;
		exp/=2;

	}

	return ans;

}


void solve(){

	ll n; cin >> n;

	matrix aux = fastxp(base,n-1);

	ll ans = 0;
	fr(i,3)
		fr(j,3){
			ans+=aux[i][j];
			ans%=MOD;
		}
	
	cout << ans << endl;
}

int main(){

	fastio;
	int t; cin >> t;
	while(t--)	solve();
}