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

vi adj[100100];
int memo[100100][2];

int pd(int u, int flag, int pai){

    int& pdm = memo[u][flag];
    if(pdm!=-1) return pdm;

    int pega = 1;
    int passa = 0;

    for(auto v : adj[u]){
        if(v==pai)  continue;

        if(flag==0){
            pega+=pd(v,1,u);
            passa+=pd(v,0,u);
        }
        else{
            passa+=pd(v,0,u);
        }
    }

    if(flag==0)
        return pdm = max(pega, passa);
    else
        return pdm = passa;

}
    
int main(){

	fastio;
    int n,k;
    cin >> n >> k;

    fr(i,k){
        int a,b;
        cin >> a >> b;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    ms (memo,-1);

    cout << pd(1,0,0)<<endl;

}