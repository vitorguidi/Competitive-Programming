#include "bits/stdc++.h"
using namespace std;
 
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define grtp greater<pair<int,int>>
 
#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
 
#define ms(x, v) memset(x, v, sizeof x)
#define all(x)	x.begin(),x.end()
#define dbg(x) cout << #x << " = " << x << endl
#define gnl cout << endl
#define say(oi)  cout << "hello" << endl;
 
const int INF = 0x3f3f3f3f;
const long long int llINF = 1e18;
 
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
int dist[10001];
int flag[10001];
 
void dijkstra(int v, vector< vector<pii> > &nodes){
 
	int atual;
	priority_queue <pii,vector<pii>,grtp> fila;
	
	ms(dist,INF);
	ms(flag,0);
 
	dist[v]=0;
	fila.push(mp(0,v));
	
	while( !fila.empty() ){
 
		atual=fila.top().snd;
		fila.pop();
		flag[atual]=1;
 
		fr( i,nodes[atual].size() ){
 
			int filho=nodes[atual][i].snd;
			int peso=nodes[atual][i].fst;
 
			if(flag[filho]==1)	continue;
			
			if(dist[filho]>dist[atual]+peso)	dist[filho]=dist[atual]+peso;
 
			fila.push( mp(dist[filho],filho) );
		}		
	}
}
 
int main(){
 
	int t;
	vector< vector<pii> > nodes;
	
	cin >> t;
	
	fr(i,t){
 
		int v,k,x,y,w;
		
		cin >> v >> k;
		nodes.resize(v+1);
 
		fr(i,k){
			cin >> x >> y >> w;
			nodes[x].pb( mp(w,y) );
		}
 
		int a,b;
		cin >> a >> b;
 
		dijkstra(a,nodes);
 
		if(dist[b]!=INF)	cout << dist[b] << endl;
		else				cout << "NO" << endl;
 
		nodes.clear();
	}
	
	return 0;
}	