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
#define all(x)	x.begin(),x.end()

#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int l,h,w,n,s;

char m[110][110][15];
int d[110][110][15];
int memo[10100][110];

int dx[6]={-1,0,1,0,0,0};
int dy[6]={0,1,0,-1,0,0};
int dz[6]={0,0,0,0,1,-1};

vii vols;

struct coord{
    int lvl,row,col;
};

bool in_grid(coord x){
    if(x.row==0 || x.row>h)
        return false;
    if(x.col==0 || x.col>w)
        return false;
    if(x.lvl==0 || x.lvl>l)
        return false;
    return true;
}

char symbol(coord x){
    return m[x.row][x.col][x.lvl];
}

void bfs(coord v){

    queue<coord> fila;
    ms(d,INF);
    d[v.row][v.col][v.lvl]=0;
    fila.push(v);

    while(!fila.empty()){

        coord pai = fila.front();
        fila.pop();

        int dpai=d[pai.row][pai.col][pai.lvl];

        fr(i,6){
    
            coord filho=pai;
            
            filho.lvl+=dz[i];
            filho.row+=dx[i];
            filho.col+=dy[i];

            int &dfilho = d[filho.row][filho.col][filho.lvl];

            if(!in_grid(filho))
                continue;

            if(symbol(filho)=='X')
                continue;

            if(i==4 && !(symbol(pai)=='U' && symbol(filho)=='D') )
                continue;
            
            if(i==5 && !(symbol(pai)=='D' && symbol(filho)=='U') )
                continue;
        
            if( dfilho > 1+dpai ){

               dfilho = 1 + dpai;
               fila.push(filho);
            
            }

        }

    }


}

int pd(int wgt, int ind){

    if(wgt<0)
        return -INF;

    if(wgt==0 || ind==n)
        return 0;

    int &pdm=memo[wgt][ind];

    if(pdm!=-1)
        return pdm;

    int cost = vols[ind].fst;
    int val = vols[ind].snd;

    return pdm = max( val + pd(wgt - cost,ind+1), pd(wgt,ind+1)  );

}

int main(){
    
    int t;
    cin >> t;
   
    while(t--){

        cin >> l >> h >> w >> n >> s;
        coord ini;

        frr(i,l){
            frr(j,h){
                frr(k,w){
                    cin >> m[j][k][i];
                    if(m[j][k][i]=='S'){
                        ini.lvl=i;
                        ini.row=j;
                        ini.col=k;
                    }
                }
            }
        }

        bfs(ini);
        vols.clear();

        fr(i,n){
            int x,y,z,p;
            cin >> x >> y >> z >> p;
            int cost = d[y][z][x];
            if(cost==INF)
            	continue;
            cost=cost*3;
            vols.pb( {cost,p} );
        }

        n=vols.size();

        ms(memo,-1);
        cout << pd(s,0) << endl;
        
    }

}

