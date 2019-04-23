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
typedef pair<double,double> point;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;

const double pi = acos(-1);

int d[5];
int ang[5];

point p[10];

pair<double,double> v[10];

point operator+(point a, point b){
	return {a.fst+b.fst,a.snd+b.snd};
}

point operator-(point a, point b){
	return {a.fst-b.fst,a.snd-b.snd};
}

int main(){

	fastio;
	
	cout << setprecision(9) << fixed;
	
	int n; cin >> n;
	
	double g; cin >> g;
	
	frr(i,n)	cin >> d[i] >> ang[i];
	
	v[0]={0,0};
	
	frr(i,n){
		
		double dx = d[i]*sin(ang[i]*pi/180.0);
		double dy = d[i]*cos(ang[i]*pi/180.0);
		
		
		p[i] = p[i-1] - mp(dx,dy);
	
	}
		
	frr(i,n){
		
		point last = p[n];
		point now = p[i-1];
		
		point delta = now - last;
		
		double dh = abs(delta.snd);
		
		cout << sqrt(2.0*g*dh) << endl;	
	
	}
	
	gnl;

}