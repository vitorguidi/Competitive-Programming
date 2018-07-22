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

vector<string> lista = {"ABA","ACA","BCB","BAB","CAC","CBC","ABC","ACB","BAC","BCA","CAB","CBA"};
matrix t,ini;

bool comp(int a, int b){

	string x=lista[a],y=lista[b];

	if(x[0]==y[0] || x[1]==y[1] || x[2]==y[2])
		return false;
	return true;
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
				aux[i][j]+=a[i][k] * b[k][j];
				aux[i][j]=aux[i][j]%mod;
			}
		}
	}

	return aux;

}

matrix gen_id(){
	matrix aux;
	aux.resize(12);
	fr(i,12){
		aux[i].resize(12);
		aux[i][i]=1;
	}
	return aux;
}

matrix fastxp(matrix a, ll exp){

	matrix aux = gen_id();
	while(exp>0){
		if(exp%2)
			aux=aux*a;
		a=a*a;
		exp=exp/2;
	}
	return aux;

}

void print_matrix(matrix x){
	fr(i,x.size()){
		fr(j,x[i].size()){
			cout << x[i][j] << " ";
		}
		gnl;
	}
}

int main(){

	ll n; cin >> n;

	if(n==1){
		cout << 12 << endl;
		return 0;
	}

	t.resize(12);
	fr(i,12)
		t[i].resize(12);

	fr(i,12){
		fr(j,12){
			if(comp(i,j))
				t[i][j]=t[j][i]=1;
		}
	}

	fr(i,12){
		int lol=0;
		fr(j,12){
			if(t[i][j])
				lol++;
		}		
		ini.pb({lol});
	}

	matrix aux = fastxp(t,n-2);
	matrix ans = aux*ini;
	ll xdd = 0;
	fr(i,12){
		xdd+=ans[i][0];
		xdd=xdd%mod;
	}

	cout << xdd << endl;


}