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

#define otp(x) cout << x << endl
#define gnl cout << endl
#define pira cout << "pira" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int n,c;
int debt[10100];
int vis[10100];
vector<vii> nodes;

ll dfs(int v){

	vis[v]=1;

	ll dist=0;

	for(auto filho : nodes[v]){
		
		int id = filho.snd;
		int viagens = 0;

		if(vis[id])
			continue;

		ll aux = dfs(filho.snd);
		debt[v]+=debt[id];

		viagens = debt[id]/c;
		
		if(debt[id]%c!=0)
			viagens++;

		dist += 2*viagens*filho.fst;
		dist+=aux;

	}

	return dist;

}

int main(){
    
    cin >> n >> c;

    nodes.resize(n+1);

    frr(i,n){
    	int aux; cin >> aux;
    	debt[i]=aux;
    }

    fr(i,n-1){
    	int x,y,w;
    	cin >> x >> y >> w;
    	nodes[x].pb({w,y});
    	nodes[y].pb({w,x});
    }

    cout << dfs(1) << endl;

}

