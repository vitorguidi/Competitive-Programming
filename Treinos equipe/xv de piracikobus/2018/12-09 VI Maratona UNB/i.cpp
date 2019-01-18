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

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

int inicial[250][250];
ll brute[30][30];
ll cost[30][30];
int pai[30][30];
int m,n,c; 

void thiago(int v){

	set<pair<ll,int>> fila;
	fila.insert({0,v});

	while(!fila.empty()){

		pair<ll,int> anciao = *fila.begin();
		fila.erase(fila.begin());

		frr(i,c){

			ll dist = anciao.fst + cost[anciao.snd][i];

			if(brute[v][i]>dist){

				brute[v][i]=dist;
				pai[v][i]=anciao.snd;
			
				fila.insert({brute[v][i],i});
			
			}

		}

	}

}

int main(){

	fastio;

	cin >> m >> n >> c;

	frr(i,m)
		frr(j,n)
			cin >> inicial[i][j];

	frr(i,c)
		frr(j,c)
			cin >> cost[i][j];

	fr(i,30)	pai[i][i]=i;

	fr(i,30)
		fr(j,30)
			brute[i][j]=llINF;

	fr(i,30)	brute[i][i]=0;

	frr(i,c)	thiago(i);

	ll best = (ll)1e18;
	int color = -1;

	frr(k,c){

		ll aux = 0;

		frr(i,m)
			frr(j,n)
				aux+=brute[inicial[i][j]][k];

		if(aux<best){
			best=aux;
			color=k;
		}

	}

	vector<tuple<int,int,int>> comandos;
	int cnt = 0;

	frr(i,m){
		frr(j,n){

			if(inicial[i][j]==color)	continue;

			vector<int> pais;

			int origem = inicial[i][j];
			int cara = color;

			while(pai[origem][cara]!=cara){
				pais.pb(cara);
				cara=pai[origem][cara];
			}
			reverse(all(pais));

			for(auto x : pais){
				cnt++;
				tuple<int,int,int> aux;
				get<0>(aux)=i;
				get<1>(aux)=j;
				get<2>(aux)=x;
				comandos.pb(aux);
			}

		}
	}

	cout << best << " " << cnt << endl;
	for(auto x : comandos)
		cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) << endl;

}
