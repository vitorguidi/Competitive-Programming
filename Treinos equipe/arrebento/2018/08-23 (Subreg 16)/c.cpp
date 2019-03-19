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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

vii ops = { {0,1},{1,2},{2,3},{4,5},{5,6},{6,7},{0,4},{1,5},{2,6},{3,7} };
vii nodes[50000];
map<vi,int> mapa;
ll dist[50000];

vi troca(vi& a, int ind){
	vi aux = a;
	pii op = ops[ind];
	swap(aux[op.fst],aux[op.snd]);
	return aux;
}

void dijkstra(int v){
	
	ms(dist,INF);
	dist[v]=0;

	set<pii> fila;
	fila.insert({0,v});
	
	while(!fila.empty()){
	
		pii p = *fila.begin();
		fila.erase(fila.begin());
		int pai = p.snd;
		int cost = p.fst;
	
		for(auto x : nodes[pai]){
		
			int f = x.snd;
			int are = x.fst;
		
			if(dist[f]>are+cost){
				dist[f]=are+cost;
				fila.insert( mp(dist[f],f) );
			}

		}

	}
}

int main(){

	vi ini;
	vi end;

	fr(i,8){
		int aux;cin >> aux;
		ini.pb(aux);
	}

	fr(i,8){
		int aux; cin >> aux;
		end.pb(aux);
	}
	
	vi lol = ini;
	sort(all(lol));
	int cnt=0;
	do{
		mapa[lol]=cnt++;
	}while(next_permutation(all(lol)) );
	
	sort(all(lol));
	do{
		int ind = mapa[lol];
		fr(i,10){
			vi aux = troca(lol,i);
			pii op = ops[i];
			int cost = lol[op.fst]+lol[op.snd];
			int tgt = mapa[aux];
			nodes[ind].pb( mp(cost,tgt) );
			nodes[tgt].pb( mp(cost,ind) );

		}
	}while( next_permutation(all(lol)) );
	
	int vamo = mapa[ini];
	int dale = mapa[end];
	dijkstra(vamo);
	
	cout << dist[dale] << endl;
}