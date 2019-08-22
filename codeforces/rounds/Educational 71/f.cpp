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
const int MOD = 1e9+7;
 
int sz=750;

ll memo[750][750];	//bucket[mod][soma]	
ll v[5100100];

void update(int x, ll y){
	v[x]+=y;
	for(int mod=1;mod<sz;mod++)
		memo[mod][x%mod]+=y;
}

ll query(int x, int y){
	if(x<sz)
		return memo[x][y];
	ll ans = 0;
	for(int i=y;i<=500000;i+=x)
		ans+=v[i];
	return ans;
}

int main(){
 
	fastio;

	int q; cin >> q;

	while(q--){
		int op,x,y;
		cin >> op >> x >> y;
		if(op==1){
			update(x,y);
		}
		else{
			cout << query(x,y) << endl;
		}

	}
 
}