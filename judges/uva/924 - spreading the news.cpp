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

vi nodes[2510];
int dist[2510];
int day[2510];

void bfs(int v){
    
    queue<int> fila;
    fila.push(v);
    dist[v]=0;

    while(!fila.empty()){
    
        int pai=fila.front();
        fila.pop();
        int tam = nodes[pai].size();
        
        fr(i,tam){
            
            int filho = nodes[pai][i];
            
            if(dist[filho]>1+dist[pai]){
                dist[filho]=1+dist[pai];
                fila.push(filho);
            }

        }

    }

}

int main(){

    int e;
    cin >> e;
    
    fr(i,e){
        int n;
        cin >> n;
        fr(j,n){
            int x;
            cin >> x;
            nodes[i].pb(x);
        }
    }

    int t;
    cin >> t;
    
    while(t--){
        int s;
        ms(dist,INF);
        ms(day,0);
   
        cin >> s;

        bfs(s);
        int mx=0,id=-1;
        
        fr(i,e){
            if(dist[i]==INF)
                continue;
            day[dist[i]]++;
        }

        frr(i,e){
            if(mx<day[i]){
                mx=day[i];
                id=i;
            }
        }
        
        if(id==-1)
            cout << 0 << endl;
        else
            cout << mx << " " << id << endl;
            
    }

}
