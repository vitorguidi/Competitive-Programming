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

pll dist[25100][30];
ll a[25100][30],b[25100][30];
int n,m;

void dijkstra(int x, int y){

    pq < pair<pll,pii>, vector< pair<pll,pii> >, greater< pair<pll,pii> > > fila;
    
    dist[x][y]=mp(0,0);
    pii v = mp(x,y);

    fila.push(  mp(dist[x][y],v) );

    while(!fila.empty()){

        v=fila.top().snd;
        x = v.fst;
        y = v.snd;

        fila.pop();

        pll new_dist;
        pii coord;

        if(y>1){ //movimento para a track da esquerda
            
            new_dist.fst=dist[x][y].fst;
            new_dist.snd=dist[x][y].snd+b[x][y-1];

            if(new_dist<dist[x][y-1]){
                dist[x][y-1]=new_dist;
                coord.fst=x;
                coord.snd=y-1;
                fila.push(mp(new_dist,coord));
            }

        }

        if(y<m){    //movimento para track da direita
            
            new_dist.fst=dist[x][y].fst;
            new_dist.snd=dist[x][y].snd+b[x][y];
            
            if(new_dist<dist[x][y+1]){
                dist[x][y+1]=new_dist;
                coord.fst=x;
                coord.snd=y+1;
                fila.push(mp(new_dist,coord));
            }

        }

        if(x<=n){    //movimento para d+1
            
            new_dist.fst=dist[x][y].fst+a[x][y];
            new_dist.snd=dist[x][y].snd;
            
            if(new_dist<dist[x+1][y]){
                dist[x+1][y]=new_dist;
                coord.fst=x+1;
                coord.snd=y;
                fila.push(mp(new_dist,coord));
            }

        }

    }



}

void run(){
   
    cin >> n >> m;

    fr(i,25100){
        fr(j,30)    dist[i][j]=mp(llINF,llINF);
    }

    frr(i,n){
        frr(j,m)    scanf("%I64lld",&a[i][j]);
    }

    frr(i,n){
        frr(j,m-1)  scanf("%I64lld",&b[i][j]);
    }

    dijkstra(1,1);

    pll ans=mp(llINF,llINF);

    frr(i,m){
        if(dist[n+1][i]<ans)  ans=dist[n+1][i];
    }

    cout << ans.fst << " " << ans.snd << endl;

}

int main(){

    int t;
    scanf("%d",&t);
    fr(i,t) run();

}
