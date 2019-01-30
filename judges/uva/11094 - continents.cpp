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

int m,n,vis[22][22];
char v[22][22];
char letra;

int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};

int dfs(int z, int w){

    int ans=1;
    vis[z][w]=1;

    fr(i,4){
        int xf=z+dx[i];
        int yf=w+dy[i];
        if(xf>=n || xf<0)
            continue;
        if(yf>=n)
            yf-=n;
        if(yf<0)
            yf+=n;
        if(vis[xf][yf]==1)
            continue;
        if(v[xf][yf]!=letra)
            continue;
        ans+=dfs(xf,yf);
    }

    return ans;

}

int main(){

    int x,y;

    while(cin>>m){

        cin >> n;

        string aux;
        getline(cin,aux);

        fr(i,m){
            string s;
            getline(cin,s);
            fr(j,n){
                v[i][j]=s[j];
            }
        }

        cin >> x >> y;
        ms(vis,0);
        letra=v[x][y];
        dfs(x,y);

        int mx=0;
        fr(i,m){
            fr(j,n){
                if(!vis[i][j] && v[i][j]==letra)
                    mx=max(mx,dfs(i,j));
            }
        }

        cout << mx << endl;
    }
}
