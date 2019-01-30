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
typedef tuple<int,int,int> cara;
const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int grid[1010][1010];
int d[1010][1010];
int dx[]={-1,-1,-1,0,1,1,1,0};
int dy[]={-1,0,1,1,1,0,-1,-1};

int n; 

bool in_grid(int a, int b){
	return (a>=0 && a<n) && (b>=0 && b<n);
}

int main(){
    
	fastio;

	cin >> n;
	int xq,yq; cin >> xq >> yq;
	xq--;yq--;	
	
	int xk,yk; cin >> xk >> yk;
	xk--;yk--;
	
	int x,y; cin >> x >> y;
	x--;y--;

	fr(i,n){
		fr(j,n){
			if(i==xq || j== yq)			grid[i][j]=1;
			if(abs(i-xq)==abs(j-yq))	grid[i][j]=1;
		}
	}

	ms(d,INF);
	d[xk][yk]=0;

	queue<cara> fila;
	fila.push(make_tuple(0,xk,yk));

	while(!fila.empty()){

		cara pai = fila.front();
		fila.pop();

		fr(i,8){
			
			int xf = get<1>(pai)+dx[i];
			int yf = get<2>(pai)+dy[i];

			int cost = get<0>(pai);

			if(!in_grid(xf,yf))	continue;
			if(grid[xf][yf])	continue;

			cost++;

			if(cost<d[xf][yf]){
				d[xf][yf]=cost;
				fila.push(make_tuple(cost,xf,yf));
			}

		}

	}


	if(d[x][y]!=INF)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;



}

