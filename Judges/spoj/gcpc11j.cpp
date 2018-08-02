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
const double pi = 3.141592653589793238462643383279502884L;

vector<vi> nodes;
int vis[100100];

void dfs(int v, int pai){
    
    int tam = nodes[v].size();
    
    fr(i,tam){
        int filho = nodes[v][i];
        if(!vis[filho]){
            vis[filho]=1+vis[v];
            dfs(filho,v);
        }
    }

}

int main(){
    int c;
    scanf("%d",&c);

    while(c--){
    
        int n;
        scanf("%d",&n);
        
        nodes.clear();
        nodes.resize(n+1);
        
        fr(i,n-1){
            int x,y;
            scanf("%d %d",&x,&y);
            nodes[x].pb(y);
            nodes[y].pb(x);
        }
        
        ms(vis,0);
        dfs(0,0);
        int mx=0;
        int root=0; 
        fr(i,n){
            if(vis[i]>mx){
                mx=vis[i];
                root=i;
            }
        }

        ms(vis,0);
        mx=0;
        dfs(root,root);
        fr(i,n){
            if(vis[i]>mx)
                mx=vis[i];
        }

        cout << max(mx/2,mx-mx/2) << endl;
    }
}
