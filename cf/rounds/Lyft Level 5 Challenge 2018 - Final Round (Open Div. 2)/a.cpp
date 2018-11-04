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

	ll n; cin >> n;
	ll x,y; cin >> x >> y;

	ll dx1=abs<ll>(x-1ll);
	ll dy1=abs<ll>(y-1ll);

	ll d1 = dx1 + dy1 - min<ll>(dx1,dy1);

	ll dx2=abs<ll>(n-x);
	ll dy2=abs<ll>(n-y);

	ll d2 = dx2+dy2 - min<ll>(dx2,dy2);

	if(d1<=d2)
		cout << "White" << endl;
	else
		cout << "Black" << endl;

}

