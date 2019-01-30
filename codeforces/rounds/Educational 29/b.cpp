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

ll v[300];
int n;

ll solve(vector<ll> x){

	ll ans = 0;
	int len = x.size();
	for(int i=0;i<len/2;i++)
		ans+=abs<ll>(x[2*i]-x[2*i+1]);

	return ans;

}

int main(){
    
	fastio;

	cin >> n;

	n*=2;

	frr(i,n)	cin >> v[i];

	sort(v+1,v+n+1);

	ll ans = llINF;

	frr(i,n){
		frr(j,n){

			if(i==j)	continue;
		
			ll aux = 0;

			vector<ll> x;

			frr(k,n)
				if(k!=i && k!=j)
					x.pb(v[k]);

			aux=solve(x);

			ans=min<ll>(ans,aux);

		}
	}

	cout << ans << endl;
}

