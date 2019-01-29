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
vi adj[100100];
double h[100100];
int vis[100100];
vector<double> v;

void dfs(int s,int pai,double p){
	vis[s] = 1;

	if(adj[s].size() == 1 && adj[s][0] == pai) v.pb(h[s]*p);

	double k;
	k = adj[s].size();
	
	if(pai != 0) k--;

	for(auto x : adj[s]){
		if(vis[x]) continue;
		h[x] = h[s] + 1;
		dfs(x,s,p/k);
	}

}

int main(){

	fastio;
	int n;
	cin >> n;
	if(n == 1){
		cout <<0<< endl;
		return 0;
	}
	fr(i,n-1){
		int a,b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	h[1] = 0;

	dfs(1,0,1);

	double k = v.size();
	double sum = 0;
	fr(i,k) sum += v[i];

	double ans = double(sum); 
	
	cout<<setprecision(15)<<fixed;

	cout << ans << endl;


}
