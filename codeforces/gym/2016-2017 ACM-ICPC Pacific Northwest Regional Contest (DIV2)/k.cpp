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

double d1[6],d2[6];

int main(){
    
    fr(i,6){
    	int x;
    	cin >> x;
    	d1[--x]+=1.0;
    }

    fr(i,6){
    	int x;
    	cin >> x;
    	d2[--x]+=1.0;
    }

    double pig=0.0;

    fr(i,6)
    	pig+=( d1[i]/6.0 )*( d2[i]/6.0 );
    
    double pwin=0.0;

    fr(i,6){
    	double aux = d1[i]/6.0;
    	for(int j=0;j<i;j++){
    		pwin+=aux*(d2[j]/6.0);
    	}
    }

    double ans = pwin/(1.0-pig);

    cout << setprecision(5) << fixed;

    cout << ans << endl;

}

