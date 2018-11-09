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

double d[70][70];
int caso;

void solve(){


	fr(i,70)
		fr(j,70)
			d[i][j]=1e18;

	fr(i,70)
		d[i][i]=0;


	map<string,int> id;
	map<int,string> rid;
	map<int,tuple<int,int,int>> coord;

	int p; cin >> p;
	
	
	fr(i,p){
	
		string s;
		ll x,y,z;
	
		cin >> s >> x >> y >> z;

		id[s]=i;
		rid[i]=s;
	
		coord[i]=make_tuple(x,y,z);
	
	}

	fr(i,p){
		fr(j,p){

			if(i==j)	continue;
			
			ll d1 = abs<ll>( get<0>(coord[i]) - get<0>(coord[j]) );
			d1*=d1;

			ll d2 = abs<ll>( get<1>(coord[i]) - get<1>(coord[j]) );
			d2*=d2;

			ll d3 = abs<ll>( get<2>(coord[i]) - get<2>(coord[j]) );
			d3*=d3;

			ll dist = d1+d2+d3;

			d[i][j]=d[j][i]=sqrt((double)dist);

		}
	}

	int w; cin >> w;
	
	fr(i,w){
		string x,y;
		cin >> x >> y;
		int l,m;
		l=id[x];
		m=id[y];
		d[l][m]=0;
	}

	

	fr(k,p)
	fr(i,p)
	fr(j,p)
		d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	

	int q; cin >> q;

	cout << "Case " << ++caso << ":" << endl;

	fr(i,q){
		string a,b;
		cin >> a >> b;
		cout << "The distance from " << a <<" to " << b << " is " << (ll)(d[id[a]][id[b]]+0.5) << " parsecs." << endl;
	}

}

int main(){

	fastio;

	int t; cin >> t;
	while(t--)	solve();

}
