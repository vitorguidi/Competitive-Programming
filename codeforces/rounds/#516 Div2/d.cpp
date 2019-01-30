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
typedef tuple<int,int,int,int> state;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;


int d[2020][2020];
int grid[2020][2020];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int n,m,r,c,x,y;


bool in_grid(int a, int b){
	return (a>=0 && a<n) && (b>=0 && b<m);
}

void dijkstra(pii cara){

	set<state> fila;

	ms(d,INF);
	d[cara.fst][cara.snd]=0;
	
	state aux = make_tuple(0,0,cara.fst,cara.snd);
	fila.insert(aux);

	while(!fila.empty()){

		state pai = *fila.begin();
		fila.erase(fila.begin());

		fr(i,4){

			int xf= get<2>(pai) + dx[i];
			int yf= get<3>(pai) + dy[i];

			if(!grid[xf][yf])		continue;
			if(!in_grid(xf,yf))		continue;

			state novo = make_tuple( get<0>(pai)+(i==3),get<1>(pai)+(i==1),xf,yf );

			if(get<0>(novo)>x || get<1>(novo)>y)	continue;

			if(get<0>(novo) < d[xf][yf]){
				fila.insert(novo);
				d[xf][yf]=get<0>(novo);
			}

		}


	}

}

int main(){
    
	fastio;

	cin >> n >> m >> r >> c >> x >> y;

	string s;
	getline(cin,s);

	fr(i,n){
		getline(cin,s);
		fr(j,m){
			if(s[j]=='.')
				grid[i][j]=1;
		}
	}

	r--;c--;
	dijkstra({r,c});

	int cnt = 0;

	fr(i,n)
		fr(j,m)
			if(d[i][j]!=INF)
				cnt++;

	cout << cnt << endl;

}

