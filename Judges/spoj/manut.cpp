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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int vis[500],cut[500],low[500],clk,pre[500];
vi nodes[500];

void dfs(int v,int caller){

    vis[v]=1;
    low[v]=pre[v]=clk++;
    int nf=0;
    bool any=false;

    for (auto filho : nodes[v]){

        if(filho==caller)
            continue;

        if(!vis[filho]){

            nf++;
            dfs(filho,v);

            if(low[filho]>=pre[v])
                any=true;

            low[v]=min(low[v],low[filho]);

        }
        else
            low[v]=min(low[v],pre[filho]);

    }

    if(v==1 && nf>1)
        cut[v]=1;
    else if(any && v!=1)
        cut[v]++;

}


int main(){

    int n,m,cnt;
    
    while(cin >> n){
    
        if(!n)
            break;
        
        cin >> m;
        cnt++;

        frr(i,n)
            nodes[i].clear();
        
        fr(i,m){
            int x,y;
            cin >> x >> y;
            nodes[x].pb(y);
            nodes[y].pb(x);
        }
        
        ms(vis,0);
        ms(cut,0);
        
        dfs(1,1);
        
        vi ans;
        frr(i,n){
            if(cut[i])
                ans.pb(i);
        }
        
        cout << "Teste " << cnt << endl;
    
        if(ans.size()==0){
            cout << "nenhum" << endl << endl;
            continue;
        }

        fr(i,ans.size())
            cout << ans[i] << " ";
        gnl;gnl;
    }

}
