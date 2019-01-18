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
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int dist[550][550];
char grid1[550][550],grid2[550][550];
char grid[550][550];
int n,m;

bool valid(pii x){
	return x.fst>=0 && x.fst<n && x.snd>=0 && x.snd<m;
}

void bfs(){

	ms(dist,INF);
	dist[0][0]=0;

	queue< tuple<int,int,int> > fila;

	tuple<int,int,int> aux;

	fr(i,3)
		get<1>(aux)=0;

	fila.push(aux);

	while(!fila.empty()){

		tuple<int,int,int> origin = fila.front();
		fila.pop();

		pii pai = {get<1>(origin),get<2>(origin)};
		int distnow = get<0>(origin);

		fr(i,4){

			pii filho = {pai.fst+dx[i],pai.snd+dy[i]};

			if(!valid(filho))	continue;
			if(grid[filho.fst][filho.snd]=='#')	continue;

			if(dist[filho.fst][filho.snd]>distnow+1){

				dist[filho.fst][filho.snd]=distnow+1;
			
				tuple<int,int,int> novo;
				
				get<0>(novo)=distnow+1;
				get<1>(novo)=filho.fst;
				get<2>(novo)=filho.snd;
				
				fila.push(novo);
			
			}

		}

	}

}

int main(){

	fastio;

	cin >> n >> m;
	
	string s;
	getline(cin,s);

	fr(i,n){
		getline(cin,s);
		fr(j,m){
			grid1[i][j]=s[j];
		}
	}

	getline(cin,s);

	fr(i,n){
		getline(cin,s);
		fr(j,m){
			grid2[i][j]=s[j];
		}
	}

	fr(i,550)
		fr(j,550)
			grid[i][j]=grid1[i][j];


	bfs();
	int sp1 = dist[n-1][m-1];

	fr(i,550)
		fr(j,550)
			grid[i][j]=grid2[i][j];

	bfs();
	int sp2 = dist[n-1][m-1];

	fr(i,550)
		fr(j,550){
			if(grid1[i][j]=='#' || grid2[i][j]=='#')
				grid[i][j]='#';
			else
				grid[i][j]='.';
		}

	bfs();
	int sp3 = dist[n-1][m-1];

	if(sp1!=sp2)
		puts("NO");
	else if(sp3!=sp1 || sp3!=sp2)
		puts("NO");
	else if(sp1==INF || sp2==INF)
		puts("NO");
	else
		puts("YES");

}
