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

vi nodes[5050];
int vis[5050];
int used[5050];

void dfs(int v){

	vis[v]=1;
	used[v]=1;
	
	for(auto x : nodes[v]){
		if(vis[x] || used[x])
			continue;
		dfs(x);
		break;
	}

}

int main(){
    
	fastio;

	int n; cin >> n;
	vi v;

	int cnt=0;
	map<int,int> coord;
	
	fr(i,n){
		int x; cin >> x;
		v.pb(x);
	}

	sort(all(v));

	for(auto x : v)
		if(!coord[x])
			coord[x]=cnt++;

	fr(i,n)
		v[i]=coord[v[i]];

	fr(i,n)
		for(int j=i+1;j<n;j++)
			if(v[i]<v[j])
				nodes[i].pb(j);
	
	int ans = 0;

	fr(i,n){
		if(used[i])	continue;
		ms(vis,0);
		dfs(i);
		ans++;
	}

	cout << ans << endl;

}

