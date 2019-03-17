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
#define olar cout << "pira" << endl
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll; 

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int adj[20][20];
int memo[20][1<<20];
int n, root;

int pd(int u, int mask){

	if(__builtin_popcount(mask)==n){
		if(adj[u][0]!=INF)
			return adj[u][0];
		return INF;
	}

	int& pdm = memo[u][mask];
	if(pdm!=-1)	return pdm;
	
	pdm=INF;
	
	fr(i,n){
		if((1<<i)&mask)	continue;
		pdm=min(pdm,adj[u][i]+pd(i,mask|(1<<u)));
	}

	return pdm;

}

int main(){

	fastio;

	cin >> n;

	fr(i,n)
		fr(j,n)	cin >> adj[i][j];

	ms(memo,-1);

	int ans = INF;

	cout << pd(0,0) << endl;
	
} 