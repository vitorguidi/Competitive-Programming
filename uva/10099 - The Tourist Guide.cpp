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
int dist[110];
int clk=1;

void solve(){

	vector<tuple<int,int,int>> edges;

	ms(dist,-INF);

	fr(i,m){
		int x,y,w; cin >> x >> y >> w;
		edges.pb(make_tuple(x,y,w));
		edges.pb(make_tuple(y,x,w));
	}

	int s,d,t; cin >> s >> d >> t;

	dist[s]=INF;

	frr(i,n-1){

		for(auto x : edges){
	
			int ori = get<0>(x);
			int des = get<1>(x);
			int cost = get<2>(x)-1;

			int cap = min(dist[ori],cost);
			if(dist[des]<cap)
				dist[des]=cap;

		}

	}

	cout << "Scenario #"<<clk++<< endl;
	cout << "Minimum Number of Trips = " << ( d!=s ? (t+dist[d]-1)/dist[d] : 0 ) << endl << endl;



}

int main(){

	fastio;

	while(true){
		cin >> n >> m;
		if(!n)	break;
		solve();
	}

}