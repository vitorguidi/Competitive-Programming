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

double xm,ym;

struct point{
	double x,y;
	point(){}
	point(double a, double b){x=a;y=b;}
	point operator-(point b){return {x-b.x,y-b.y};}
	point operator+(point b){return {x+b.x,y+b.y};}
	double operator^(point b){return x*b.y-y*b.x;}
	double operator*(point b){return x*b.x+y*b.y;}
	double operator~(){return hypot(x,y);}
};
struct segment{
	point p,q;
	segment(){}
	segment(point a,point b){a=p;b=q;}
};
struct line{
	double a,b,c;
	line(){}
	line(point p,point q){
		a=q.y-p.y;
		b=p.x-q.x;
		c=-a*p.x-b*p.y;
	}
	point intersect(line l){
		double disc = point(a,b)^point(l.a,l.b);		
		double x = point(-c,b)^point(-l.c,l.b);
		x/=double(disc);
		double y = point(a,-c)^point(l.a,-l.c);
		y/=double(disc);
		return point(x,y);
	}
};

void solve(){

	int n; cin >> n;

	double dist = 1e18;
	point ans;
	point m = point(xm,ym);

	vector<point> v;

	fr(i,n+1){
		ll x,y; cin >> x >> y;
		v.pb(point(x,y));
	}

	fr(i,n){
		point p=v[i];
		point q=v[i+1];
		segment s = segment(p,q);

		if( (m-p)*(q-p)<0 || (m-q)*(p-q)<0 ){
			double d1 = ~(m-p);
			if(d1<dist){
				dist=d1;
				ans={p.x,p.y};
			}
			double d2 = ~(m-q);
			if(d2<dist){
				dist=d2;
				ans={q.x,q.y};
			}
			continue;
		}

		point ort = p-q;
		ort=point(-ort.y,ort.x);

		point outro = m+ort;

		line l = line(m,outro);
		line r = line(p,q);

		point lol = l.intersect(r);	

		double nd = hypot(lol.x-m.x,lol.y-m.y);

		if(nd<dist){
			dist=nd;
			ans=lol;
		}

	}

	cout << ans.x << endl << ans.y << endl;

}

int main(){

	fastio;
	cout << setprecision(4) << fixed;
	while(cin >> xm >> ym)	solve();

}