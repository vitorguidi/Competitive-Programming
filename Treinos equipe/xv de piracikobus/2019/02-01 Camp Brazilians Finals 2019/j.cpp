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

struct point{
	ll x;
	ll y;
};
struct reta{
	ll a,b,c;
};

typedef struct point point;
typedef struct reta reta;
int n;
point house,usp;

int main(){

	fastio;
	
	cin>> house.x >> house.y;
	cin >> usp.x >> usp.y;

	cin >> n;

	ll ans = 0;

	fr(i,n){

		reta r;
		cin >> r.a >> r.b >> r.c;

		int val1 = (r.a*usp.x+r.b*usp.y+r.c>0);
		int val2 = (r.a*house.x+r.b*house.y+r.c>0);

		if(val1^val2)	ans++;

	}

	cout << ans << endl;



}