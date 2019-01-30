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

int n;

double x[50500];
double y[50500];

double calc(double val){

	double ans = 0;

	fr(i,n){
		double aux = sqrt( (x[i]-val)*(x[i]-val) + (y[i]*y[i]) );
		ans=max(aux,ans);
	}

	return ans;

}

void solve(){

	double a = -1e10;
	double b = 1e10;	

	fr(i,n)	cin >> x[i] >> y[i];

	fr(i,90){
		double k1 = a + (b-a)/3.0;
		double k2 = b - (b-a)/3.0;

		if(calc(k1)>calc(k2))	a=k1;
		else					b=k2;
	}

	cout << (a+b)/2.0 << " " << calc( (a+b)/2.0 ) << endl;


}

int main(){

	fastio;
	cout << setprecision(15) << fixed;
	while(true){
		cin >> n;
		if(!n)	break;
		solve();
	}

}