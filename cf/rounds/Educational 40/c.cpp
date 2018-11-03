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
	vector<ll> v;

	ll last;
	cin >> last;
	v.pb(last);

	set<ll> aux;

	if(n==1){
		cout << "YES" << endl;
		cout << 1 << " " << last << endl;
		return 0;
	}

	fr(i,n-1){

		ll x; cin >> x;
		if(x==last){
			cout << "NO" << endl;
			return 0;
		}
		
		aux.insert(abs<ll>(x-last));
		last=x;
		v.pb(x);
	
	}

	auto it = aux.find(1);
	
	if(it!=aux.end())
		aux.erase(it);

	if(aux.size()>1){
		cout << "NO" << endl;
		return 0;
	}

	ll mx = 0;
	ll y;
	
	if(aux.size())
		y = *(aux.begin());
	else
		y=1;

	for(auto x : v)
		mx=max<ll>(mx,x);

	fr(i,n)
		v[i]--;

	if(y==1){
		cout << "YES" << endl;
		cout << mx << " " << 1 << endl;
		return 0;
	}

	for(int i =1;i<n;i++){
	
		int delta = abs(v[i]-v[i-1]);
		
		if(delta!=1 && (v[i]/y == v[i-1]/y)){
			cout << "NO" << endl;
			return 0;
		}
		if(delta==1 && (v[i]/y != v[i-1]/y)){
			cout << "NO" << endl;
			return 0;
		}

	}

	cout << "YES" << endl;
	cout << (mx+y-1)/y << "  " << y << endl;

}

