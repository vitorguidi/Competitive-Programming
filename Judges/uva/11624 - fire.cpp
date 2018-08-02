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

char v[1010][1010];
int dj[1010][1010],df[1010][1010],dg[1010][1010];

struct coord{
    int x, y;
};

int r,c;
int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};

void bfs(coord src, int (&d)[1010][1010],int flag){

    queue<coord> fila;
    d[src.x][src.y]=0;
    fila.push(src);

    while(!fila.empty()){
        coord pai = fila.front();
        fila.pop();
        
        fr(i,4){
            coord filho = pai;
            filho.x+=dx[i];
            filho.y+=dy[i];
        
            if(filho.x<0 || filho.x>=r)
                continue;
            if(filho.y<0 || filho.y>=c)
                continue;
            if(v[filho.x][filho.y]=='#')
                continue;
            
            int new_d=d[pai.x][pai.y]+1;

            if(d[filho.x][filho.y]>new_d){
                if(flag==1 && new_d>=df[filho.x][filho.y])
                    continue;
                d[filho.x][filho.y]=1+d[pai.x][pai.y];
                fila.push(filho);
            }

        }
    }

    // if(flag==0){
    //     fr(i,r){
    //         fr(j,c){
    //             dg[i][j]=min(dg[i][j],df[i][j]);
    //         }
    //     }
    // }

}

int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        
        cin >> r >> c;
        string s;
        coord joe,fire;

        vector<coord> foguin;
        
        getline(cin,s);
    
        fr(i,r){
            getline(cin,s);
            fr(j,c){
                v[i][j]=s[j];
                if(v[i][j]=='J'){
                    joe.x=i;
                    joe.y=j;
                }
                if(v[i][j]=='F'){
                    fire.x=i;
                    fire.y=j;
                    foguin.pb(fire);
                }
            }
        }
        
        ms(dj,INF);
        ms(df,INF);

        fr(i,foguin.size()){
            bfs(foguin[i],df,0);    
        }
        
        bfs(joe,dj,1);

        int ans=INF;

        fr(i,r){
            if(df[i][0]>dj[i][0] && v[i][0]!='#')
                ans=min(ans,dj[i][0]);
            if(df[i][c-1]>dj[i][c-1] && v[i][c-1]!='#')
                ans=min(ans,dj[i][c-1]);
        }

        fr(i,c){
            if(df[0][i]>dj[0][i] && v[0][i]!='#')
                ans=min(ans,dj[0][i]);
            if(df[r-1][i]>dj[r-1][i] && v[r-1][i]!='#')
                ans=min(ans,dj[r-1][i]);
        }

        // cout << "matriz do fogo" << endl;
        // fr(i,r){
        //     fr(j,c){
        //         int val=df[i][j];
        //         if(val==INF)
        //             cout << "X ";
        //         else
        //             cout << val << " ";
        //     }
        //     gnl;
        // }
        // gnl;

        // cout << "matriz do joe" << endl;
        // fr(i,r){
        //     fr(j,c){
        //         int val=dj[i][j];
        //         if(val==INF)
        //             cout << "X ";
        //         else
        //             cout << val << " ";
        //     }
        //     gnl;
        // }
        // gnl;
        

        if(ans==INF)
            cout << "IMPOSSIBLE" << endl;
        else
            cout << ans+1 << endl;

    }
}
