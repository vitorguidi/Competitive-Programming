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

double acum[200200];
double v[200200];
int n;

double solve(double x){

	acum[0]=0.0;

	double mn = 0;
	double mx = 0;

	for(int i=1;i<=n;i++){
		acum[i]=double(v[i])-x;
		acum[i]+=acum[i-1];
		mx=max(mx,acum[i]);
		mn=min(mn,acum[i]);
	}

	return abs(mn-mx);

}

int main(){

	fastio;

	cin >> n;

	double mn = INF;
	double mx = -INF;

	frr(i,n){
		cin >> v[i];
		mx=max(mx,v[i]);
		mn=min(mn,v[i]);
	}

	double a = -20000;
	double b = 20000;


	for(int i=1;i<=100;i++){
	
		double x = (a+b)/2.0;
	
		double step = (b-a)/3.0;
		
		double k1 = a + step;
		double k2 = b-step;

		if(solve(k1)>solve(x))
			a=k1;
		else
			b=k2;

	}

	cout << setprecision(15) <<fixed;

	cout << solve((a+b)/2.0) << endl;

}