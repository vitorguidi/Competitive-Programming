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
#define pq priority_queue
#define grtp greater< pair<int,int> >

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

int vis[110];
vector<vi> nodes;

int dfs(int v, int prev){
    
    int tam = nodes[v].size();

    if(vis[v]==-1){
        if(prev==1)
            vis[v]=0;
        else
            vis[v]=1;
    }

    int ans=0;
    fr(i,tam){
        int filho = nodes[v][i];
        if(vis[filho]==-1)
            ans=max(ans,dfs(filho,vis[v]));
        else if(vis[filho]!=vis[v])
            continue;
        else
            return 1;
    }

    return ans;

}

int main(){

    gottagofast;
    int n,m,cnt=0;
    while(cin >> n){
        nodes.resize(n+1);
        nodes.clear();
        cnt++;
        cout << "Instancia " << cnt << endl;
        cin >> m;
        fr(i,m){
            int x,y;
            cin >> x >> y;
            nodes[x].pb(y);
            nodes[y].pb(x);
        }
        ms(vis,-1);
        int ans = dfs(1,0);
        if(ans==0)
            cout << "sim" << endl;
        else
            cout << "nao" << endl;
        gnl;
    }
}
