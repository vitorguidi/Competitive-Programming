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

ll calc(ll n){
	return ((n)*(n-1))/2ll;
}

ll solve(ll v, ll e){

	ll ini=0,end=v;
	ll ans = 0;

	while(ini<=end){

		ll mid = (ini+end)/2;

		if( calc(mid) <=e ){
			ans=max(ans,mid);
			ini=mid+1;
		}
		else
			end=mid-1;

	}

	return ans;

}

int main(){
    
	fastio;

	ll n,m; cin >> n >> m;

	ll minans,maxans;

	minans=2ll*m;
	minans = (minans>=n ? 0 : n-minans);


	ll aux;
	while(m){
		aux = solve(n,m);

		ll amt = calc(aux);
		
		if(m>amt){
			n-=min<ll>(n,aux+1ll);
			m=0;
		}
		else{
			n-=min<ll>(n,aux);
			m=0;
		}
	}

	cout << minans << " " << n << endl;


}

