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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int vis[200200],dist[200200];
int pai[200200];
vi nodes[200200];

void dfs(int v){

	vis[v]=1;

	for(auto x : nodes[v]){

		if(vis[x])
			continue;

		pai[x]=v;
		dist[x]=1+dist[v];
		dfs(x);
	}

}

int main(){

	int n;
	cin >> n;

	fr(i,n-1){
		int x,y;
		cin >> x >> y;
		nodes[x].pb(y);
		nodes[y].pb(x);
	}

	pai[1]=1;
	dfs(1);

	priority_queue<pii> fila;

	for(int i=2;i<=n;i++){
		if(dist[i]>2)
			fila.push({dist[i],i});
	}

	int ans = 0;

	while(!fila.empty()){

		pii aux = fila.top();
		fila.pop();
		int v = aux.snd;

		if(dist[v]<=2)
			continue;
		
		dist[ pai[v] ] = 1;
		ans++;
	
		for(auto x : nodes[ pai[v] ]){
			dist[x]=min(dist[x],2);
		}			

	}

	cout << ans << endl;

}