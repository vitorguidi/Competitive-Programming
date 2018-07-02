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

vi nodes[10100];
int vis[10100];

void dfs(int v){
    vis[v]=1;
    int tam = nodes[v].size();
    fr(i,tam){
        int filho=nodes[v][i];
        if(!vis[filho])
            dfs(filho);
    }
}

int main(){
    
    int n,m;
    cin >> n >> m;
    if(m!=n-1){
        cout << "NO" << endl;
        return 0;
    }   
    fr(i,m){
        int x,y;
        cin >> x >> y;
        nodes[x].pb(y);
        nodes[y].pb(x);
    }
        
    dfs(1);

    frr(i,n){
        if(vis[i]==0){
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

}
