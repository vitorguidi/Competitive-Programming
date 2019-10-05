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

#define endl "\n" 
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) 
 
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;
 
const int INF = 0x3f3f3f3f;

int main(){
	fastio;
	cout << setprecision(8)<<fixed;
	int n;
	cin >> n;
	while(n--){
		ll w,g,h,r;
		cin >> w >> g >> h >> r;
		if(g > h) swap(g,h);

		cout << sqrt(w*w + (h-g)*(h-g)) << ' ';
		g -= r;
		h -=r;
		//Olá, uma poesia: Batatinha quando nasce, espalha ramas pelo chão, ai meus deus, guidi é gatão
		double ini = 0;
		double end = w;
		
		while(abs(ini-end)>1e-7){

			double delta = end-ini;
			delta/=3.0;

			double a = ini + delta;
			double b = end - delta;

			double fa = sqrt(a*a + g*g) + sqrt( (w-a)*(w-a) + h*h );
			double fb = sqrt(b*b + g*g) + sqrt( (w-b)*(w-b) + h*h );
			
			if(fa<fb)	end=b;
			else		ini=a;

		}
		// for(double x=0;x<=w;x+=50){

		// 	double distx = sqrt(x*x + g*g) + sqrt( (w-x)*(w-x) + h*h );
		// 	cout << distx << " ";

		// }
		// gnl;gnl;
		//dbg(ini);
		cout << sqrt(ini*ini + g*g) + sqrt( (w-ini)*(w-ini) + h*h ) << endl;
	}
 
}