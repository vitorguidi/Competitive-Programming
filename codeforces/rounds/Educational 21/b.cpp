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
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

ll acum[200100];

int main(){
    
	fastio;

	ll n,k; cin >> n >> k;

	cout << setprecision(10) << fixed;

	frr(i,n){
		cin >> acum[i];
		acum[i]+=acum[i-1];
	}

	ll sum = 0;

	for(int i=1;i<=n-k+1;i++)
		sum+=acum[i+k-1]-acum[i-1];
	
	long double ans = (long double)sum/( (long double)(n-k+1));

	cout << ans << endl;


}

