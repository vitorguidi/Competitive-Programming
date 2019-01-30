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
typedef vector<vector<ll>> matrix;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

int v[100100];
vi seg[400100];

vi merge(vi& a, vi& b){

	int inia=0;
	int inib=0;

	vi ans;

	while(inia<a.size() && inib<b.size()){

		if(a[inia]<=b[inib])
			ans.pb(a[inia++]);
		else
			ans.pb(b[inib++]);

	}

	while(inia<a.size())
		ans.pb(a[inia++]);

	while(inib<b.size())
		ans.pb(b[inib++]);

	return ans;

}

void build(int node,int l, int r){

	if(l==r){
		seg[node]={v[l]};
		return;
	}

	ll mid = (l+r)/2;

	build(2*node,l,mid);
	build(2*node+1,mid+1,r);

	seg[node]=merge(seg[2*node],seg[2*node+1]);

}

ll query(int node, int l, int r, int a, int b, ll val){

	if(l>b || r<a)		return 0;

	if(a<=l && r<=b){

		auto right = seg[node].end();
		auto left = upper_bound(all(seg[node]),val);
		ll aux = right-left;
		ll amt = seg[node].size()-aux;
		return amt;

	}

	ll mid = (l+r)/2;

	return query(2*node,l,mid,a,b,val) + query(2*node+1,mid+1,r,a,b,val);

}

int main(){

	fastio;

	int n,q; cin >> n >> q;

	frr(i,n)	cin >> v[i];

	build(1,1,n);

	fr(i,q){
		
		int x,y,k;
		cin >> x >> y >> k;
		
		ll ini = -2*(ll)1e9;
		ll end = 2*(ll)1e9;

		ll ans;

		while(ini<=end){

			ll mid = (ini+end)/2;
			ll amt = query(1,1,n,x,y,mid);
			if(amt<k){
				ini=mid+1ll;
				ans=mid;
			}
			else
				end=mid-1;	
		
		}

		cout << ans+1ll << endl;

	}

}