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

int main(){

	fastio;

	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vi v;
		fr(i,n){
			int x; cin >> x;
			v.pb(x);
		}
		int mx = 0;
		fr(i,n){
			fr(j,n){
				if(i==j)	continue;
				int aux = v[i]^v[j];
				mx=max(mx,__builtin_popcount(aux));
			}
		}
		cout << mx << endl;
	}
}