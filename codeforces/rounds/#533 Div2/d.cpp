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

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

char grid[1010][1010];
int speed[1010];
int cnt[10];

int n,m,p;


int dist[1010][1010];
queue<tuple<int,int,int>> filas[10];

int colored;

bool valid(int x, int y){
	return x>=0 && x<n && y>=0 && y<m && grid[x][y]=='.';
}

void bfs(int player, int turn){

	int last = turn*speed[player];

	queue<tuple<int,int,int>> aux;
	queue<tuple<int,int,int>> &q = filas[player];

	while(!q.empty()){

		tuple<int,int,int> u = q.front();
		q.pop();
		
		int x = get<1>(u);
		int y = get<2>(u);
		int cost = get<0>(u);

		fr(i,4){
			
			int xf = x+dx[i];
			int yf = y+dy[i];

			if(valid(xf,yf)){

				int new_cost = 1 + cost;
				if(new_cost>turn*speed[player] + 1)	continue;
				grid[xf][yf]='0'+player;
				dist[xf][yf]=new_cost;

				tuple<int,int,int> nova = make_tuple(new_cost,xf,yf);
				
				colored++;
				cnt[player]++;
				
				int bord = 0;

				fr(i,4){
					int xn = xf+dx[i];
					int yn = yf + dy[i];
					if(valid(xn,yn))	bord++;
				}

				if(!bord)	continue;

				if(new_cost==turn*speed[player])
					aux.push(nova);
				
				else
					q.push(nova);

			}

		}

	}



	swap(aux,q);

}

int main(){
    
	fastio;

	cin >> n >> m >> p;

	frr(i,p)	cin >> speed[i];

	int tot=0;

	string s;
	getline(cin,s);
	ms(dist,INF);


	fr(i,n){

		getline(cin,s);
		
		fr(j,m){
			
			grid[i][j]=s[j];
			
			if(s[j]=='.')
				tot++;
			
			else if(s[j]!='#'){
				int id = s[j]-'0';
				cnt[id]++;
				filas[id].push(make_tuple(0,i,j));
				dist[i][j]=0;
			}

		}

	}

	int turn = 1;
	
	while(colored!=tot){
		int old = colored;
		frr(i,p)	bfs(i,turn);
		if(old==colored)	break;
		turn++;
	}


	frr(i,p)	cout << cnt[i] << " ";
	gnl;

}
