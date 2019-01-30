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

#define gnl cout << endl
#define olar cout << "olar" << endl
#define gottagofast ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

vector<vi> nodes;
int vis[10010],indeg[10100];

int dfs(int v){

    vis[v]=1;

    int ans=0;

    for(auto filho : nodes[v]){
        
        if(vis[filho]==2)
            continue;

        if(vis[filho]==1){
            ans= -INF;
            continue;
        }

        ans=min(ans,dfs(filho));
    }

    vis[v]=2;
    return ans;

}

int main(){

    int t;
    cin >> t;
    
    while(t--){
    
        int n,h;
        cin >> n >> h;
    
        nodes.clear();
        nodes.resize(n+1);
        
        ms(vis,0);
        ms(indeg,0);

        fr(i,h){
            int x,y;
            cin >> x >> y;
            
            nodes[x].pb(y);
            
            indeg[y]++;
        }

        int cnt=0,flag=0;
        int ini;

        frr(i,n){

            if(vis[i])
                continue;

            int check=dfs(i);
        
            if(check==-INF){
                flag=1;
                break;
            }

            if(indeg[i]==0){
                cnt++;
                ini=i;
            }
        
        }

        if(flag){
            cout << "recheck hints" << endl;
            continue;
        }

        if(cnt>1){
            cout << "missing hints" << endl;
            continue;
        }

        queue<int> fila;
        vi ans;
        ans.pb(ini);
        fila.push(ini);


        cnt=1;flag=0;

        while(!fila.empty()){
            
            int atual = fila.front();
            fila.pop();
            cnt--;

            for(auto filho : nodes[atual]){
                indeg[filho]--;
                if(!indeg[filho]){
                    cnt++;
                    ans.pb(filho);
                    fila.push(filho);
                }
            }

            if(cnt>1){
                flag=1;
                break;
            }
        
        }

        if(flag){
            cout << "missing hints" << endl;
            continue;
        }

        fr(i,ans.size())
            cout << ans[i] << " ";
        gnl;

    }

}