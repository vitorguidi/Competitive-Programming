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

bool comp(tuple<int,int,int> a,tuple<int,int,int> b){
	if(get<0>(a)==get<0>(b))
		return get<1>(a)<get<1>(b);
	return get<0>(a)<get<0>(b);
}

void solve(){

	int n; cin >> n;

	vector< tuple<int,int,int> > v;
	int ans[1010];
	ms(ans,0);

	fr(i,n){
		int l,r; cin >> l >> r;
		tuple<int,int,int> aux = make_tuple(l,i,r);
		v.pb(aux);
	}

	sort(all(v),comp);

	// for(auto x : v){
	// 	dbg(get<0>(x));
	// 	dbg(get<1>(x));
	// 	dbg(get<2>(x));
	// 	gnl;
	// }

	int t=1;
	for(auto x : v){
		t=max(t,get<0>(x));
		if(get<2>(x)>=t){
			ans[get<1>(x)]=t;
			t++;
		}
	}

	fr(i,n)
		cout << ans[i] << " ";
	gnl;

}

int main(){
    
	fastio;

	int t; cin >> t;
	while(t--)	solve();

}

