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

struct point{
	ll x,y,z;
};

vector<vi> nodes;
int n;
point v[1010];
ll d[1010][1010];
int vis[1010];

void printa(){

	frr(i,n){
		frr(j,n){
			cout << d[i][j] << " ";
		}
		gnl;
	}

}

ll calc(int i, int j){
	
	ll ans = 0;

	ans+= ( v[i].x - v[j].x )*( v[i].x - v[j].x);
	ans+=( v[i].y - v[j].y )*( v[i].y - v[j].y );
	ans+=( v[i].z - v[j].z )*( v[i].z - v[j].z );

	return ans;

}

void fill(double r){

	nodes.clear();
	nodes.resize(n+1);

	frr(i,n){

		nodes[i].resize(n+1);
		
		frr(j,n){

			if(i==j) continue;
			

			double aux = 4*r-double(d[i][j]);
			if(aux>=0)
				nodes[i].pb(j);
		}

	}

}

void dfs(int v){

	vis[v]=1;

	fr(i,nodes[v].size()){

		int filho = nodes[v][i];

		if(vis[filho])
			continue;

		dfs(filho);

	}

}

bool check(double r){

	fill(r);

	ms(vis,0);
	dfs(1);

	//dbg(r);

	frr(i,n){
		if(!vis[i]){
			
			return false;
		}
	}

	return true;

}

int main(){

	cin >> n;

	frr(i,n)
		cin >> v[i].x >> v[i].y >> v[i].z;
	
	frr(i,n){
		frr(j,n){
			if(i==j) continue;
			d[i][j]=calc(i,j);
		}
	}

	double ini = 0;
	double end = 4*1e18;
	double mid;

	frr(i,100){

		mid = (ini+end)/2;

		if(check(mid))
			end=mid;
		else
			ini=mid;

	}

	cout << setprecision(5) << fixed;
	cout << pow(mid,0.5) << endl;

}