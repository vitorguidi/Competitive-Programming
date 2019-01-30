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
typedef vector<ll> vl;
typedef tuple<ll,ll,ll> edge;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;	

ll cost[10100],hgt[10100];
int n;

ll calc(ll x){
	ll sum = 0;
	for(int i =1;i<=n;i++)
		sum+=cost[i]*abs(hgt[i]-x);
	return sum;	
}

void solve(){

	cin >> n;

	frr(i,n)	cin >> hgt[i];
	frr(i,n)	cin >> cost[i];

	ll a = 0;
	ll b = 10000;

	while(b-a>3){

		ll k1 =(2*a+b)/3;
		ll k2=(2*b+a)/3;

		if(calc(k1)>calc(k2))	
			a=k1;
		else if(calc(k2)>calc(k1))
			b=k2;
		else	
			a=b;

	}

	ll ans = llINF;

	for(int i=a;i<=b;i++)
		ans=min<ll>(ans,calc(i));

	cout << ans << endl;

}

int main(){

	fastio;

	int t; cin >> t;
	while(t--)	solve();
}