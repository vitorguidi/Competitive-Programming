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

ll grundy(ll x){
	if(x==1 || x==0)	return 0;
	if(x%2==0)	return x/2ll;
	return grundy(x/2);
}

int main(){

	int t; cin >> t;
	while(t--){

		int n; cin >> n;
		ll ans = 0;

		fr(i,n){
			ll x; cin >> x;
			ans^=grundy(x);
		}

		if(ans==0)
			puts("NO");
		else
			puts("YES");

	}

}