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
const int mod = 1e9+7;

ll memo[100100][52];
int t,m,n; 

ll pd(ll tempo, ll valor){

	if(tempo==1)
		return 1;

	ll &pdm = memo[valor][tempo];
	
	if(pdm!=-1)
		return pdm;

	ll ans = 0;

	if(valor>m)
		ans+=pd(tempo-1,valor-1);

	if(valor<n)
		ans+=pd(tempo-1,valor+1);

	return pdm=ans%mod;

}

int main(){
    
    cin >> t >> m >> n;

    ll resp = 0;
    ms(memo,-1);

    for(int i=m;i<=n;i++){
    	resp+=pd(t,i);
    	resp=resp%mod;
    }

    cout << resp << endl;

}

