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

ll v[2020];
ll ans[2020][3];

int main(){
    
	fastio;

	int n; cin >> n;	

	frr(i,n)	cin >> v[i];

	if(n==1){
		cout << 0 << endl;
		return 0;
	}


	vector<tuple<int,int,int>> ans;

	for(int i=n;i>0;i--){
		ll sou = v[i]/n;
		ll target = sou*n + i;
		ll delta = target - v[i];
		if(delta<0)	delta+=n;
		ans.pb(make_tuple(1,i,delta));
		for(int j=1;j<=i;j++)	v[j]+=delta;
	}

	ans.pb(make_tuple(2,n-1,n));

	cout << n+1 << endl;

	for(auto x : ans)	cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) << endl;

}