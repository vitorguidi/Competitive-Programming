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

vi nodes[200200];
ll nf[200200];
int hgt[200200];
int vis[200200];
int n; 
ll ans = 0;

int dfs(int v){

	vis[v]=1;
	int cnt=0;
	
	for(auto x : nodes[v]){
		
		if(vis[x])
			continue;
		
		hgt[x]=1+hgt[v];
		cnt+=1+dfs(x);
	
	}
	
	nf[v]=cnt;
	return cnt;

}

void dfs2(int v){

	vis[v]=1;

	for(auto x : nodes[v]){
		
		if(vis[x])
			continue;

		ans+=(1ll+nf[x])*(n-nf[x]-1ll);

		dfs2(x);
	}

}

int main(){
    
	fastio;

	cin >> n;

	fr(i,n-1){
		int x,y;
		cin >> x >> y;
		nodes[x].pb(y);
		nodes[y].pb(x);
	}

	dfs(1);
	ms(vis,0);
	dfs2(1);

	ll even =0,odd=0;
	frr(i,n){
		if(hgt[i]%2)
			odd++;
		else
			even++;	
	}

	ans+=(even*odd);
	ans/=2ll;

	cout << ans << endl;


}

