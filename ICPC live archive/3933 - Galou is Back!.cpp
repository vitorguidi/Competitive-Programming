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

char m[110][110];
char vis[110][110];

int dx[6]={-1,-1,0,1,1,0};
int dy[6]={0,1,1,0,-1,-1};
int r,c;

struct coord{
    int x,y;
};

void dfs(coord v){
    
    char &dv=vis[v.x][v.y];
    dv='B';

    fr(i,6){

        coord filho=v;
        filho.x+=dx[i];
        filho.y+=dy[i];

        if(filho.x<0 || filho.x>=r)
            continue;
        if(filho.y<0 || filho.y>=c)
            continue;
        
        char &df=vis[filho.x][filho.y];

        if(df=='.' || df=='B')
            continue;

        df='B';
        dfs(filho);
    }

    
}

void bfs(coord v){
    
    queue<coord> fila;
    if(vis[v.x][v.y]==')'){
        vis[v.x][v.y]='B';
        return;
    }
    vis[v.x][v.y]='(';
    fila.push(v);
    
    while(!fila.empty()){
   
        coord pai=fila.front();
        fila.pop();

        char &dpai=vis[pai.x][pai.y];
        
        fr(i,6){

            coord filho=pai;
            filho.x+=dx[i];
            filho.y+=dy[i];

            char &df=vis[filho.x][filho.y];
            
            if(filho.x<0 || filho.x>=r)
                continue;
            if(filho.y<0 || filho.y>=c)
                continue;
            if(df=='.')
                continue;
            
            if(df=='F'){
                if(dpai=='(')
                    df=')';
                if(dpai==')')
                    df='(';
                fila.push(filho);
                continue;
            }

            if(df=='(' && dpai=='('){
                df=dpai='B';
                return;
            }
            if(df==')' && dpai==')'){
                df=dpai='B';
                return;
            }


        }

    }

}

int main(){
    
    while(cin >> r){
        
        if(!r)
            break;
        
        vector<coord> ini;

        cin >> c;
        string s;
        getline(cin,s);
        
        fr(i,r){
            
            getline(cin,s);
            
            fr(j,c){
                
                if(s[j]!='.'){
                    vis[i][j]='F';
                }
                
                else
                    vis[i][j]='.';
                
                if(s[j]=='I'){
                    coord aux;
                    aux.x=i;
                    aux.y=j;
                    ini.pb(aux);
                }

            }

        }

        fr(i,ini.size())
            bfs(ini[i]);

        fr(i,r){
            fr(j,c){
                if(vis[i][j]=='B'){
                    coord aux;
                    aux.x=i;
                    aux.y=j;
                    dfs(aux);
                }
            }
        }

        
        gnl;
        fr(i,r){
            fr(j,c){
                cout << vis[i][j];
            }
            gnl;
        }
        
    }
}

