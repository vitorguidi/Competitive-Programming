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
const ll mod = 1e7;

ll n,k,l;

matrix operator*(matrix& a,matrix& b){

	matrix ans;
	
	int a1=a.size(),a2=a[0].size();
	int b1=b.size(),b2=b[0].size();

	ans.resize(a1);
	fr(i,a1)
		ans[i].resize(b2);

	fr(i,a1){
		fr(j,b2){
			ans[i][j]=0;
			fr(z,a2){
				ans[i][j]+=a[i][z]*b[z][j];
				ans[i][j]=ans[i][j]%mod;
			}
		}
	}

	return ans;

}

matrix gen_id(){
	matrix ans;
	ans.resize(2);
	fr(i,2){
		ans[i].resize(2);
		ans[i][i]=1;
	}
	return ans;
}

matrix fastxp(matrix a, ll exp){

	matrix ans = gen_id();
	while(exp>0){
		if(exp%2)
			ans=a*ans;
		a=a*a;
		exp=exp/2;
	}
	return ans;

}


int main(){

	while(cin >> n && cin >> k && cin >> l){

		n=n/5;
		k=k%mod;
		l=l%mod;
		matrix base = { {k,l},{1,0} };
		matrix ini = { {k},{1} };

		matrix ans = fastxp(base,n-1);
		ans = ans*ini;

		int lol = ans[0][0];
		string s;
		fr(i,6){
			int aux = lol%10;
			s.pb('0'+aux);
			lol=lol/10;
		}
		reverse(all(s));
		cout << s << endl;

	}

}