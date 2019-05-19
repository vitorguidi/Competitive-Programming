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

ll phi[1100100];
ll ans[1100100];


int main(){

	fastio;

    fr(i,1100100)
        phi[i]=i;

    for(ll i=2;i<1100100ll;i++){
        if(phi[i]==i){
            for(ll j=i;j<1100100;j+=i){
                phi[j]/=i;
                phi[j]*=(i-1ll);
            }
        }
    }	

    for(ll i=1;i<=1000001;i++){
        for(ll j=i;j<=1000001;j+=i){
            ans[j]+=i*phi[j/i];
        }
    }

    for(int i=1;i<1100100;i++){
        ans[i]+=ans[i-1];
        ans[i]-=i;
        
    }

    ll n;
    while(cin>>n){
        if(!n)  break;
        cout << ans[n] << endl;
    }

}