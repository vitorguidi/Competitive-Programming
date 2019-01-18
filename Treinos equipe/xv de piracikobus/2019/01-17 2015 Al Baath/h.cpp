#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;
const ll mod=1e9+7;
const int LMAXN = 20;

int mx[4]={-1,1,0,0};
int my[4]={0,0,-1,1};

int vis[110][110];
int m,n,sx,sy;

char mapa[110][110];

queue<pii> fila;

bool valido(int x,int y){
	if(x<0 || y<0)
		return false;

	if(x>=n || y>=m)
		return false;

	if(mapa[x][y]=='#')
		return false;

	return true;

}



void bfs(){

	while(!fila.empty()){
		pii aux=fila.front();
		fila.pop();

		fr(i,4){
			int x=aux.fst+mx[i];
			int y=aux.snd+my[i];

			if(valido(x,y) && vis[x][y]>( vis[aux.fst][aux.snd]+1) ){
				vis[x][y]=vis[aux.fst][aux.snd]+1;
				fila.push({x,y});
			}
		}
	}

}

void solve(){
	cin>>n>>m;
	string s;

	ms(vis,INF);

	int chx,chy;
	fr(i,n){
		cin>>s;
		fr(j,m){
			mapa[i][j]=s[j];
			if(s[j]=='S'){
				sx=i;
				sy=j;
			}
			if(s[j]=='*'){
				fila.push({i,j});
				vis[i][j]=0;
			}
			if(s[j]=='X'){
				chx=i;
				chy=j;
			}
		}
	}		
	


	bfs();
	int aux=vis[chx][chy];
	vis[sx][sy]=0;
	fila.push({sx,sy});
	bfs();

	if(aux!=vis[chx][chy])
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;

}


int main(){
	fastio;
	int t;
	cin>>t;

	while(t--) solve();
}