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
int vis[1100000];

void dfs(int v,int pai){

    int tam = nodes[v].size();
    
    fr(i,tam){
        int filho=nodes[v][i];
        if(filho==pai)
             continue;
        vis[filho]=vis[v]+1;
        dfs(filho,v);
    }
}


int main(){

    gottagofast;

    int n;
    cin >> n;
   
    nodes.resize(n+1);

    frr(i,n-1){
        int x,y;
        cin >> x >> y;
        nodes[y].pb(x);
        nodes[x].pb(y);
    }
    
    dfs(1,1);
    
    int d=0;
    int folha=0;
    
    frr(i,n){
        if(d<vis[i]){
            d=vis[i];
            folha=i;
        }
    }

    ms(vis,0);
    vis[folha]=0;

    dfs(folha,folha);
    d=0;
    frr(i,n){
        if(d<vis[i]){
            d=vis[i];
        }
    }
    cout << d << endl;

}
