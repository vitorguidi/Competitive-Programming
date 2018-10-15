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
#define olar cout << "pira" << endl
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll; 

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int bit[200200];
int acum[200200];

ll fastxp(ll base, ll exp){

	ll ans = 1;

	while(exp){
		if(exp%2)
			ans*=base;
		base*=base;
		exp/=2;
		base%=MOD;
		ans%=MOD;
	}

	return ans;

}


int main(){

	fastio;

	int n,m;
	cin >> n >> m;
	
	string a,b;

	cin >> a;
	cin >> b;

	reverse(all(b));
	reverse(all(a));

	for(int i=0;i<m;i++)
		if(b[i]=='1')
			acum[i]++;
	
	for(int i=m-1;i>=0;i--)
		acum[i]+=acum[i+1];

	ll ans=0;
	for(int i=0;i<n;i++){
		if(i<m && a[i]=='1')
			ans=(ans+acum[i]*fastxp(2,i))%MOD;
	}

	cout << ans << endl;

}