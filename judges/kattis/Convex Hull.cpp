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

struct point{

	ll x,y;
	point(){}
	point(ll a, ll b){x=a,y=b;}

	ll operator^(point p){return x*p.y-y*p.x;}
	point operator-(point p){return point(x-p.x,y-p.y);}
	bool operator <(const point& p){return (x!=p.x ? x<p.x : y<p.y);}

};

ll ori(point from, point a, point b){
	return (a-from)^(b-from);
}

bool ccw(point from, point a, point b){
	return ori(from,a,b)>=0;
}

vector<point> getHull(vector<point>& v){

	vector<point> hull;

	for(int i=0;i<v.size();i++){
		int sz=hull.size();
		point cur = v[i];
		while(sz>=2 && ccw(hull[sz-2],hull[sz-1],cur)){
			sz--;
			hull.pop_back();
		}
		hull.push_back(cur);
	}

	return hull;

}

vector<point> convexHull(vector<point>& v){
	if(v.size()<=3)
		return v;
	sort(all(v));
	vector<point> lowerHull,upperHull;
	upperHull=getHull(v);
	reverse(all(v));
	lowerHull=getHull(v);
	lowerHull.pop_back();
	upperHull.pop_back();
	for(auto x : lowerHull)
		upperHull.pb(x);
	return upperHull;
}

void printa(vector<point>& v){
	cout << v.size() << endl;
		for(auto p : v)
			cout << p.x << " " << p.y << endl;
}

int main(){
 
	int n;
	while(scanf("%d",&n) && n){
		map<pii,int> vis;
		vector<point> v;
		frr(i,n){
			int x,y;
			cin >> x >> y;
			if(vis[{x,y}])
				continue;
			vis[{x,y}]=1;
			v.pb(point(x,y));
		}
		if(v.size()<=3){
			printa(v);
			continue;
		}
		vector<point> hull = convexHull(v);
		reverse(all(hull));
		printa(hull);
	}
}