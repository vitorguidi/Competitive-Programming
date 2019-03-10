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
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;

int ans[110];

int main(){
    
	fastio;

	int n; cin >> n;

	vector<ll> v;

	frr(i,n){
		ll x; cin >> x;
		v.pb(x);
	}

	sort(all(v));
	
	if(n==2){
		for(auto x : v)	cout << x << " ";
			gnl;
		return 0;
	}

	reverse(all(v));

	int clk = 0;
	for(int i=0;i<n;i+=2){
		ans[clk]=v[i];
		clk++;
	}
	clk=n-1;
	for(int i=1;i<n;i+=2){
		ans[clk]=v[i];
		clk--;
	}

	fr(i,n)	cout << ans[i] << " ";
	gnl;

}