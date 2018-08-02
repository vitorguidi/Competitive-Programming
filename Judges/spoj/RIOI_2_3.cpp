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

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int m[50][50];
int dist[1<<10+3][50][50];

int n;

int count_sorry(int x){

	int ans=0;
	for(int i=0;i<=10;i++){
		if(x&(1<<i))
			ans++;
	}
	return ans;
}

void bfs( pii v ){

	queue < pair<pii,int> > fila;

	int maskpai = 0 | (1<<m[v.fst][v.snd]);

	dist[maskpai][v.fst][v.snd]= count_sorry(maskpai);
	
	fila.push( mp(v, maskpai) );

	while(!fila.empty()){

		pii pai = fila.front().fst;
		maskpai = fila.front().snd;

		fila.pop();

		int &dpai= dist[maskpai][pai.fst][pai.snd];

		fr(i,4){

			pii filho=pai;

			filho.fst+=dx[i];
			filho.snd+=dy[i];

			if(filho.fst>=n || filho.fst<0 || filho.snd<0 || filho.snd>=n)
				continue;

			int maskfilho = maskpai | (1<< m[filho.fst][filho.snd] );

			int &dfilho = dist[maskfilho][filho.fst][filho.snd];

			int new_dist = count_sorry(maskfilho);

			if(dfilho>new_dist){
				dfilho=new_dist;
				fila.push( mp(filho,maskfilho) );
			}

		}

	}

}

int main(){

	int t;
	cin >> t;
	
	while(t--){

		int sx,sy,ex,ey;

		cin >> n;
		
		fr(i,n){
			fr(j,n){
				cin >> m[i][j];
			}
		}

		cin >> sx >> sy >> ex >> ey;

		ms(dist,INF);

		bfs( mp(sx,sy) );

		int ans=INF;
		fr(i,1024)
			ans=min(ans,dist[i][ex][ey]);
		
		cout << ans << endl;

	}

}
