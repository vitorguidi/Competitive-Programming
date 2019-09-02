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
const int MAXN=100100;
const int MAXM=1100100;

double pi = acos(-1);
struct point{
	ll x,y;
	point(){x=y=0;}
	point(ll a, ll b){x=a,y=b;}
	ll operator^(point p){return x*p.y-y*p.x;}
	point operator-(point p){return point(x-p.x,y-p.y);}
	
};
bool operator<(const point& a, const point& b){
	return make_pair(a.x,a.y)<make_pair(b.x,b.y);
}

ll ori(point from, point a, point b){
	return (a-from)^(b-from);
}

bool ccw(point from, point a, point b){
	return ori(from,a,b)>0;
}

vector<point> getHull(vector<point> v){

	vector<point> hull;
	point cur;

	for(int i=0;i<v.size();i++){
		point cur = v[i];
		int sz = hull.size();
		while(sz>=2 && ccw( hull[sz-2],hull[sz-1],cur) )
			hull.pop_back(),sz--;		
		hull.pb(v[i]);
	}

	return hull;

}

vector<point> convexHull(vector<point>& v){


	if(v.size()<=3)
		return v;

	vector<point> lowerHull,upperHull;

	upperHull = getHull(v);
	reverse(all(v));
	lowerHull = getHull(v);

	lowerHull.pop_back();
	upperHull.pop_back();

	for(auto x : lowerHull)
		upperHull.pb(x);

	return upperHull;


}

void printa(vector<point> v){
	cout << v.size() << endl;
	for(auto x : v)
		cout << x.x << " " << x.y << endl;
	gnl;
}

int main(){
 
	fastio;
	int n;
	int clk=0;

	cout << setprecision(2) << fixed;

	while(cin>>n){

		if(!n)	break;
	
		vector<point> v;
		fr(i,n){
			ll x,y;
			cin >> x >> y;
			v.pb(point(x,y));
		}

		// printa(v);

		ll area = 0;

		fr(i,n)
			area+= v[(i+1)%n]^v[i];
		area=abs(area);

		sort(all(v));
		vector<point> hull = convexHull(v);
		reverse(all(hull));

		ll areaHull=0;
		fr(i,hull.size())
			areaHull+= hull[(i+1)%hull.size()]^hull[i];

		areaHull=abs(areaHull);

		// dbg(area);
		// dbg(areaHull);

		ll ans = areaHull;
		ans-=area;
		ans*=100ll;

		double out = double(ans)/double(areaHull);

		 // printa(hull);
		
		cout << "Tile #" << ++clk << endl;
		cout << "Wasted Space = " << out << " %" <<endl << endl;

	}	
}