#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define pq priority_queue
#define grtp greater< pair<int,int> >

#define gnl cout << endl
#define olar cout << "olar" << endl

typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

vi nodes[200200];
int vis[200200],pai[200200];
int be;

int dfs(int v){

    vis[v]++;
    int tam = nodes[v].size();
    int ans=0;
    
    if(tam!=2)  ans=1;

    fr(i,tam){
        int filho=nodes[v][i];
        
        if(vis[filho]==1 && filho!=pai[v])  be++;

        if(vis[filho]!=0)   continue;
        
        pai[filho]=v;
        ans=max(ans,dfs(filho));
    }

    vis[v]++;
    return ans;
}

int main(){

    int n,m;
    scanf("%d %d",&n,&m);

    fr(i,m){
        int x,y;
        scanf("%d %d",&x,&y);
        nodes[x].pb(y);
        nodes[y].pb(x);
    }

    frr(i,n)    pai[i]=i;

    int ans=0;
    frr(i,n){
        if(vis[i]!=0)   continue;
        be=0;
        int aux=dfs(i);
        if(be==1 && !aux)    ans++;
    }

    printf("%d\n",ans);

}
 