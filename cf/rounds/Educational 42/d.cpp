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
typedef vector<pll> vll;
const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

bool comp(pll a, pll b){
	return a.snd<b.snd;
}

int main(){
    
	fastio;

	ll n; cin >> n;
	
	set<pll> v;
	vll ans;
	
	fr(i,n){
		ll x; cin >> x;
		v.insert({x,i});
	}

	while(!v.empty()){

		auto it = v.begin();
		auto prox = it;
		prox++;

		if(prox==v.end() || prox->fst!=it->fst){
			ans.pb(*it);
			v.erase(it);
		}
		else{
			pll novo = {2ll*(it->fst),prox->snd};
			v.erase(it);
			v.erase(prox);
			v.insert(novo);
		}	
	
	}

	sort(all(ans),comp);

	cout << ans.size() << endl;
	for(auto x : ans)
		cout << x.fst << " ";
	gnl;

}

