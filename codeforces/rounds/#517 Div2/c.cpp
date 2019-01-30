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

pii solve(int a, int b){

}

ll calc(ll x){

	ll ini=0;
	ll end = x;
	ll ans = 0;
	
	while(ini<=end){

		ll mid=(ini+end)/2ll;
		
		if(mid*(mid+1ll)<=2ll*(x)){
			ini=mid+1;
			ans=max(ans,mid);
		}

		else
			end=mid-1;
	}

	return ans;


}

ll acum[100100];

int main(){
    
	fastio;

	ll a,b; cin >> a >> b;

	ll n = calc(a+b);

	vi x,y;

	for(int i=n;i>0;i--){
		if(a>=i){
			x.pb(i);
			a-=i;
		}
		else{
			b-=i;
			y.pb(i);
		}
	}
	cout << x.size() << endl;
	for(auto k : x)
		cout << k << " ";
	gnl;
	cout << y.size() << endl;
	for(auto k : y)
		cout << k << " ";
	gnl;

}