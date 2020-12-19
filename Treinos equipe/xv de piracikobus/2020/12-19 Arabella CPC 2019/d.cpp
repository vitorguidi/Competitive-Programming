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

int main(){

	fastio;

	int n,m;
	cin >> n >> m;

	vector<int> v;
	for(int i=0;i<n;i++) {
		int x; cin >> x;
		v.push_back(x);
	}

	ll v2 = 0;

	for(int i=0;i<m;i++) {
		ll x; cin >> x;
		v2 = __gcd(v2,x);
	}

	bool ans = true;

	for(int x : v) {
		if(x%v2 != v[0]%v2)	ans = false;
	}

	cout << (ans ? "Yes" : "No") << endl;

	return 0;

}
