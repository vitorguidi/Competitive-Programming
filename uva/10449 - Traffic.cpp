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
#define olar cout << "pira" << endl
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll; 

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int n,m;
ll dist[220];
ll tag[220];
int clk=1;

void solve(){

	vii edges;

	frr(i,n)	cin >> tag[i];

	frr(i,n)	dist[i]=llINF;

	dist[1]=0;

	cin >> m;

	fr(i,m){
		int x,y; cin >> x >> y;
		edges.pb({x,y});
	}

	frr(i,n-1){

		for(auto x : edges){

			if(dist[x.fst]==llINF)	continue;

			ll cost = 	tag[x.snd]-tag[x.fst];
			cost*=cost*cost;

			if( dist[x.snd] > dist[x.fst] + cost )
				dist[x.snd] = dist[x.fst] + cost;
				
		}

	}

	vi bad;

	for(auto x : edges){
	
		if(dist[x.fst]==llINF)	continue;

		ll cost = 	tag[x.snd]-tag[x.fst];
		cost*=cost*cost;

		if( dist[x.snd] > dist[x.fst] + cost ){
			bad.pb(x.snd);
			dist[x.snd]=dist[x.fst] + cost;
		}
			
	}

	for(auto x : bad)	dist[x]=-llINF;

	int q; cin >> q;
		
	cout << "Set #"<<clk++<< endl;
	frr(i,q){
		int x; cin >> x;
		if(dist[x]<3 || dist[x]==llINF)
			cout << "?" << endl;
		else
			cout << dist[x] << endl;
	}


}

int main(){

	fastio;

	while(cin >> n)
		solve();

}