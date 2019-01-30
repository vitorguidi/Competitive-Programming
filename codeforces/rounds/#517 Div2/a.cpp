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

	ll n,m,k; cin >> n >> m >> k;

	ll x0=1,y0=1,x1=n,y1=m;

	ll ans = 0;

	while(x0<=x1 && y0<=y1 && k){
		ans+=(x1-x0+1)*2;
		ans+=(y1-y0+1-2)*2;
		x0+=2;y0+=2;
		x1-=2;y1-=2;
		k--;
	}

	cout << ans << endl;

}

