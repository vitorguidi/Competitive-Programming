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

ll la,ra,ta,lb,rb,tb;
ll passo;

ll solve(ll k){


	ll left 	= 	lb + passo*k;
	ll right 	= 	rb + passo*k;

	left%=ta;
	right%=ta;

	if(right<left)
		right+=ta;

	ll x = max<ll>(la,left);
	ll y = min<ll>(ra,right);

	return max<ll>(0,y-x+1);

}

int main(){
    
	fastio;

	cin >> la >> ra >> ta >> lb >> rb >> tb;

	passo = __gcd(ta,tb);

	if(passo==1){
		cout << min<ll>( abs<ll>(ra-la+1ll) , abs<ll>(rb-lb+1ll) ) << endl;
		return 0;
	}

	if(ta<tb){
		swap(ta,tb);
		swap(la,lb);
		swap(ra,rb);
	}

	rb%=ta;
	lb%=ta;
	
	int k = ( abs<ll>(la+ta-lb) )/passo;

	int ans = 0;

	int ini = max<ll>(k-4,0);

	for(int i=ini;i<=k+4;i++)
		ans=max<ll>(ans,solve(i));

	k= ( abs<ll>(ra+ta-rb) )/passo;


	ini = max<ll>(k-4,0);

	for(int i=ini;i<=k+4;i++)
		ans=max<ll>(ans,solve(i));

	cout << ans << endl;
	

}

