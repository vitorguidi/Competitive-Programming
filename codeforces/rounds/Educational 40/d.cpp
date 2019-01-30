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

vi nodes[1010];
int dist[1010];
int dist2[1010];
int edges[1010][1010];

void bfs(int v){

	ms(dist,INF);
	dist[v]=0;
	
	queue<int> fila;
	fila.push(v);

	while(!fila.empty()){
		
		int pai = fila.front();
		fila.pop();
		
		for(auto x : nodes[pai]){
			if(1+dist[pai]<dist[x]){
				fila.push(x);
				dist[x]=1+dist[pai];
			}
		}
	
	} 

}

int main(){
    
	fastio;

	int n,m,s,d; cin >> n >> m >> s >> d;

	fr(i,m){
		int x,y; cin >> x >> y;
		nodes[x].pb(y);
		nodes[y].pb(x);
		edges[x][y]=1;
		edges[y][x]=1;
	}

	bfs(d);

	frr(i,n)
		dist2[i]=dist[i];

	bfs(s);

	int cnt=0;
	frr(i,n){
		for(int j=i+1;j<=n;j++){
		
			if(edges[i][j])	continue;

			int d1=1+dist[i]+dist2[j];
			int d2=1+dist[j]+dist2[i];

			int new_d=min(d1,d2);

			if(new_d>=dist[d])	cnt++;

		}
	}

	cout << cnt << endl;

}

