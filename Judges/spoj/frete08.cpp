//BEATRIZ QUE NAO SABE CODAR APROVA ESSE HEADER

#include "bits/stdc++.h"
using namespace std;

#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define grtp greater<pair<int,int>>
#define pq priority_queue

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x, v) memset(x, v, sizeof x)
#define all(x)	x.begin(),x.end()
#define dbg(x) cout << #x << " = " << x << endl
#define gnl cout << endl
#define olar()  cout << "olarr" << endl;

const int INF = 0x3f3f3f3f;
const long long int llINF = 1e18;

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

vector< vector<pii> > nodes;
int dist[1001];
int flag[1001];

void prim(int v){

	pq <pii,vector<pii>,grtp> fila;
	fila.push(mp(0,v));
	dist[v]=0;

	while(!fila.empty()){
		
		int pai = fila.top().snd;
		int dnow = fila.top().fst;
		fila.pop();
		flag[pai]=1;

		fr(i,nodes[pai].size()){

			int filho = nodes[pai][i].snd;
			int peso = nodes[pai][i].fst;
			
			if(flag[filho]==1)	continue;

			if(dist[filho]>peso){
				dist[filho]=peso;
				fila.push(mp(peso,filho));
			}
		
		}
	
	}

}

int main(){

	int n,m;
	int p,q,u;

	cin >> n >> m;

	ms(dist,INF);

	nodes.resize(n);

	fr(i,m){
		cin >> p >> q >> u;
		nodes[q].pb(mp(u,p));
		nodes[p].pb(mp(u,q));
	}
	prim(0);
	int cnt=0;
	fr(i,n)	cnt+=dist[i];
	cout << cnt << endl;

}	
