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

int d[120][100100];	//distancia[cidade][passadas]	
int clk=1;
int t; 

void solve(){

	int n,m; 
	map<string,int> id;
	cin >> n;

	int cnt=1;
	string s;

	ms(d,INF);
	d[1][0]=0;

	frr(i,n){
		cin >> s;
		id[s]=cnt++;
	}

	vector<tuple<int,int,int>> edges;

	cin >> m;

	frr(i,m){
		string ori,des;
		int cost;
		cin >> ori >> des >> cost;
		edges.pb(make_tuple(id[ori],id[des]	,cost));
	}
	
	frr(i,100050){

		frr(j,n)
			d[j][i]=d[j][i-1];


		for(auto x : edges){
			
			int ori = get<0>(x);
			int des = get<1>(x);
			int cost = get<2>(x);

			if(d[des][i]>d[ori][i-1]+cost)
				d[des][i]=d[ori][i-1]+cost;

		}

	}

	int q; cin >> q;

	cout << "Scenario #" << clk++ << endl;
	// dbg(n);
	// dbg(m);
	// dbg(q);
	
	frr(i,q){
		int k; cin >> k;
		if(d[n][k+1]==INF)
			cout << "No satisfactory flights" << endl;
		else
			cout << "Total cost of flight(s) is $" << d[n][k+1] << endl;
	}
	if(clk!=t+1)
		gnl;

}

int main(){

	fastio;

	cin >> t;
	frr(i,t)
		solve();

}