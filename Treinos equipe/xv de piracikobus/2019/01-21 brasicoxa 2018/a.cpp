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
//#define ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) fastio

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
typedef vector<pll> vll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

int main(){

	//fastio;
	string s;
	cin >> s;

	string aux;

	for(auto x : s)
		if(x!='.')
			aux.pb(x);

	ll ans = 0;
	ll base =1;

	reverse(all(aux));

	for(auto x : aux){
		ans+=(x-'0')*base;
		base*=10;
	}

	int g = __gcd(36000ll,ans);
	cout << 36000/g << endl;

}