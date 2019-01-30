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

ll n,a,b;
vector<ll> v;

ll solve(ll x){

	ll aux1 = max(a,b);
	ll aux2 = min(a,b);

	a=aux1;
	b=aux2;

	ll ans = 0;

	for(ll i=x;i>0;i--){

		ll teto = (i+1ll)/2ll;
		ll piso = i/2ll;

		if(a>=teto && b>=piso){
			
			a-=teto;
			b-=piso;
			ans = teto+piso;
			x-=teto+piso;
			
			if(teto==piso){
				ll amt = min<ll>((x+1ll)/2ll,a);
				a-=amt;
				ans+=amt;
			}
			else{
				x--;
				ll amt = min<ll>((x+1)/2ll,a);
				a-=amt;
				ans+=amt;
			}

			break;	

		}

	}

	return ans;

}

int main(){
    
	fastio;

	cin >> n >> a >> b;

	ll at = 0;

	string s; cin >> s;
	s.pb('*');
	
	ll ans = 0;

	fr(i,n+1){	
		if(s[i]=='*'){
			if(at)
				v.pb(at);
			at=0;
		}
		else
			at++;
	}

	sort(all(v));
	reverse(all(v));

	for(auto x : v)
		ans+=solve(x);
	
	cout << ans << endl;


}