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

vector<ll> v;
matrix base;

matrix operator*(matrix& a, matrix& b){

	int ra = a.size();
	int ca = a[0].size();

	int rb = b.size();
	int cb = b[0].size();

	matrix ans;
	ans.resize(ra);
	fr(i,ra)	ans[i].resize(cb);

	fr(i,ra){
		fr(j,cb){

			ll val = 0;
			fr(k,ca){
				val+=a[i][k]*b[k][j];
				val%=MOD;
			}
			ans[i][j]=val;

		}
	}

	return ans;

}


matrix gen_id(int n){
	matrix aux;
	aux.resize(n);
	fr(i,n){
		aux[i].resize(n);
		aux[i][i]=1;
	}
	return aux;
}

matrix fastxp(matrix& a, ll exp){

	matrix ans = gen_id(a.size());

	while(exp){

		if(exp%2)	ans=ans*a;
		a=a*a;
		exp/=2ll;

	}

	return ans;

}


int main(){
    
	fastio;

	int n;
	ll k;
	cin >> n >> k;

	fr(i,n){
		ll x; cin >> x;
		v.pb(x);
	}	

	base.resize(n);
	fr(i,n)	base[i].resize(n);

	fr(i,n){
		fr(j,n){
			ll aux = v[i]^v[j];
			int val = __builtin_popcountll(aux);
			if(val%3==0)	base[i][j]=base[j][i]=1;
		}
	}

	matrix aux = fastxp(base,k-1);

	matrix ans;
	ans.resize(n);
	fr(i,n)	ans[i].resize(1);

	fr(i,n)	ans[i][0] = 1;

	matrix ultima = aux*ans;

	ll val = 0;
	fr(i,n){
		val=(val+ultima[i][0])%MOD;
	}

	cout << val << endl;


}

