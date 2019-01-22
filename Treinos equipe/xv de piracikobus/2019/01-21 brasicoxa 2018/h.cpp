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
typedef vector<ll> vl;
typedef tuple<ll,ll,ll> edge;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

ll ans = 0;
ll dist[100100],cost[100100];
vector<edge> nodes[100100];
int ori[100100];
map<pll,ll> are;
int vis[100100];

int main(){

	fastio;

	int n,m;
	cin >> n >> m;

	frr(i,n)	dist[i]=cost[i]=llINF;
	dist[1]=cost[1]=0;

	fr(i,m){
		ll a,b,l,c;
		cin >> a >> b >> l >> c;
		nodes[a].pb(make_tuple(l,c,b));
		nodes[b].pb(make_tuple(l,c,a));
	}

	set<edge> fila;
	fila.insert(make_tuple(0,0,1));

	while(!fila.empty()){

		edge pai = *fila.begin();
		fila.erase(fila.begin());

		int from = get<2>(pai);

		for(auto x : nodes[from]){

			int tgt = get<2>(x);
			ll wgt = get<0>(x);
			ll mnt = get<1>(x);

			if(dist[tgt]>dist[from]+wgt || (dist[tgt]==dist[from]+wgt && cost[tgt]>mnt)){

				dist[tgt]=dist[from]+wgt;
				cost[tgt]= mnt;

				fila.insert(make_tuple(dist[tgt],cost[tgt],tgt));
			
			}

		}

	}

	ori[1]=1;

	ll ans = 0;

	frr(i,n)
		ans+=cost[i];

	cout << ans << endl;


}