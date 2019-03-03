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

vector<pii> nodes[100100];
int dist[100100][3];
	int n,m;

void dijkstra(){

	ms(dist,INF);
	dist[1][0]=0;

	set<tuple<int,int,int>> q;

	q.insert(make_tuple(0,0,1));
	//dist,vert,parity

	while(!q.empty()){

		tuple<int,int,int> pai = *q.begin();
		q.erase(q.begin());

		int u = get<2>(pai);
		int par = get<1>(pai);
		ll d = get<0>(pai);

		for(auto x : nodes[u]){

			int v = get<1>(x);
			int w = get<0>(x);

			int np =(par+1)%3;

			if(dist[v][np]<=dist[u][par]+w)	continue;

			dist[v][np]=dist[u][par]+w;

			if(v!=n)	q.insert(make_tuple(dist[v][np],np,v));

		}

	}

}

int main(){

	fastio;

	cin >> n >> m;

	fr(i,m){
		ll u,v,w;
		cin >> u >> v >> w;
		nodes[u].pb({w,v});
		nodes[v].pb({w,u});
	}

	dijkstra();

	set<pair<int,string>> s;

	s.insert({dist[n][0],"me"});
	s.insert({dist[n][2],"Killua"});
	s.insert({dist[n][1],"Gon"});

	for(auto x : s)	cout << x.snd << endl;

}