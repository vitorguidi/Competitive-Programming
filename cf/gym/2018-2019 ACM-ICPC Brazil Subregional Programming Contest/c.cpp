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
typedef vector<ll> vl;
typedef vector<pll> vll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const ll MOD = 998244353;

ll bit[200200];
map<ll,ll> check;

void update(int ind, ll val){
	for(int i=ind;i<200200;i+=i&-i)
		bit[i]+=val;
}

ll query(int ind){
	ll ans=0;
	for(int i=ind;i>0;i-=i&-i)
		ans+=bit[i];
	return ans;
}

ll solve(vl& v){

	ms(bit,0);
	check.clear();
	
	int cnt=1;
	vl aux;

	for(auto x : v)
		aux.pb(x);

	sort(all(aux));

	for(auto x : aux){
		if(!check[x])
			check[x]=cnt++;
	}

	ll ans=0;

	for(auto x : v){
		ans+=query(200000)-query(check[x]);
		update(check[x],1);
	}

	return ans;

}

int main(){

	fastio;

	ll x,y;
	cin >> x >> y;
	cin >> x >> y;

	ll ans=0;

	vll v;

	for(ll i=0;i<x;i++){
		ll a,b; cin >> a >> b;
		v.pb({a,b});
	}

	ans+=1+x+y+x*y;

	sort(all(v));
	
	vl aux;
	fr(i,x)
		aux.pb(v[i].snd);
	
	ans+=solve(aux);
	
	aux.clear();
	v.clear();

	for(ll i=0;i<y;i++){
		ll a,b; cin >> a >> b;
		v.pb({a,b});
	}

	sort(all(v));
	fr(i,y)
		aux.pb(v[i].snd);

	ans+=solve(aux);

	cout << ans << endl;
	
}