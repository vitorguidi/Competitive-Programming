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

ll pg_sum(ll x){
	return (1<<x)-1ll;
}

ll pa_sum(ll x){
	return (x*(x+1ll))/2ll;
}

int main(){

	fastio;

	int t; cin >> t;
	while(t--){

		int x; cin >> x;
		ll aux = 31-__builtin_clz(x);
		aux++;
		ll sum = pa_sum(x)-2*pg_sum(aux);
		cout << sum << endl;
	}
	
}