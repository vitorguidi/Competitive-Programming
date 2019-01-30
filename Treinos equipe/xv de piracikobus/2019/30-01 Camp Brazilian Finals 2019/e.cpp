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

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

struct matrix{
	ll x1,x2,x3,x4;
	matrix(){
		x1=1;
		x4=1;
		x2=0;
		x3=0;
	}
};


matrix operator*(matrix& a, matrix& b){
	
	matrix ans = matrix();
	
	ans.x1 = a.x1*b.x1 + a.x2*b.x3;
	ans.x1%=MOD;
	
	ans.x2 = a.x1*b.x2 + a.x2*b.x4;
	ans.x2%=MOD;
	
	ans.x3 = a.x3*b.x1 + a.x4*b.x3;
	ans.x3%=MOD;
	
	ans.x4 = a.x3*b.x2 + a.x4*b.x4;
	ans.x4%=MOD;
	
	return ans; 

}

matrix fastxp(matrix& base, ll exp){

	matrix ans = matrix();

	while(exp){
		if(exp%2)
			ans=ans*base;
		base=base*base;
		exp/=2;
	}

	return ans;

}

int main(){

	fastio;

	matrix base;
	base.x1=3;
	base.x2=1;
	base.x3=1;
	base.x4=3;

	ll n; cin >> n;

	matrix aux = fastxp(base,n);

	cout << aux.x1 << endl;

}
