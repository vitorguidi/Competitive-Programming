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

ll d[2020];	//distancia[cidade][passadas]	

void solve(){

	int n,m; cin >> n >> m;

	fr(i,2020)	d[i]=llINF;

	d[1]=0;

	vector<tuple<int,int,ll>> edges;

	frr(i,m){
		int x,y;
		ll cost;
		cin >> x >> y >> cost;
		edges.pb(make_tuple(x,y,cost));
	}

	frr(i,n-1){
		for(auto x : edges){
			int ori = get<0>(x);
			int des = get<1>(x);
			ll cost = get<2>(x);
			if(d[des]>d[ori]+cost)
				d[des]=d[ori]+cost;
		}
	}

	for(auto x : edges){
	
		int ori = get<0>(x);
		int des = get<1>(x);
		ll cost = get<2>(x);
	
		if(d[des]>d[ori]+cost){
			puts("possible");
			return;
		}
	
	}

	puts("not possible");

}

int main(){

	fastio;

	int t; cin >> t;
	while(t--)	solve();
}