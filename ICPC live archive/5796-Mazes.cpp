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

int pre[10100],comp[10100];
int low[10100],clk=1;
vi nodes[10100];
map<pii,int> memo;

void dfs_connect(int v, int val){

    comp[v]=val;

    for (auto filho : nodes[v]){

        if( !memo[{v,filho}] )
            continue;

        if(comp[filho])
            continue;

        dfs_connect(filho,val);

    }

}

void dfs(int v, int caller){

    low[v]=pre[v]=clk++;
    int nf=0; bool any=false;

    for (auto filho : nodes[v]){
        
        if(filho==caller)
            continue;
        
        if(!pre[filho]){
            
            nf++;
            dfs(filho,v);
            
            if(low[filho]>pre[v]){
                memo[{v,filho}]=1;
                memo[{filho,v}]=1;
            }
            
            low[v]=min(low[filho],low[v]);
        }

        else
            low[v]=min(low[v],pre[filho]);

    }

}

int main(){

    fastio;
    int r,c,q;

    while(cin >> r){
        
        if(!r)
            break;
        
        cin >> c >> q;

        frr(i,r)
            nodes[i].clear();

        fr(i,c){
            int x,y;
            cin >> x >> y;
            nodes[x].pb(y);
            nodes[y].pb(x);
        }

        ms(comp,0);
        ms(pre,0);
        ms(low,0);
        memo.clear();

        frr(i,r){
            if(!pre[i])
                dfs(i,i);
        }

        int cnt=1;
        
        frr(i,r){
            if(!comp[i]){
                dfs_connect(i,cnt);
                cnt++;
            }
        }

        fr(i,q){
            
            int s,t;
            
            cin >> s >> t;
         
            if(comp[s]==comp[t])
                cout << "Y" << endl;
            else
                cout << "N" << endl;
        
        }

        cout << "-" << endl;

    }

}
