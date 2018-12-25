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

int root,pre[110],low[110],cut[110],clk,vis[110];
vi nodes[110];

void dfs(int v, int caller){

    low[v]=pre[v]=clk++;
    int nf=0;   bool any=false;
    vis[v]=1;

    for (auto filho : nodes[v]){

        if(filho==caller)
            continue;

        if(!vis[filho]){

            nf++;
            dfs(filho,v);

            if(low[filho]>=pre[v])
                any=true;

            low[v]=min(low[filho],low[v]);

        }
        
        else
            low[v]=min(low[v],pre[filho]);

    }

    if(v==root && nf>1)
        cut[v]=1;
    else if(v!=root && any)
        cut[v]=1;
        
}

int main(){

    int n;
    int caso=0;
    
    while(cin >> n){
        
        if(!n)
            break;
        
    
        if(caso!=0)
            gnl;

        caso++;

        map<string,int> names;
        map<int,string> volta;

        string s;
        getline(cin,s);

        int cnt=0;
        
        fr(i,n){
            getline(cin,s);
            names[s]=cnt;
            volta[i]=s;
            cnt++;
            nodes[i].clear();
        }

        int r;
        cin >> r;
        getline(cin,s);

        fr(i,r){
            int x,y;
            cin >> s;
            x=names[s];
            cin >> s;
            y=names[s];
            nodes[x].pb(y);
            nodes[y].pb(x);
        }

        ms(pre,0);
        ms(low,0);
        ms(cut,0);
        ms(vis,0);
        clk=0;

        fr(i,n){
            if(vis[i])
                continue;
            root=i;
            dfs(i,i);
        }
        
        vector<string> ans;

        fr(i,n){
            if(cut[i])
                ans.pb(volta[i]);
        }
        
        sort(all(ans));
        
        cout << "City map #" << caso << ": " << ans.size() << " camera(s) found" << endl;
        
        fr(i,ans.size())
            cout << ans[i] << endl;
    
    }

}
