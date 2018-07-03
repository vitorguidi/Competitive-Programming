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

struct coord{
    int x,y,z;
};

int l,r,c;
char m[33][33][33];
int dist[33][33][33];

int dx[6]={0,-1,0,1,0,0};
int dy[6]={-1,0,1,0,0,0};
int dz[6]={0,0,0,0,1,-1};

void bfs(coord v){

    queue<coord> fila;
    fila.push(v);
    dist[v.z][v.x][v.y]=0;
     
    while(!fila.empty()){
    
        coord pai = fila.front();
        fila.pop();
        
        fr(i,6){
            coord filho=pai;
            filho.x+=dx[i];
            if(filho.x<0 || filho.x>=r)
                continue;
            filho.y+=dy[i];
            if(filho.y<0 || filho.y>=c)
                continue;
            filho.z+=dz[i];
            if(filho.z<0 || filho.z>=l)
                continue;
            int dfilho=dist[filho.z][filho.x][filho.y];
            int dpai=dist[pai.z][pai.x][pai.y];
            if(dfilho>1+dpai && m[filho.z][filho.x][filho.y]!='#'){
                fila.push(filho);
                dist[filho.z][filho.x][filho.y]=1+dpai;
            }
        }
    }
}

int main(){

    while(cin >> l){

        coord start,end;
        cin >> r >> c;

        if(!l)
            break;

        string s;
        getline(cin,s);

        fr(i,l){
            fr(j,r){
                getline(cin,s);
                fr(k,c){
                    m[i][j][k]=s[k];
                    if(m[i][j][k]=='S'){
                        start.z=i;
                        start.x=j;
                        start.y=k;
                    }
                    if(m[i][j][k]=='E'){
                        end.z=i;
                        end.x=j;
                        end.y=k;
                    }

                }
            }
            getline(cin,s);
        }

        ms(dist,INF);
        bfs(start);

        int ans=dist[end.z][end.x][end.y];

        if(ans==INF)
            cout << "Trapped!" << endl;
        else
            cout << "Escaped in " << ans << " minute(s)." << endl;

    }

}
