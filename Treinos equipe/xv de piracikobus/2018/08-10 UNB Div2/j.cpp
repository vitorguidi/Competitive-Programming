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
typedef vector< vector<ll> > matrix;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;
const int mod = 1e9+7;

int n,m,k;
matrix adj; 	

matrix operator*(matrix a, matrix b){

	matrix aux;
	int len=a.size();
	aux.resize(len);
	fr(i,len)
		aux[i].resize(len);

	fr(i,n){
		fr(j,n){
			aux[i][j]=0;
			fr(k,n){
				aux[i][j]+=a[i][k]*b[k][j];
				aux[i][j]=aux[i][j]%mod;
			}
		}
	}	

	return aux;

}

matrix gen_id(int len){
	matrix aux;
	aux.resize(len);
	fr(i,len)
		aux[i].resize(len);
	fr(i,n)
		aux[i][i]=1;
	return aux;
}

matrix fastxp(matrix a, ll exp){

	matrix aux = gen_id(a.size());
	while(exp){
		if(exp%2)
			aux=aux*a;
		a=a*a;
		exp=exp/2;
	}
	return aux;

}

int main(){


	cin >> n >> m >> k;
	adj.resize(n);
	fr(i,n)
		adj[i].resize(n);

	fr(i,m){
		int x,y; cin >> x >> y;
		x--;y--;
		adj[x][y]++;
	}

	matrix aux = fastxp(adj,k);

	int cnt = 0;
	vi ans;
	fr(i,n){
		if(aux[i][0]){
			cnt++;
			ans.pb(i);
		}
	}

	cout << cnt << endl;
	fr(i,cnt)
		cout << ans[i]+1 << " ";
	gnl;

}