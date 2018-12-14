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

	cout << setprecision(15) << fixed;

	ll x1,y1,x2,y2;
	cin >> x1 >> y1 >> x2 >> y2;

	ll vx1,vy1,vx2,vy2;
	cin >> vx1 >> vy1 >> vx2 >> vy2;

	vx2-=vx1;
	vy2-=vy1;

	vx1=0;
	vy1=0;

	if(vx2==0 && vy2==0){

		double ans = sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );

		cout << (double)ans << endl;
		return 0;

	}

	if(vx2==0 && vy2){		//reta perpendicular

		ll dist = abs<ll>(x2-x1);

		if(y2<=y1 && vy2>=0){
			cout << (double)dist << endl;
			return 0;
		}
		if(y2>=y1 && vy2<=0){
			cout << (double)dist << endl;
			return 0;
		}

		double ans = sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );

		cout << (double)ans << endl;
		return 0;


	}

	if(vx2 && vy2==0){

		ll dist = abs<ll>(y1-y2);

		if(x1<=x2 && vx2<0){
			cout << (double)dist << endl;
			return 0;
		}		
		if(x1>=x2 && vx2>0){
			cout << (double)dist << endl;
			return 0;
		}

		double ans = sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );

		cout << ans << endl;
		return 0;

	}

	double m = (double)vy2/(double)vx2;
	double m2 = -1.0/m;

	double c = (double)y2 - m*(double)x2;
	double c2 = (double)y1 - m2*(double)x1;

	double x = (c2-c)/(m-m2);
	double y = m*x + c;

	double t = (x-x2)/vx2;

	if(t<0){
		double ans = sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
 
		cout << ans << endl;
		return 0;
	}

	else{

		double ans = sqrt( (x1-x)*(x1-x) + (y1-y)*(y1-y) );
		cout << ans << endl;
		return 0;

	}

}