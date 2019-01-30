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

	vector<ll> v1,v2;

	ll n,m;
	cin >> n >> m;

	fr(i,n/2){
		int x; cin >> x;
		v1.pb(x);
	}
	for(int i=n/2;i<n;i++){
		int x; cin >> x;
		v2.pb(x);
	}

	v1.pb(0);
	v2.pb(0);

	vector<ll> repo2;
	set<ll> repo1;

	int len1=v1.size();
	int len2=v2.size();

	fr(i,1<<len1){
		ll ans = 0;
		fr(j,len1)
			if(i&(1<<j))
				ans+=v1[j];
		repo1.insert(ans%m);
	}

	fr(i , 1<<len2){
		ll ans = 0;
		fr(j,v2.size())
			if(i&(1<<j))
				ans+=v2[j]%m;
		repo2.pb(ans%m);
	}

	sort(all(repo2));

	ll best=0;

	for(auto x : repo1){

		int target = m-1-x;
		if(target<0)
			target+=m;
	
		auto it = upper_bound(all(repo2),target);	
		it--;
	
		best=max<ll>(best,(x+*it)%m);
	
	}

	cout << best << endl;


}

