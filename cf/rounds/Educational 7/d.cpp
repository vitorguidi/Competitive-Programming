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

int v[2*500500];
// vi pos[500500];

int main(){
    
	int n; cin >> n;

	fr(i,n/2){
		int cara = 2*i+1;
		v[i]=cara;
		v[i+n-cara]=2*i+1;
	}
	fr(i,n/2){
		int cara = 2+2*i;
		v[n+i]=cara;
		v[n+i+n-cara]=2*i+2;
	}

	fr(i,2*n)
		if(!v[i])
			v[i]=n;

	fr(i,2*n)	cout << v[i] << " ";
	gnl;	

	// fr(i,2*n)	pos[v[i]].pb(i);

	// int ans = 0;

	// frr(i,n){
	// 	int dist = abs(pos[i][0]-pos[i][1]);
	// 	ans+=(n-i)*abs(dist+i-n);
	// }

	// cout << ans << endl;	

}
