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
const ll llINF = 0x3f3f3f3f3f3f3f;

int main(){
    
	fastio;

	vii a;
	int n; cin >> n;
	int last = INF;

	fr(i,n){
		int x; cin >> x;
		a.pb({x,i});
	}

	sort(all(a));
	int val = a[0].fst;

	vii b;

	for(auto x : a)
		if(x.fst==val)
			b.pb(x);

	int ans = INF;

	fr(i,b.size()-1)
		ans=min(ans,abs(b[i].snd-b[i+1].snd));

	cout << ans << endl;
}

