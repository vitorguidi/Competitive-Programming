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
const int mod = 1000000009;
typedef vector< vector<ll> > matrix;

int n,m,k;

matrix base = { {1,1,1},{1,0,0},{0,1,0} };
matrix ini = {{2},{1},{0}};

matrix operator*(matrix a, matrix b){

	int a1 = a.size(); int a2 = a[0].size();
	int b1 = b.size(); int b2 = b[0].size();

	matrix aux;
	aux.resize(a1);

	fr(i,a1)
		aux[i].resize(b2);

	fr(i,a1){
		fr(j,b2){
			aux[i][j]=0;
			fr(k,a2){
				aux[i][j]+= a[i][k]  * b[k][j];
				aux[i][j]=aux[i][j]%mod;
			}
		}
	}

	return aux;

}

matrix id(int tam){
	matrix ans;
	ans.resize(tam);
	fr(i,tam){
		ans[i].resize(tam);
		ans[i][i]=1;
	}
	return ans;
}

matrix fastxp(matrix a, ll exp){

	matrix ans = id(3);

	while(exp>0){
		if(exp%2==1)
			ans=ans*a;
		a=a*a;
		exp=exp/2;
	}

	return ans;

}

int main(){

	ll n;

	while(cin >> n){

		if(!n)
			break;

		if(n==1){
			cout << 0 << endl;
			continue;
		}
		else if(n==2){
			cout << 1 << endl;
			continue;
		}
		else if(n==3){
			cout << 2 << endl;
			continue;
		}

		matrix aux = fastxp(base,n-3);

		matrix ans = aux*ini;

		// fr(i,ans.size()){
		// 	fr(j,ans[0].size()){
		// 		cout << ans[i][j] << " ";
		// 	}
		// 	gnl;
		// }

		cout << ans[0][0] << endl;

		
	}

}