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
const ll MOD = 1e9+7;

ll n;

ll euclid(ll a, ll b, ll& x, ll& y){

	if(b==0){
		x=1;y=0;
		return a; 
	}

	ll x1,y1;

	ll d = euclid(b,a%b,x1,y1);

	x = y1;
	y = x1 - (a/b)*y1;

	return d;

}

void solve(){

	ll c1,n1,c2,n2;

	cin >> c1 >> n1 >> c2 >> n2;

	ll aux = __gcd(n1,n2);

	if(n%aux!=0){
		cout << "failed" << endl;
		return;
	}

	ll a = n1/aux;
	ll b = n2/aux;
	ll c = n/aux;

	ll x,y;

	euclid(a,b,x,y);

	x*=c;
	y*=c;

	ll t2 = floor((1.0*y)/(1.0*a));
	ll t1 = ceil((-1.0*x)/(b*1.0));

	if(t2<t1){
		cout << "failed" << endl;
		return;
	}

	ll cost = (x+t1*b)*c1 + (y-t1*a)*c2;
	
	ll bx = x+t1*b;
	ll by = y-t1*a;

	ll nx= x+t2*b;
	ll ny= y-t2*a;
	
	if( nx>=0 && ny>=0 && nx*c1+ny*c2<cost  ){
		bx=nx;
		by=ny;
	}

	if(bx>=0 && by>=0)
		cout << bx << " " << by << endl;
	else
		cout << "failed" << endl;
}

int main(){

	fastio;

	while(true){
		cin >> n;
		if(!n)	break;
		solve();
	}

}