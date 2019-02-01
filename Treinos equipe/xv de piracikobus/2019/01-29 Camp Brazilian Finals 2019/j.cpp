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
typedef vector<ll> vll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

int sz[100100],id[100100];

vector<tuple<int,int,int>> edges;
vi perm;

set<int> grupo[100100];
map<ll,ll> mapa[100100];

vii nodes[100100];
int myxor[100100],vis[100100];
	
ll n,ans,clk=1;

int find(int a){

	if(id[a]==a)	return a;
	return find(id[a]);

}

ll comb(ll x){
	return (x*(x-1ll))/2ll;
}

void dfs(int v){

	vis[v]=clk;

	for(auto x : nodes[v]){

		int filho = x.snd;

		if(vis[filho]>=clk)	continue;
		myxor[filho]=myxor[v]^x.fst;
		dfs(filho);
	
	}

}

void join(int a, int b, int c){

	int old_a=a;
	int old_b=b;

	a=find(a);b=find(b);

	if(a==b)	return;

	if(sz[a]<sz[b]){
		swap(a,b);
		swap(old_a,old_b);
	}

	myxor[old_b]=myxor[old_a]^c;
	dfs(old_b);
	clk++;

	for(auto x : mapa[b])
		ans-=comb(x.snd);

	mapa[b].clear();

	for(auto x : grupo[b]){

		grupo[a].insert(x);

		ans-=comb(mapa[a][ myxor[x] ]);
		mapa[a][ myxor[x] ]++;
		ans+=comb(mapa[a][ myxor[x] ]);

	}

	id[b]=a;
	sz[a]+=sz[b];

}

int main(){

	fastio;

	cin >> n;

	fr(i,n-1){
		int a,b,z;
		cin >> a >> b >> z;
		edges.pb(make_tuple(a,b,z));
	}

	frr(i,n){
		sz[i]=1;
		id[i]=i;
		grupo[i].insert(i);
		mapa[i][0]++;
	}

	fr(i,n-1){
		int x; cin >> x;
		perm.pb(--x);
	}

	reverse(all(perm));

	vll coiso;

	for(auto x : perm){
		
		coiso.pb(ans);

		edge are = edges[x];

		int a = get<0>(are);
		int b = get<1>(are);
		int c = get<2>(are);
	
		join(a,b,c);
		
		nodes[a].pb({c,b});
		nodes[b].pb({c,a});
		
	
	}

	cout << ans << endl;
	reverse(all(coiso));

	for(auto x : coiso)
		cout << x << endl;

}