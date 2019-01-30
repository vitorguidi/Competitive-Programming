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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

ll n,k;

ll solve(vector<pll>& x){

	sort(all(x));
	ll ans=0;

	while(x.size()){

		ll &amt = x.rbegin()->snd;
		ll &dist = x.rbegin()->fst;

		ll times = amt/k;
		amt%=k;

		ans+=2*times*dist;

		if(!amt){
			x.pop_back();
			continue;
		}

		ll sobra = k;
		ll tira = min(amt,k);

		ans+=2*dist;

		while(sobra && x.size()){

			ll &cara = x.rbegin()->snd;
			tira=min(cara,sobra);

			cara-=tira;
			sobra-=tira;

			if(!cara)
				x.pop_back();

		}

	}

	return ans;

}

int main(){

	cin >> n >> k;

	vector<pll> left,right;

	fr(i,n){
		ll x,w;
		cin >> x >> w;
		if(x>=0)
			right.pb({x,w});
		else
			left.pb({abs(x),w});
	}

	
	ll ans = solve(left)+solve(right);

	cout << ans << endl;

}