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

int dist[1010][1010];	//distancia[cidade][passadas]	

int main(){

	fastio;

	int n,m; cin >> n >> m;

	vector<tuple<int,int,int>> edges;

	fr(i,m){
		int x,y,cost;
		cin >> x >> y >> cost;
		auto aux = make_tuple(x,y,cost);
		edges.pb(aux);
	}

	ms(dist,INF);
	dist[1][0]=0;

	for(int i=1;i<n;i++){

		frr(j,n)
			dist[j][i]=dist[j][i-1];

		for(auto x : edges){
			
			int ori = get<0>(x);
			int des = get<1>(x);
			int cost = get<2>(x);

			if( dist[des][i] > dist[ori][i-1] + cost )
				dist[des][i] = dist[ori][i-1] + cost ;
			
		}

	}

	int q; cin >> q;

	fr(i,q){
		int d,k; cin >> d >> k;
		if(dist[d][k+1]==INF)
			cout << "=[" << endl;
		else
			cout << "=] " << dist[d][k+1] << endl;	
	}

}