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
const int MOD = 1e9+7;

int main(){

	fastio;

	map<ll,ll> tem,vis;

	int n;
	cin >> n;

	vector<ll> v;
	
	v.pb(0);
	tem[0]++;
	
	ll sum=0;
	
	fr(i,n){
	
		ll a;
		cin >> a;
		a*=2ll;
	
		sum+=a;
		if(i!=n-1){
			v.pb(sum);
			tem[sum]++;
		}

	}
	
	vector<pll> caras;

	for(auto x : v){
		ll target = x+sum/2ll;
		target%=sum;
		if(tem[x] && tem[target]){
			caras.pb({x,target});
			tem[x]--;
			tem[target]--;
		}
	}

	if(caras.size()>=2)
		puts("Y");
	else
		puts("N");

}
