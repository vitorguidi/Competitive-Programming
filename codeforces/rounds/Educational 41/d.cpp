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

struct point{
	ll x,y;
	point(){}
	point(ll a, ll b){x=a,y=b;}
	point operator-(point p){return{x-p.x,y-p.y};}
	ll operator^(point p){return x*p.y-y*p.x;}
};

struct line{
	ll a,b,c;
	line(){}
	line(point p, point q){
		a=q.y-p.y;
		b=p.x-q.x;
		c=-a*p.x-b*p.y;
		ll aux = __gcd(a,b);aux=__gcd(aux,c);
		a/=aux;b/=aux;c/=aux;
	}
	bool inside(point p){return p.x*a+p.y*b+c==0;}
};

vector<point> v;

bool check(line l){

	vector<point> sobra;

	for(auto x : v)
		if(!l.inside(x))	sobra.pb(x);

	if(sobra.size()<=2)	return true;

	point p = sobra[0];
	point q = sobra[1];

	line r = line(p,q);

	for(auto x : sobra)
		if(!r.inside(x))	return false;

	return true;

}

int main(){

	fastio;

	int n; cin >> n;


	fr(i,n){
		ll x,y; cin >> x >> y;
		v.pb(point(x,y));
	}

	if(n<=3){cout << "YES" << endl;return 0;}

	bool flag = false;

	flag|=check(line(v[0],v[1]));
	flag|=check(line(v[0],v[2]));
	flag|=check(line(v[1],v[2]));

	cout << (flag ? "YES" : "NO") << endl;
	

} 