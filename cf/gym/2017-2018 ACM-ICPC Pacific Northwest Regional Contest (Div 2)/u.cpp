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
#define pira cout << "pira" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int main(){
    
	double prob[7];
	double expected = 0.0;

	cout << setprecision(3) << fixed;

	frr(i,6){
		cin >> prob[i];
		expected+=prob[i]*i;
	}

	double ans = 1e100;

	frr(i,6){
		double aux=expected;
		aux-=prob[i]*i;
		double x = (3.5-aux)/prob[i];
		double d = abs(x-i);
		ans=min(ans,d);
	}

	cout << ans << endl;

}

