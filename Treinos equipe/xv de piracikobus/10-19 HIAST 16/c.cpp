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
typedef tuple<int,int,int> state;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

vector<state> nodes[10100];
pii d[10100];

void dijkstra(int v){


	fr(i,10100)
		d[i]={INF,INF};

	d[v]={0,0};
	set<state> fila;


	fila.insert(make_tuple(0,0,v));

	while(!fila.empty()){

		state pai = *fila.begin();
		fila.erase(fila.begin());

		for(auto edge : nodes[get<2>(pai)]){

			int filho = get<0>(edge);
			int cost = get<1>(edge);
			int tipo = get<2>(edge);

			state novo = make_tuple(get<0>(pai),get<1>(pai),filho);

			if(tipo==1){
				get<0>(novo)+=cost;
				get<1>(novo)+=cost;
			}
			else
				get<1>(novo)+=cost;

			if( mp(get<0>(novo),get<1>(novo)) < d[filho] ){
				d[filho]={get<0>(novo),get<1>(novo)};
				fila.insert(novo);
			}

		}


	}

}

void solve(){

	int n,m;
	scanf("%d%d",&n,&m);
	
	fr(i,10100)
		nodes[i].clear();

	fr(i,m){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		
		nodes[a].pb(make_tuple(b,c,d));
		nodes[b].pb(make_tuple(a,c,d));
	
	}

	int x,y;
	scanf("%d%d",&x,&y);
	dijkstra(x);

	if(get<0>(d[y])==INF)
		printf("-1\n");
	else
		printf("%d %d\n",d[y].fst,d[y].snd);
}

int main(){

	int t;
	scanf("%d",&t);
	while(t--)	solve();
}