#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

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
const int MAXN = 100100;

vector<vi> nodes,scc;

int pre[2020],low[2020],vis[2020];
int clk,val;
stack<int> pilha;

void dfs(int v){

	low[v]=pre[v]=clk++;
	pilha.push(v);
	vis[v]=1;

	for(auto filho : nodes[v]){
		if(!vis[filho])
			dfs(filho);
		low[v]=min(low[filho],low[v]);
	}

	if(low[v]!=pre[v])
		return;

	int node;
	vi temp;

	do{
		node=pilha.top();pilha.pop();
		low[node]=INF;
		temp.pb(node);
	}	while(!pilha.empty() && node!=v);

	val++;
	scc.pb(temp);

}

int main(){

	int n,m;

	while(cin>>n){
	
		if(!n)
			break;

		cin >> m;

		nodes.clear();
		scc.clear();
		nodes.resize(n+1);
		ms(vis,0);ms(low,0);ms(pre,0);
		val=0;

		fr(i,m){
			int x,y,z;
			cin >> x >> y >> z;
			nodes[x].pb(y);
			if(z==2)
				nodes[y].pb(x);
		}

		frr(i,n){
			if(!vis[i])
				dfs(i);
			val++;
		}
		if(scc.size()!=1)
			cout << 0 << endl;
		else
			cout << 1 << endl;

	}

}