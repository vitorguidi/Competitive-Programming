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
const int MOD = 1e9+7;

ll n,m,k;

ll v[300300];
ll memo[300300][12];

ll pd(int ind, int mod){

    if(ind>n)
        return 0;

    ll &pdm=memo[ind][mod];
    if(pdm!=-1) return pdm;

    pdm=0;

    ll pega = v[ind];
    if(mod==0)
        pega-=k;

    return pdm=max(pdm,pega+pd(ind+1,(mod+1)%m));

}

int main(){

	fastio;

	cin >> n >> m >> k;

    frr(i,n){
        cin >> v[i];
    }

    ll ans = 0;

    ms(memo,-1);

    frr(i,n){
        ans=max(ans,pd(i,0));
    }

    cout << ans << endl;

}