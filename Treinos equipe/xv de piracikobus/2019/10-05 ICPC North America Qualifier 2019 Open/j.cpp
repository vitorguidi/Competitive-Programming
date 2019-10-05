#include "bits/stdc++.h"
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
 
#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)
 
#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

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

ll v[1100100];
long double pref[1100100];
long double suf[1100100];
int n;

int main(){

    fastio;

    cin >> n;

    frr(i,n){
        cin >> v[i];
		v[i]+=v[i-1];
    }

	for(int i=1;i<=n;i++){
		pref[i]=v[i]/double(i);
	}

	for(int i=n;i>0;i--){
		ll amt = v[n]-v[i-1];
		suf[i]=amt/double(n-i+1);
	}

	long double ans = 0;

	for(int i=1;i<=n;i++){

		ans = max(ans,pref[i]);
		ans = max(ans,suf[i]);

	}
	
	cout << setprecision(12) << fixed;
	cout << ans << endl;

}