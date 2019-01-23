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
typedef vector<pll> vll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

ll adj[110][110];

int main(){

	fastio;

	int n,e,t;
	cin >> n >> e >> t;

	frr(i,n)
		frr(j,n)
			adj[i][j]=llINF;

	frr(i,n)
		adj[i][i]=0;

	int m; cin >> m;

	frr(i,m){
		int a,b;
		ll c;
		cin >> a >> b >> c;
		adj[a][b] = min<ll>(adj[a][b],c);
	}

	frr(k,n)
		frr(i,n)
			frr(j,n)
				adj[i][j]=min<ll>(adj[i][k]+adj[k][j],adj[i][j]);

	int cnt = 0;

	frr(i,n){
		cnt+=(adj[i][e]<=t);
	}

	cout << cnt << endl;

}