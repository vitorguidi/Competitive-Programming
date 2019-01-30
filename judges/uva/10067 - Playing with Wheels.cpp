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
int dist[10100];

void bfs(int v,map<int,int> &forb){
    
    queue<int> fila;
    dist[v]=0;
    fila.push(v);

    while(!fila.empty()){

        int pai=fila.front();
        fila.pop();
        int tam = nodes[pai].size();
       
        fr(i,tam){
            int filho = nodes[pai][i];
            if(!forb[filho] && dist[filho]>1+dist[pai]){
                dist[filho]=1+dist[pai];
                fila.push(filho);
            }
        }

    }
}

int to_num(vi &dgt){
    int pow=1000;
    int ans=0;
    fr(i,4){
        ans+=dgt[i]*pow;
        pow=pow/10;
    }
    return ans;
}

vi to_vi(int x){
    vi ans;
    fr(i,4){
        ans.pb(x%10);
        x=x/10;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

void build_nodes(){
    
    fr(i,10000){
    
        vi aux=to_vi(i);
        vi ans[4];

        ans[0].pb((aux[0]+1)%10);
        ans[0].pb((aux[0]-1)%10);
        ans[1].pb((aux[1]+1)%10);
        ans[1].pb((aux[1]-1)%10);
        ans[2].pb((aux[2]+1)%10);
        ans[2].pb((aux[2]-1)%10);
        ans[3].pb((aux[3]+1)%10);
        ans[3].pb((aux[3]-1)%10);

        fr(j,4){
            fr(k,2){
                if(ans[j][k]==-1)
                    ans[j][k]=9;
            }
        }

        fr(j,4){
            fr(k,2){
                vi v;
                fr(l,4)
                    v.pb(aux[l]);
                v[j]=ans[j][k];
                int trampo=to_num(v);
                nodes[i].pb(trampo);
            }
        
        }

    }
}

int main(){
    
    int t;
    cin >> t;
    
    build_nodes();

    while(t--){
   

        vi target,src;
        int aux;
        map<int,int> forb;

        fr(i,4){
            cin >> aux;
            src.pb(aux);
        }
        fr(i,4){
            cin >> aux;
            target.pb(aux);
        }

        vi nono;
        int n;
        cin >> n;
        fr(i,n){
            nono.clear();
            fr(i,4){
                cin >> aux;
                nono.pb(aux);
            }
            int lol=to_num(nono);
            forb[lol]=1;
        }


        ms(dist,INF);
        bfs(to_num(src),forb);

        if(dist[to_num(target)]==INF)
            cout << -1 << endl;
        else
            cout << dist[to_num(target)] << endl;
    
    }

}
