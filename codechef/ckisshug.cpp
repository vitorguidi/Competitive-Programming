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
typedef vector<vector<ll>> matrix;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

matrix base_even = { {1,3},{0,2} };
matrix base_odd = { {1,4},{0,2} };

matrix operator*(matrix a, matrix b){

	matrix ans;
	ans.resize(2);
	fr(i,2)	ans[i].resize(2);

	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){

			ll aux = 0;

			for(int k=0;k<2;k++)
				aux=(aux+a[i][k]*b[k][j])%MOD;

			ans[i][j]=aux;
		}
	}

	return ans;

}

matrix fastxp(matrix base, ll exp){

	matrix ans = { {1,0},{0,1} };

	while(exp){
		if(exp%2)
			ans=base*ans;
		base=base*base;
		exp/=2;
	}

	return ans;

}

void solve(){

	int n; cin >> n;

	if(n%2){

		if(n==1){
			cout << 2 << endl;
			return;
		}


		int passo = (n-1)/2;

		matrix aux = fastxp(base_odd,passo);
		ll ans = 2ll*aux[0][0]+aux[0][1];
		ans%=MOD;
		cout << ans << endl;

	}
	else{
		
		int passo = (n)/2;
		matrix aux = fastxp(base_even,passo);
		ll ans = aux[0][0]+aux[0][1];
		ans%=MOD;
		cout << ans << endl;

	}

}

int main(){

	fastio;

	int t; cin >> t;
	while(t--)	solve();


}