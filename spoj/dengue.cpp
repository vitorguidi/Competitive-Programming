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

int d[110],pai[110];
vector<vi> nodes;

void dfs(int v){

    int tam = nodes[v].size();
    fr(i,tam){
        int filho = nodes[v][i];
        if(filho!=pai[v]){
            pai[filho]=v;
            d[filho]=1+d[v];
            dfs(filho);
        }
    }

}

int main(){
    int n;
    int cnt=0;
    while(cin >> n){
        if(!n)
            break;
        cnt++;
        nodes.clear();
        nodes.resize(n+1);
        fr(i,n-1){
            int x,y;
            cin >> x >> y;
            nodes[x].pb(y);
            nodes[y].pb(x);
        }
        pai[1]=1;
        dfs(1);
        int mx=0,root=1;
        frr(i,n){
            if(mx<d[i]){
                root=i;
                mx=d[i];
            }
        }
        ms(d,0);
        ms(pai,0);
        pai[root]=root;
        dfs(root);
        vi path;
        mx=0;
        int tgt=0;
        frr(i,n){
            if(mx<d[i]){
                tgt=i;
                mx=d[i];
            }
        }
        path.pb(tgt);
        while(pai[tgt]!=tgt){
            path.pb(pai[tgt]);
            tgt=pai[tgt];
        }

        cout << "Teste " << cnt << endl;

        if(path.size()==1)
            cout << root << endl;
        else
            cout << path[path.size()/2] << endl;

        gnl;

    }
}
