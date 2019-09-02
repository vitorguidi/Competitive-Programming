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
	ll operator*(point p){return x*p.x+y*p.y;}
	double mod(){return sqrt( double(x*x+y*y) );}

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

bool cw(point from, point a, point b){
	return ori(from,a,b)<0;
}

double ans[300300];
double pi = acos(-1);

double handle(point a, point b){
	// cout << "estou em " << a.x << " " << a.y << endl;
	// cout << "quero chegar em " << b.x << " " << b.y << endl;
	point path = (b-a);
	double s = point(0,1)^path;
	double c = point(0,1)*path;

	double ans = (atan2(s,c));
	return min(abs(ans),pi/2.0);
}

int main(){
 
 	fastio;
 	vector<point> v;
 	int n; cin >> n;

 	fr(i,n){
 		point p;
 		cin >> p.x >> p.y;
 		v.pb(p);
 	}

 	ans[0]=ans[n-1]=pi/2.0;

 	vector<point> hull;
 	hull.pb(v[0]);

 	//cout << "vindo da esuqerda " << endl;
 	//gnl;
 	for(int i=1;i<n;i++){
 		int sz=hull.size();
 		point cur = v[i];
 		//cout << "estou no pto " << cur.x << " " << cur.y << endl;
 		while(hull.size()>=2 && ccw(hull[sz-2],hull[sz-1],cur)){
 			sz--;
 			hull.pop_back();
 		}
 		//cout << "bati no pto" << hull[sz-1].x << " " << hull[sz-1].y << endl;
 		ans[i]+=handle(cur,hull[sz-1]);
 		hull.pb(cur);
 		//gnl;
 	}

 	hull.clear();
 	hull.pb(v[n-1]);
	
	//cout << "vindo da direita " << endl;
	//gnl;
 	for(int i=n-2;i>=0;i--){
 		int sz=hull.size();
 		point cur = v[i];
 		//cout << "estou no pto" << cur.x << " " << cur.y << endl;
 		while(hull.size()>=2 && cw(hull[sz-2],hull[sz-1],cur)){
 			sz--;
 			hull.pop_back();
 		}
 		//cout << "bati no pto" << hull[sz-1].x << " " << hull[sz-1].y << endl;
 		ans[i]+=handle(cur,hull[sz-1]);
 		hull.pb(cur);
 		//gnl;
 	}

 	cout << setprecision(6) << fixed;

 	fr(i,n){
 		cout << ans[i]*12/pi << endl;
 	}
	
}