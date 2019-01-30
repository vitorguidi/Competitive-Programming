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
#define pq priority_queue
#define grtp greater< pair<int,int> >

#define gnl cout << endl
#define olar cout << "olar" << endl
#define gottagofast ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const double pi = 3.141592653589793238462643383279502884L;

int acum[5050],v[5050],n,k;

double media(int k){
	double ans=0;
	for(int i=1;i<=n-k+1;i++){
		double r=acum[i+k-1];
		double l = acum[i-1];
		ans=max(ans,(r-l)/k);
	}
	return ans;

}

int main(){

    cin >> n >> k;
    frr(i,n)
    	cin >> v[i];
    frr(i,n)
    	acum[i]=acum[i-1]+v[i];

    	cout << setprecision(15) << fixed;

    double ans=0.0;
    for(int i=k;i<=n;i++)
    	ans=max(ans,media(i));
   	cout << ans << endl;

}

