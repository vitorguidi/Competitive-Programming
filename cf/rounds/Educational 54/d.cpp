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
typedef tuple<ll,int,int> edge;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

vector<pll> nodes[300600];
ll d[300600];
int hgt[300600];
int pai[300600];
int used[300600];

void dijkstra(int v){

	set<pair<ll,int>> fila;

	d[1]=0;
	hgt[1]=0;

	fila.insert({0ll,1});

	while(!fila.empty()){

		pair<ll,int> dad = *fila.begin();
		fila.erase(fila.begin());

		for(auto x : nodes[dad.snd]){
			if(d[x.snd]>d[dad.snd]+x.fst){

				fila.erase({d[x.snd],x.snd});

				pai[x.snd] = dad.snd;
				hgt[x.snd]=1+hgt[dad.snd];
				
				d[x.snd] = d[dad.snd] + x.fst;
				fila.insert({d[x.snd],x.snd});
			
			}
		}

	}

}

int main(){
    
	fastio;

	int n,m,k;
	cin >> n >> m >> k;

	map<pii,int> check;
	vector<pii> edges;

	frr(i,m){
		int x,y,w;
		cin >> x >> y >> w;
		nodes[x].pb({w,y});
		nodes[y].pb({w,x});
		edges.pb({x,y});
	}

	fr(i,300300)
		d[i]=llINF;

	dijkstra(1);

	for(int i=2;i<=n;i++){
		check[{pai[i],i}]=1;
		check[{i,pai[i]}]=1;
	}

	int inutil=0;
	
	fr(i,m){
		pii cara = edges[i];
		if(check[{cara.fst,cara.snd}] || check[{cara.snd,cara.fst}])
			used[i]=1;
		else
			inutil++;
	}

	set<pii> aux;

	for(int i=2;i<=n;i++)
		aux.insert({hgt[i],i});

	int old_m=m;

	m-=inutil;
	check.clear();

	while(m>k && !aux.empty()){

		auto it = aux.rbegin();
		pii atual = *it;
		aux.erase(atual);

		check[ {atual.snd,pai[atual.snd]} ]=1;
		check[ {pai[atual.snd],atual.snd} ]=1;
		
		m--;
	
	}

	fr(i,old_m){
		pii aresta = edges[i];
		if( check[{aresta.fst,aresta.snd}] || check[{aresta.snd,aresta.fst}] )
			used[i]=0;
	}

	cout << m << endl;

	fr(i,old_m	)
		if(used[i])
			cout << i+1 << " ";
	gnl;

}

