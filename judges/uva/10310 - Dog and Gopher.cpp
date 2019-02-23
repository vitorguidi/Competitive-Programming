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
#define olar cout << "pira" << endl
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll; 

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int n;

struct point{
	ll x,y;

};
ll dist2(point p, point q){
	return (p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y);
}

void solve(){

	point gopher,dog;

	double x,y;

	cin >> x >> y;
	gopher.x = 1000.0*x;
	gopher.y = 1000.0*y;

	cin >> x >> y;
	dog.x = 1000.0*x;
	dog.y = 1000.0*y;

	vector<point> v;

	fr(i,n){
		point aux;
		cin >> x >> y;
		aux.x=1000.0*x;
		aux.y=1000.0*y;
		v.pb(aux);
	}

	fr(i,n){
		point p = v[i];
		ll distg = dist2(p,gopher);
		ll distd = dist2(p,dog);
		if(4ll*distg<=distd){
			cout << "The gopher can escape through the hole at (" << p.x/1000.0 << "," << p.y/1000.0 << ")." << endl;
			return;
		}
	}

	cout << "The gopher cannot escape." << endl;

}

int main(){

	fastio;
	cout << setprecision(3) << fixed;
	while(cin >> n)	solve();
	
}