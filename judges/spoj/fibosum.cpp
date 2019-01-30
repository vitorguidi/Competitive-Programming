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

matrix id= { {1,0,0},{0,1,0},{0,0,1} };
matrix t = { {1,1,1},{0,1,1},{0,1,0} };
matrix ini = { {1},{1},{0} };	


void print_matrix(matrix a){
	fr(i,a.size()){
		fr(j,a[0].size()){
			cout << a[i][j] << " ";
		}
		gnl;
	}
}

matrix operator*(matrix a, matrix b){

	int a1=a.size(),a2=a[0].size();
	int b1=b.size(),b2=b[0].size();

	matrix aux;
	aux.resize(a1);
	
	fr(i,a1)
		aux[i].resize(b2);

	fr(i,a1){
		fr(j,b2){
			aux[i][j]=0;
			fr(k,a2){
				aux[i][j] += a[i][k] * b[k][j];
				aux[i][j] = aux[i][j]%mod;
			}
		}
	}

	return aux;

}

matrix fastxp (matrix a, ll exp){

	matrix aux=id;

	while(exp>0){
		if(exp%2)
			aux=aux*a;
		a=a*a;
		exp = exp/2;
	}

	return aux;

}

ll fib(int x){

	if(x<=0)
		return 0;
	if(x==1)
		return 1;

	x-=1;

	matrix aux = fastxp(t,x);

	matrix ans = aux*ini;

	// print_matrix(aux);
	// gnl;

	return ans[0][0];

}

int main(){
	
	int t;
	cin>>t;
	
//	dbg(fib(5));



	while(t--){
		
		int n,m;
		cin>>n>>m;
	
		ll ans = ( fib(m)-fib(n-1) )%mod;
	
		if(ans<0)
			ans=ans+mod;
		
		cout << ans << endl;
	}

}