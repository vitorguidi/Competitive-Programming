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
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;
typedef vector< vector<ll> > matrix;
const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;
const ll mod = 1e9+9;

vector<vii> nodes,nodes2;
int dist[10100];

void dijkstra(int v){

	set<pii> fila;
	dist[v]=0;
	fila.insert(mp(0,v));

	while(!fila.empty()){
		
		pii pai = *fila.begin();
		fila.erase(fila.begin());

		for(auto filho : nodes2[pai.snd]){

			if( dist[filho.snd] > filho.fst + pai.fst){
				dist[filho.snd]=filho.fst + pai.fst;
				fila.insert( mp(dist[filho.snd] , filho.snd) );
			}

		}

	}

}

int main(){

	int c,v;
	cin >> c >> v;
	nodes.resize(c+1);
	nodes2.resize(c+1);

	fr(i,v){
		int x,y,w;
		cin >> x >> y >> w;
		nodes[x].pb({w,y});
		nodes[y].pb({w,x});

	}

	frr(i,c){
		for(auto edge : nodes[i]){
			for(auto edge2 : nodes[edge.snd]){
				nodes2[i].pb( mp(edge.fst + edge2.fst,edge2.snd) );
				nodes2[edge2.snd].pb( mp(edge.fst + edge2.fst,edge2.snd) );
			}
		}
	}

	ms(dist,INF);
	dijkstra(1);

	int ans = dist[c];
	if(ans==INF)	ans=-1;
	cout << ans << endl;

}