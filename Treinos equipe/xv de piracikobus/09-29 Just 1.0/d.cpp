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

int chave;
int n,m,k;
int id[20];
vector<pair<int,pii>> edges;
vector<pair<int,pii>> edges2;

int find(int x){
	if(id[x]==x)	return x;
	return id[x]=find(id[x]);
}

void join(int a, int b){
	a=find(a);b=find(b);
	if(a==b)	return;
	id[a]=b;
}


ll brute(int mask){

	fr(i,20)	id[i]=i;
	edges2.clear();


	for(auto x : edges){
		if( ( (1<<x.snd.fst)&mask ) && ( (1<<x.snd.snd)&mask ) )
			edges2.pb( mp(x.fst, mp(x.snd.fst,x.snd.snd) ) );
	}

	sort(all(edges2));

	ll ans = 0;

	for(auto x : edges2){
		if(find(x.snd.fst)!=find(x.snd.snd)){
			ans+=x.fst;
			join(x.snd.fst,x.snd.snd);
		}
	}

	set<int> lol;

	fr(i,n){
		if( ( (1<<i)&mask ) == 0 )	continue;
		lol.insert(find(i));
	}

	if(lol.size()!=1)	return llINF; 

	return ans;

}

void solve(){

	cin >> n >> m >> k;
	chave = 0;
	
	edges.clear();

	fr(i,m){
		int u,v,c;
		cin >> u >> v >> c;
		u--;v--;
		edges.pb(mp(c,mp(u,v)));
	}
	fr(i,k){
		int x; cin >> x;
		x--;
		chave=chave|(1<<x);
	}

	ll ans = llINF;
	fr(i,(1<<n)){
		if( ( (i^chave)&chave )!=0 )
			continue;
		ans=min<ll>(brute(i),ans);
	}

	cout << ans << endl;
}

int main(){

	fastio;
	int t; cin >> t;
	while(t--)	solve();

}