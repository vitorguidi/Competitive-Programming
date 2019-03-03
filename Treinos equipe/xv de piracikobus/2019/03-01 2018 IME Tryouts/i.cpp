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

	ll x,y;

	point(){}
	point(ll a, ll b){x=a;y=b;}

	ll operator^(point p){return x*p.y-y*p.x;}
	point operator-(point p){return {x-p.x,y-p.y};}

};

bool inside(point p,vector<point>& v){

	bool pos=false;
	bool neg=false;

	int n = v.size();

	for(int i=0;i<n;i++){
		ll dot = (v[i]-p)^(v[(i+1)%n]-p);
		if(dot>0)	pos=true;
		if(dot<0)	neg=true;
	}

	return !(neg&pos);

}


vector<point> sheena,rose,maria;

int main(){

	fastio;

	int s,r,m;
	cin >> s >> r >> m;

	fr(i,s){
		ll x,y;
		cin >> x >> y;
		sheena.pb(point(x,y));
	}

	fr(i,r){
		ll x,y;
		cin >> x >> y;
		rose.pb(point(x,y));
	}

	fr(i,m){
		ll x,y;
		cin >> x >> y;
		maria.pb(point(x,y));
	}

	int n; cin >> n;

	fr(i,n){
		
		int x,y;
		cin >> x>> y;
		point p = point(x,y);

		string ans = "Outside";

		if(inside(p,maria))	ans="Maria";
		if(inside(p,rose))	ans="Rose";
		if(inside(p,sheena))	ans = "Sheena";

		cout << ans << endl;

	}

}