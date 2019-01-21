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

int main(){

	fastio;
	double a,b,c,r;
	cin >> a >> b >> c >> r;
	double tc,tb,ta;
	cout.precision(15);
	tc = acos(-(c*c - a*a - b*b)/(2*a*b));
	tb = acos(-(b*b - a*a - c*c)/(2*a*c));
	ta = acos(-(a*a - b*b - c*c)/(2*b*c));

	double ar = 0.0;
	r *= r;
	
	
	ar += r*((1.0/tan(tc/2.0)) - (acos(-1) - tc)/2.0);
	
	ar += r*((1.0/tan(ta/2.0)) - (acos(-1) - ta)/2.0);
	
	ar += r*((1.0/tan(tb/2.0)) - (acos(-1) - tb)/2.0);
	double aux;

	

	aux = a*b*sin(tc)/2.0;


	cout << (aux - ar)/aux << endl;

}
