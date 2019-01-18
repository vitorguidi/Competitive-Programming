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
typedef vector< vector<ll> > matrix;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e6;

ll n,k,l;

matrix operator* (matrix a,matrix b){
	int c,d,e;
	c = a.size();
	d = b[0].size();
	e = b.size();

	matrix ans;
	ans.resize(c);
	fr(i,c) ans[i].resize(d);

	fr(i,c){
		fr(j,d){
			ans[i][j] = 0;
			fr(k,c){
				ans[i][j] += (a[i][k]%MOD)*(b[k][j]%MOD);
				ans[i][j] = ans[i][j]%MOD;
			}
		}
	}

	return ans;

}

matrix fast(matrix a,ll exp){
	if(exp == 1) return a;
	matrix ans = fast(a,exp/2);
	ans = ans*ans;
	if(exp%2) ans = ans*a;
	return ans;
}

int ctd(ll k){
	int ct = 0;
	if(k == 0) return 1;
	while(k > 0){
		ct++;
		k = k/10;
	}

	return ct;
}



void imprime (ll k){

	int aux = ctd(k);
	fr(i,6 - aux) cout << '0';
	cout << k << endl;

}


int main(){

	fastio;
	cin >> n >> k >> l;

	k %= MOD;
	l %= MOD;
	n = n/5;

	if (n== 1){
		imprime(k);
		return 0;
	}

	if(n==2){
		imprime((k*k + l)%MOD);
		return 0;
	}

	matrix z;
	z.resize(2);
	fr(i,2) z[i].resize(1);

	matrix f;

	f.resize(2);
	fr(i,2) f[i].resize(2);

	z[1][0] = k;
	z[0][0] = ((k*k + l)%MOD);

	f[0][0] = k;
	f[0][1] = l;
	f[1][0] = 1;
	f[1][1] = 0;

	matrix aux = fast(f,n-2);
	
	matrix ans = aux*z;
	//cout << ans[0][0] << ' '<<ans[1][0] << endl;

	imprime(ans[0][0]);


}
