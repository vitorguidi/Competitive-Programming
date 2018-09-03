#include "bits/stdc++.h"
using namespace std;

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define dbg(x)	cout << #x << " = " << x << endl

#define gnl cout << endl

typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

ll n,m;
ll a[1010],b[1010];

bool check(double val){

	double pay=m;
	double burned = (pay+val)/a[1];
	val-=burned;

	if(val<0)
		return false;

	for(int i = 2;i<=n;i++){

		burned = (pay+val)/b[i];
		val-=burned;
		
		if(val<0)
			return false;

		burned = (pay+val)/a[i];
		val-=burned;

		if(val<0)
			return false;

	}

	burned=(pay+val)/b[1];
	val-=burned;

	if(val<0)
		return false;

	return true;

}

double bins(double ini, double end, int cnt){

	double mid = (ini+end)/2.0;
	cnt++;

	if(cnt==1000)
		return INF;

	if(check(mid))
		return min(mid,bins(ini,mid,cnt));
	else
		return bins(mid,end,cnt);

}

int main(){
    
    cin >> n >> m;

    frr(i,n)
    	cin >> a[i];
    frr(i,n)
    	cin >> b[i];


    cout << setprecision(9) << fixed;
   	double ans = bins(1,1e9+5,1);

   	if(check(ans) && ans<=(double)1e9+1e-6)
   		cout << ans << endl;
   	else
   		cout << -1 << endl;

}

