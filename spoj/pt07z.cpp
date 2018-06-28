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

vi nodes[10100];
int dist[10100],pai[10100];

void dfs(int v, int p){
    
    if(pai[v]==0){
        pai[v]=p;
        dist[v]=dist[p]+1;
    }
    int ans=0;
    int tam = nodes[v].size();
    fr(i,tam){
        int filho = nodes[v][i];
        if(filho==p)
            continue;
        dfs(filho,v);
    }

}

int main(){

    int n;
    cin >> n;
    
    fr(i,n-1){
        int x,y;
        cin >> x >> y;
        nodes[x].pb(y);
        nodes[y].pb(x);
    }
    
    pai[1]=1;
    dfs(1,1);

    int x=0,y=0;

    frr(i,n){
        if(dist[i]>y){
            x=i;
            y=dist[i];
        }
    }

    ms(dist,0);
    ms(pai,0);
    pai[x]=x;
    dfs(x,x);
    int ans=0;
    frr(i,n){
        if(dist[i]>ans)
            ans=dist[i];
    }

    cout << ans << endl;

}
