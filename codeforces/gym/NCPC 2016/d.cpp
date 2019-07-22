#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()

#define gnl cout << endl
#define olar cout << olar << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) 

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;

ll cost[400];

int main(){

    fastio;
    
    int n; cin >> n;
    
    frr(i,n)
        cin >> cost[i];
        
    int ini=1;
    ll cash = 100;
    
    while(ini<=n){
    
        ll mincost = cost[ini];
        while(ini+1<=n && cost[ini+1]<=mincost){
            mincost=cost[++ini];
        }
        
        if(ini>=n)  break;
        
        ll maxcost = cost[ini];
        while(ini+1<=n && cost[ini+1]>=maxcost){
            maxcost=cost[++ini];
        }
        
                
        ll compra = cash/mincost;
        compra = min(compra,100000ll);
        cash+=compra*maxcost;
        cash-=compra*mincost;
        
    
    }
    
    cout << cash << endl;

}