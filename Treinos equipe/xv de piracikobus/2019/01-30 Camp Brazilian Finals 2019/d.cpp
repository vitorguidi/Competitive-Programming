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

ll adj[110][110];
ll memo[1<<14][15];

vector<pii> travels;
map<int,int> id;

int n,m,b,z; 
int quantas;

ll pd(int mask, int ind){

	pii prev_trip = travels[ id[ind] ];
	int old_town = prev_trip.snd;

	if( __builtin_popcount(mask)==quantas ){
		//puts("bananan");
		//dbg(adj[old_town][b]);
		return adj[old_town][b];
	}

	ll &pdm = memo[mask][ind];
	if(pdm!=-1)	return pdm;

	pdm=llINF;
	
	fr(i,quantas){
	
		if( (1ll<<i)&mask )	continue;

		int tgt = travels[ id[i] ].snd;
		int from = travels[ id[i] ].fst;
		
		int new_mask = mask|(1ll<<i);

		ll take =  adj[old_town][from] + adj[from][tgt] + pd(new_mask,i);
	
		pdm=min<ll>( pdm , take);
	
	}

	return pdm;


}

void solve(){

	cin >> n >> m >> b;

	fr(i,110)
		fr(j,110)
			adj[i][j]=llINF;

	fr(i,110)	adj[i][i]=0;


	fr(i,m){
		int a,b;
		ll w;
		cin >> a >> b >> w;
		adj[a][b]=min<ll>(adj[a][b],w);
		adj[b][a]=min<ll>(adj[b][a],w);
	}

	frr(k,n){

		frr(i,n)
			frr(j,n)
				adj[i][j]=min<ll>(adj[i][j],adj[i][k]+adj[k][j]);

	}

	// frr(i,n){
	// 	frr(j,n){
	// 		cout << adj[i][j] << " ";
	// 	}
	// 	gnl;
	// }

	cin >> z;		//numero de tipos de viagens

	ms(memo,-1);
	quantas=0;
	travels.clear();
	
	fr(i,z){
		
		int a,b,amt;
		cin >> a >> b >> amt;
		travels.pb({a,b});
			
		fr(j,amt)
			id[quantas++]=i;

	}

	id[quantas]=z;
	travels.pb({b,b});

	cout << pd( 0 , quantas) << endl;

}

int main(){

	fastio;

	int t; cin >>t;
	while(t--)	solve();

}
