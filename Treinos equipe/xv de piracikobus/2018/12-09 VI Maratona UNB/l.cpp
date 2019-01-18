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

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

ll m_quadrado(ll x){
	ll ini,fim,meio,best; 

	best=ini=0;
	fim=3000; 

	while(ini <= fim){
		meio=(fim+ini)/2; 
		if(meio*meio <= x){
			best=meio; 
			ini=meio+1;
		}
		else 
			fim=meio-1;
	} 
	return best;
}

void solve(){
	ll a,b,r; 
	cin>>a>>b>>r;

	ll tot,x,y;

	x=0;
	tot=4*r;

	for(y=1;y<r;y++){
		x+=m_quadrado(r*r-y*y); 
	}
//	dbg(x);
	tot+=4*x; 
	cout<<tot<<endl;

}

int main(){
	fastio;
	int t; 
	cin>>t; 
	while(t--) solve();
}
