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

#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;

int n,m,q,hgt[10100];
int memo[10100][23],pai[10100],vis[10100];
vi nodes[10100];

int MAXNL=20;

void dfs(int v){

    vis[v]=1;
    for(auto filho : nodes[v]){
        if(vis[filho])
            continue;
        pai[filho]=v;
        hgt[filho]=1+hgt[v];
        dfs(filho);
    }

}

void build_table(){

    for(int i=1;i<=n;i++)
        memo[i][0]=pai[i];

    for(int i=1;i<=MAXNL;i++)
        for(int j=1;j<=n;j++)
            memo[j][i]=memo[ memo[j][i-1] ][i-1];

}

int lca(int x, int y){
    
    if(hgt[x]<hgt[y])
        swap(x,y);

    for(int i=MAXNL;i>=0;i--)
        if(hgt[ memo[x][i]  ] >= hgt[y] )
            x=memo[x][i];
   
    if(x==y)
        return x;

    for(int i=MAXNL;i>=0;i--){
        if(memo[x][i]!=memo[y][i]){
            x=memo[x][i];
            y=memo[y][i];
        }
    }

    return memo[y][0];
    
}


int main(){

    int t;cin >> t;
    int cnt=0;
    
    while(t--){
        
        cnt++;
        cin >> n;
        ms(vis,0);
        ms(pai,0);
        ms(hgt,0);

        fr(i,10100)
            nodes[i].clear();

        frr(i,n){
            cin >> m;
            fr(j,m){
                int x; cin >> x;
                nodes[i].pb(x);
                nodes[x].pb(i);
            }
        }

        pai[1]=hgt[1]=1;
        dfs(1);

        build_table();
        int q; cin >> q;
        cout << "Case " << cnt << ":" << endl;
        fr(i,q){
            int a,b; cin >> a >> b;
            cout << lca(a,b) << endl;
        }

    }

}
