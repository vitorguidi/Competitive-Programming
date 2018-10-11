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
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

map<int,pii> loc;

int d[3][11][11][11][11];
pii memo[120][3];

int grid[11][11];

int n; 

pii soma(pii a, pii b){
	return{a.fst+b.fst,a.snd+b.snd};
}

pii pd(int num, int cara){

	if(num==(n*n))	return {0,0};

	pii &pdm=memo[num][cara];
	if(pdm!=mp(-1,-1))	return pdm;

	int x0 = loc[num].fst;
	int y0 = loc[num].snd;

	int x = loc[num+1].fst;
	int y = loc[num+1].snd;

	pdm = {INF,INF};

	pdm=min(pdm, soma( {d[cara][x0][y0][x][y],0} , pd(num+1,cara))  );

	if(cara!=0)
		pdm=min(pdm, soma( {1+d[0][x0][y0][x][y],1} , pd(num+1,0) ) );
	
	if(cara!=1)
		pdm=min(pdm, soma( {1+d[1][x0][y0][x][y],1} , pd(num+1,1)) );
	
	if(cara!=2)
		pdm=min(pdm, soma( {1+d[2][x0][y0][x][y],1} , pd(num+1,2)) );

	
	return pdm;

}

bool in_grid(int x, int y){
	return (x>=0 && x<n && y>=0 && y<n);
}

vii adj(int cara, int x, int y){

	vii ans;

	if(cara==0){	//cavalo

		fr(i,n)
			fr(j,n)
				if(in_grid(i,j) && abs(x-i)*abs(y-j)==2)
					ans.pb({i,j});
	}

	else if(cara==1){	//bispo

		fr(i,n)
			fr(j,n)
				if(in_grid(i,j) && abs(x-i)==abs(y-j))
					ans.pb({i,j});

	}

	else{	//torre

		fr(i,n)
			fr(j,n)
				if(in_grid(i,j) && ( i==x || j==y ))
					ans.pb({i,j});

	}

	return ans;

}

void dijkstra(int cara, int x, int y){

	set< pair<int,pii> > fila;

	fr(i,n)
		fr(j,n)
			d[cara][x][y][i][j]=INF;

	d[cara][x][y][x][y]=0;

	pair< int,pii > ini;
	ini.fst=0;
	ini.snd.fst=x;
	ini.snd.snd=y;

	fila.insert(ini);

	while(!fila.empty()){

		pair< int,pii > pai = *fila.begin();
		fila.erase(fila.begin());

		vii filhos = adj(cara,pai.snd.fst,pai.snd.snd);

		for(auto filho : filhos){
			
			int xf = filho.fst;
			int yf = filho.snd;
		
			if( d[cara][x][y][xf][yf] > pai.fst+1){

				d[cara][x][y][xf][yf] = pai.fst+1;
				
				pair<int,pii> nova;
				nova.fst=pai.fst+1;
				nova.snd.fst=xf;
				nova.snd.snd=yf;

				fila.insert(nova);
			}

		}

	}

}

int main(){
    
	fastio;

	cin >> n;

	fr(i,n){
		fr(j,n){
			cin >> grid[i][j];
			loc[grid[i][j]]={i,j};
		}
	}

	fr(i,3)
		fr(j,n)
			fr(k,n)
				dijkstra(i,j,k);

	frr(i,n*n)
		fr(j,3)
			memo[i][j]={-1,-1};

	pii ans = {INF,INF};

	ans=min({pd(1,0),pd(1,1),pd(1,2)});

	cout << ans.fst << " " << ans.snd << endl;

}