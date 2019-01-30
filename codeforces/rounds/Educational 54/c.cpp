#include "bits/stdc++.h"
using namespace std;

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl

#define gnl cout << endl
#define olar cout << "olar" << endl

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

double conv(int x){
	return (double)x;
}

bool check(double a, double b, int d){
	
	if(a<0.0)
		return false;
	if(b<0.0)
		return false;

	if( abs<double>(a*b-conv(d)) > (double)1e-6 )
		return false;
	
	if( abs<double>(a+b-conv(d)) > (double)1e-6 )
		return false;
	
	return true;

}

int main(){

	cout << setprecision(10) << fixed;

	int t; cin >> t;
	while(t--){

		int d; cin >> d;

		if(d*d-2*d<0 || d*d-4*d<0){
			puts("N");
			continue;
		}

		int aux = d*d-4*d;

		double delta = conv(aux);

		double b1 = conv(d) - sqrt(conv(delta));
		b1/=(double)2.0;

		double b2 = conv(d) + sqrt(conv(delta));
		b2/=(double)2.0;

		double a1 = conv(d)-b1;
		double a2 = conv(d)-b2;

		if(check(a1,b1,d)){
			cout << "Y " << a1 << " " << b1 << endl;
			continue;
		}
		if(check(a2,b2,d)){
			cout << "Y " << a2 << " " << b2 << endl;
			continue;
		}
		puts("N");
	}

}