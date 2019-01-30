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
typedef vector< vector<bool> > mbool;
const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;
const ll mod = 1000000007;
matrix id = { {1,0},{0,1} };

matrix operator*(matrix& a, matrix& b){

	matrix ans;
	int len = a.size();

	ans.resize(len);
	fr(i,len)
		ans[i].resize(len);
	
	fr(i,len){
		fr(j,len){
			ans[i][j]=0;
			fr(k,len){
				ans[i][j]+=a[i][k]*b[k][j];
				ans[i][j]=ans[i][j]%mod;
			}
		}
	}

	return ans;

}

matrix fastxp(matrix& a, ll exp){

	matrix ans = id;
	while(exp>0){
		if(exp%2)
			ans=a*ans;
		a=a*a;
		exp=exp/2;
	}

	return ans;

}

int main(){

	ll a,b,n,x;
	cin >> a >> b >> n >> x;

	matrix t = { {a,1},{0,1} };
	matrix ini = { {x},{b} };
	
	matrix ans = fastxp(t,n);
	ans = ans*ini;
	cout << ans[0][0] << endl;

}
