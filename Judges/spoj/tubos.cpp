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

int pre[1010],low[1010];
vi nodes[1010];
int clk,cnt;

void dfs(int v, int caller){

    low[v]=pre[v]=clk++;

    for(auto filho : nodes[v]){

        if(filho==caller)
            continue;

        else if(!pre[filho]){

            dfs(filho,v);

            if(low[filho]>pre[v])
                cnt++;

            low[v]=min(low[filho],low[v]);
        }

        else
            low[v]=min(low[v],pre[filho]);

    }

}

int main(){

    int n,m;

    while(cin >> n){
    
        if(!n)
            break;
    
        cin >> m;
        
        frr(i,n)
            nodes[i].clear();

        fr(i,m){
            int x,y;
            cin >> x >> y;
            nodes[x].pb(y);
            nodes[y].pb(x);
        }

        ms(pre,0);
        ms(low,0);

        cnt=0;
        dfs(1,1);
        
        if(cnt==0)
            cout << "S" << endl;
        else
            cout << "N" << endl;

    }

}