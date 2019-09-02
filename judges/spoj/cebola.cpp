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

int n;

struct point{

	ll x,y;
	point(){}
	point(ll a,ll b){x=a,y=b;}

	ll operator^(point p){return x*p.y-y*p.x;}
	point operator-(point p){return point(x-p.x,y-p.y);}

};

bool operator<(point a, point b){
	return mp(a.x,a.y)<mp(b.x,b.y);
}

ll ori(point from, point a, point b){
	return (a-from)^(b-from);
}

bool ccw(point from, point a, point b){
	return ori(from,a,b)>0;
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
		hull.pb(cur);
	}
	return hull;
}

vector<point> convexHull(vector<point>& v){
	
	if(v.size()<=3)
		return v;

	vector<point> l,u;
	sort(all(v)),u=getHull(v);
	
	reverse(all(v)), l=getHull(v);
	l.pop_back(),u.pop_back();
	
	for(auto x : l)
		u.pb(x);
	
	return u;

}


void go(int n){

	vector<point> v;

	fr(i,n){
		point p;
		cin >> p.x >> p.y;
		v.pb(p);
	}

	vector<point> hull;

	int ans = 0;

	while(!v.empty()){
		hull=convexHull(v);
		ll area = 0;
		fr(i,hull.size())
			area+=hull[i]^hull[(i+1)%n];
		int sz = hull.size();
		ans+=(area!=0);
		map<point,int> vis;
		for(auto x : hull)
			vis[x]=1;
		vector<point> aux;
		for(auto x : v)
			if(!vis[x])
				aux.pb(x);
		swap(v,aux);
	}

	// dbg(ans);

	cout << (ans%2==1 ? "Take this onion to the lab!" : "Do not take this onion to the lab!") << endl;

}

int main(){
 
 	while(scanf("%d",&n) && n)
 		go(n);
	
}