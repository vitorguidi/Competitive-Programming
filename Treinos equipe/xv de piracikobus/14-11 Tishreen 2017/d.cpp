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

int adj[25],p;

int cont_mask(int mask){
	int girl=(1<<p)-1; 
	for(int i=0;i<p;i++){
		if(mask & (1<<i))
			girl &= adj[i];
	}
	return(__builtin_popcount(girl));
}

void solve(){
	int n; 
	cin>>p>>n; 
	ms(adj,0); 
	int x,y;
	fr(i,n){
		cin>>x>>y; 
		x--; 
		y--;
		adj[x] |= (1<<y);
	}
	int mx=p; 
	
	for(int i=1;i<(1<<p);i++){
		int aux; 
		aux=__builtin_popcount(i)+cont_mask(i); 
		mx=max(mx,aux);
	}
	cout<<mx<<endl;
}

int main(){

	fastio;
	int t; 
	cin>>t; 
	while(t--) solve();


}
