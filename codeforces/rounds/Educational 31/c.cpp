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
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

vi nodes[100100];
int vis[100100];

ll dfs(int v){

	vis[v]=1;
	ll ans = 1;

	for(auto x : nodes[v]){
		if(vis[x])	continue;
		ans+=dfs(x);
	}

	return ans;

}

int main(){
    
	fastio;

	int n; cin >> n;

	frr(i,n){
		int x; cin >> x;
		nodes[i].pb(x);
	}

	vector<ll> comp;

	frr(i,n){
		if(vis[i])	continue;
		comp.pb(dfs(i));
	}

	sort(all(comp));

	if(comp.size()==1){
		cout << comp[0]*comp[0] << endl;
		return 0;
	}

	int len = comp.size();
	len--;
	ll val = comp[len];
	comp.pop_back();
	len--;
	comp[len]+=val;

	ll ans = 0 ;

	for(auto x : comp)
		ans+=x*x;

	cout << ans << endl;

}

