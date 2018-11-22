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

	int n; cin >> n;
	
	ll sum=0;
	ll x;
	
	fr(i,n){
		cin >> x;
		sum+=x;
	}

	int m; cin >> m;

	vii times;

	fr(i,m){
		ll l,r;
		cin >> l >> r;
		times.pb({l,r});
	}

	sort(all(times));

	fr(i,m){

		ll l = times[i].fst;
		ll r = times[i].snd;
		
		if(l<=sum && sum<=r){
			cout << sum << endl;
			return 0;
		}

		if(l>=sum){
			cout << l << endl;
			return 0;
		}

	}

	cout << -1 << endl;

}

