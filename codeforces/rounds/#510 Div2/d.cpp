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
#define pira cout << "pira" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

ll v[200200];
vector<ll> seg[800800];

vll merge(vll &a, vll &b){

	vector<ll> c;

	int inia=0,inib=0;
	int la = a.size(), lb = b.size();

	while(inia<a.size() && inib<b.size()){
	
		if(a[inia]<=b[inib]){
			c.pb(a[inia]);
			inia++;
		}
	
		else{
			c.pb(b[inib]);
			inib++;
		}

	}

	for(int i=inia;i<la;i++)
		c.pb(a[i]);

	for(int i=inib;i<lb;i++)
		c.pb(b[i]);

	return c;

} 

void build(int node, int l, int r){

	if(l==r){
		vll aux;
		aux.pb(v[r]);
		seg[node]=aux;
		return;
	}

	int mid = (l+r)/2;

	build(2*node,l,mid);
	build(2*node+1,mid+1,r);

	seg[node]=merge(seg[2*node],seg[2*node+1]);

}

ll query(int node, int l, int r, int a, int b, ll val){

	if(l>r || r<a || l>b)
		return 0;

	if(a<=l && r<=b){
		auto it = upper_bound(all(seg[node]),val);
		int val = seg[node].end()-it;
		return val;
	}

	int mid = (l+r)/2;

	int left = query(2*node,l,mid,a,b,val);
	int right = query(2*node+1,mid+1,r,a,b,val);

	return left+right;

}


int main(){
    
	fastio;

	ll n,t; cin >> n >> t;

	frr(i,n)
		cin >> v[i];
	frr(i,n)
		v[i]+=v[i-1];


	ll ans = 0;

	build(1,1,n);
	frr(i,n){
		ll tgt = v[i]-t;
		if(v[i]<t)	ans++;
		ans+=query(1,1,n,1,i-1,tgt);
	}

	cout << ans << endl;

}

