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

set<int> adj[1010];
int color[1010];

int main(){

	fastio;

	int n,m,k;
	cin >> n >> m >> k;

	fr(i,m){
		int a,b;
		cin >> a >> b;
		adj[a].insert(b);
		adj[b].insert(a);
	}

	int clk=1;

	frr(i,n){

		if(color[i])	continue;
		
		color[i]=clk;
		
		frr(j,n){
			if(j==i)
				continue;
			if(adj[i].count(j))
				continue;
			color[j]=clk;
		}

		clk++;
	
	}

	bool flag = true;

	frr(i,n){
		for(auto x : adj[i])
			if(color[i]==color[x])
				flag=false;
	}

	frr(i,n){
		frr(j,n){
			if(i==j)	continue;
			if(adj[i].count(j))	continue;
			if(color[i]!=color[j])
				flag=false;
		}
	}

	if(!flag || clk>k+1){
		puts("-1");
		return 0;
	}

	frr(i,n)
		cout << color[i] << " ";
	gnl;
}
