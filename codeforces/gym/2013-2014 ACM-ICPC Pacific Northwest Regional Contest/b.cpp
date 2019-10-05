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

int n,k,m;
vector<pll> adj[110];

pll dist[110][110];

bool operator<(tuple<ll,ll,ll> a, tuple<ll,ll,ll> b){

	if(get<0>(a)!=get<0>(b))
		return get<0>(a)<get<0>(b);

	if(get<1>(a)!=get<1>(b))
		return get<1>(a)>get<1>(b);

	return false;

}

void dijkstra(ll ori, ll fuel){

	fr(i,110)
		dist[ori][i]=mp(1e18,1e18);

	dist[ori][ori] = mp(0,0);

	priority_queue< tuple<ll,ll,ll>, vector<tuple<ll,ll,ll>> > q;

	// set<tuple<ll,ll,ll>> q;
	//(numero recargas, combustivel atual, vertice)
	// q.insert(make_tuple(0,0,ori));
	q.push(make_tuple(0,0,ori));
	while(!q.empty()){

		// tuple<ll,ll,ll> from = *(q.begin());
		// q.erase(q.begin());

		tuple<ll,ll,ll> from = q.top();
		q.pop();

		ll u = get<2>(from);
		ll tem = get<1>(from);
		ll vezes = -get<0>(from);

		for(auto edj : adj[u]){

			ll v = edj.snd;
			ll cost = edj.fst;

			pll new_dist={1e18,1e18};

			if(tem>=cost){
				new_dist=mp(vezes,tem-cost);
			}
			else if(fuel>=cost){
				new_dist=mp(vezes+1,fuel-cost);
			}

			if(new_dist.fst<dist[ori][v].fst){
				dist[ori][v]=new_dist;
				q.push(make_tuple(-new_dist.fst,new_dist.snd,v));
			}
			else if(new_dist.fst==dist[ori][v].fst && new_dist.snd>dist[ori][v].snd){
				dist[ori][v]=new_dist;
				q.push(make_tuple(-new_dist.fst,new_dist.snd,v));
			}
			
		}

	}

}

bool check(ll cap){
	
	fr(i,n){
		dijkstra(i,cap);
		fr(j,n){
			pll aux = dist[i][j];
			if(aux.fst>k || aux.fst==1e18)
				return false;
		}
	}

	return true;


}

void go(){

	fr(i,110)
		adj[i].clear();

	cin >> n >> k >> m;

	fr(i,m){
		int a,b;
		ll d;
		cin >> a >> b >> d;
		adj[a].pb({d,b});
		adj[b].pb({d,a});
	}

	ll ini=1;
	ll end=1e12;

	ll best=1e18;

	while(ini<=end){
		ll mid=(ini+end)>>1;
		if(check(mid)){
			best=mid;
			end=mid-1;
		}
		else
			ini=mid+1;
	}

	cout << best << endl;

}

int main(){

	fastio;
 
	int q; cin >> q;
	while(q--)
		go();	
 
}