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
typedef pair<double, double> point;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

ll a,b,c;

point intersect_vertical(point x){
	return {x.fst,(-c-a*x.fst)/b};
}

point intersect_horizontal(point x){
	return {(-c -b*x.snd)/a,x.snd};
}

double dist(point x, point y){

	double ans = (x.fst-y.fst)*(x.fst-y.fst)+(x.snd-y.snd)*(x.snd-y.snd);
	ans=sqrt(ans);

	return ans;

}

int main(){

	fastio;


	ll x1,y1,x2,y2;

	cin >> a >> b >> c >> x1 >> y1 >> x2 >> y2;

	cout << setprecision(10) << fixed;

	double ans = (double)( abs<ll>(x1-x2) + abs<ll>(y1-y2) );

	if(a==0 || b==0){
		cout << ans << endl;
		return 0;
	}

	point a = {(double)x1,(double)y1};
	point b = {(double)x2,(double)y2};

	point a1 = intersect_vertical(a);
	point a2 = intersect_horizontal(a);

	point b1 = intersect_vertical(b);
	point b2 = intersect_horizontal(b);

	ans = min<double>(ans, dist(a,a1)+dist(a1,b1)+dist(b1,b) );
	ans = min<double>(ans, dist(a,a1)+dist(a1,b2)+dist(b2,b) );
	ans = min<double>(ans, dist(a,a2)+dist(a2,b1)+dist(b1,b) );
	ans = min<double>(ans, dist(a,a2)+dist(a2,b2)+dist(b2,b) );


	cout << ans << endl;

}