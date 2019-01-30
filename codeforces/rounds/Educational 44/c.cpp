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

int main(){
    
	fastio;

	ll n,k,l;
	cin >> n >> k >> l;

	vector<ll> v;
	multiset<ll> s;

	ll mn = INF;

	for(ll i=0;i<n*k;i++){
		ll x; cin >> x;
		mn=min<ll>(mn,x);
		v.pb(x);
	}

	for(auto x : v)
		if(x<=mn+l)
			s.insert(x);

	ll len = s.size();

	if(len<n){
		cout << 0 << endl;
		return 0;
	}

	ll ans = 0;

	while(!s.empty()){

		ans+=*(s.begin());
				
		ll tira = len -(n-1);
		fr(i,min<ll>(k,tira)){
			len--;
			s.erase(s.begin());
		}

		n--;
	
	}


	cout << ans << endl;


}

