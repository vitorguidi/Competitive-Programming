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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
ll v[100100];
ll acum[100100];

ll go(int n){

	if(n==1)	return ( v[1]-1)%MOD;
	
	return ( go(n-1)*v[n]+ (v[n]-1)*acum[n-1] )%MOD;

}

void solve(){
	
	int n; cin >> n;
	v[0]=1;
	acum[0]=1;
	frr(i,n){
		cin >> v[i];
		acum[i]=acum[i-1]*v[i];
		acum[i]%=MOD;
	}
	
	cout << go(n) << endl;
	
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);    
	
	int t; cin >> t;
	
	while(t--) solve();
    

}