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

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

ll sumpa(ll n,ll a0,ll r){

	ll an = a0 + (n-1ll)*r;
	return (n*(a0+an))/2ll;

}

ll query(int x){

	ll neg = (x+1)/2;
	ll pos = x/2;

	return sumpa(neg,-1,-2) + sumpa(pos,2,2);

}


int main(){
    
	fastio;

	int q; cin >> q;

	while(q--){

		ll l,r; cin >> l >> r;

		cout << query(r) - query(l-1) << endl;

	}

}

