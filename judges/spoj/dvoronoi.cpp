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

	int x,y,z;

	point(){
		x=y=z=0;
	}
	point(int a, int b,int c){
		x=a;y=b;z=c;
	}

	point operator-(point b){
		return {x-b.x,y-b.y,z-b.z};
	}
	int operator*(point b){
		return x*b.x+y*b.y+z*b.z;
	}
	point operator^(point b){
		return {y*b.z-z*b.y, z*b.x-x*b.z ,x*b.y-y*b.x };
	}

	double operator~(){
		return sqrt( x*x+y*y+z*z );
	}


};

void solve(){

	point a,b,c,d;

	int x,y,z;

	cin >> x >> y >> z;
	a=point(x,y,z);
	cin >> x >>y >> z;
	b=point(x,y,z);
	cin >> x >> y >> z;
	c=point(x,y,z);
	cin >> x >> y >> z;
	d=point(x,y,z);

	a=a-d;
	b=b-d;
	c=c-d;

	a=a^b;

	int ans = a*c;
	ans=abs(ans);

	double resp = double(ans)/6.0;
	cout << resp << endl;

}

int main(){

	fastio;
	cout << setprecision(6) << fixed;

	int t; cin >> t;
	while(t--)	solve();
	
}