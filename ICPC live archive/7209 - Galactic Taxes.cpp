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
	typedef tuple<int,int,int> edge;

	const int INF = 0x3f3f3f3f;
	const ll llINF = 0x3f3f3f3f3f3f3f;
	const int MOD = 1e9+7;

	int n,m;
	vector<edge> nodes[1100];
	double dist[1100];
	int vis[1100];

	double calc(edge x, double t){
		double aux = t*double(get<0>(x))+double(get<1>(x));
		return aux;
	}

	double dijkstra(double t){

		fr(i,n) dist[i]=1e18;
		ms(vis,0);

		dist[0]=0.0;
		set<pair<double,int>> fila;

		fila.insert(make_pair(0.0,0));

		while(!fila.empty()){

			pair<double,int> pai = *fila.begin();
			fila.erase(fila.begin());

			int dad = pai.snd;

			if(vis[dad])	continue;
			vis[dad]=1;

			for(auto x : nodes[dad]){

				int filho = get<2>(x);

				double cost = calc(x,t);

				if(dist[filho]>dist[dad]+cost){

					dist[filho]=dist[dad]+cost;
					fila.insert({dist[filho],filho});
				
				}

			}

		}

		return dist[n-1];

	}

	void solve(){

		fr(i,n)	nodes[i].clear();

		fr(i,m){

			int x,y,a,b;
			cin >> x >> y >> a >> b;
			x--;y--;
			nodes[x].pb(make_tuple(a,b,y));
			nodes[y].pb(make_tuple(a,b,x));

		}

		double a = 0.0;
		double b = 24*60;

		fr(i,100){

			double k1 = a + (b-a)/3.0;
			double k2 = b - (b-a)/3.0;

			if(dijkstra(k1)>dijkstra(k2))
				b=k2;
			else
				a=k1;

		}

		dijkstra((a+b)/2.0);

		cout << dist[n-1] << endl;

	}

	int main(){

		fastio;

		cout << setprecision(5) << fixed;
		
		while(	cin >> n >> m)
			solve();

	}