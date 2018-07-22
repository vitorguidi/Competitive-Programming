#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;

const int mod = 1000000007;
typedef vector< vector<ll> > matrix;

int m,n;

matrix operator*(matrix& a, matrix& b){

	matrix aux; aux.resize(m);
	fr(i,m)
		aux[i].resize(m);

	fr(i,m){
		fr(j,m){

			aux[i][j]=0ll;
			fr(k,m){
				aux[i][j]+=a[i][k] * b[k][j];
				aux[i][j]=aux[i][j]%mod;
			}

		}
	}

	return aux;

}

matrix id(int x){

	matrix v;
	v.resize(x);
	fr(i,x){
		v[i].resize(x);
		v[i][i]=1ll;
	}

	return v;

}

matrix exp(matrix& a, int x){

	matrix ans = id(m);

	while(x>0){

		if(x%2==1)
			ans=ans*a;
		a=a*a;
		x=x/2;
	}

	return ans;

}

int main(){

	int t; cin >> t;
	
	while(t--){

		cin >> m >> n;

		matrix v;
		v.resize(m);
		fr(i,m)
			v[i].resize(m);
		
		fr(i,m)
			fr(j,m)	cin >> v[i][j];

		matrix ans = exp(v,n);

		fr(i,m){
			fr(j,m){
				cout << ans[i][j] << " ";
			}
			gnl;
		}
	
	}
	
}