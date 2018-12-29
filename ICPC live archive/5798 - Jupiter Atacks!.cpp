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

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

ll b,p,len,n;

ll seg[400400];

ll fastxp(ll base, ll exp){
	ll ans = 1;
	while(exp){
		if(exp%2)
			ans*=base;
		base*=base;
		base%=p;
		ans%=p;
		exp/=2;
	}
	return ans;
}
ll invmod(ll x){
	return fastxp(x,p-2);
}

void update(int node, int l, int r, int ind, ll val){
	if(l==r){
		seg[node]=val*fastxp(b,len-l+1);
		seg[node]%=p;
		return;
	}
	int mid = (l+r)/2;
	if(ind<=mid)	update(2*node,l,mid,ind,val);
	else			update(2*node+1,mid+1,r,ind,val);
	seg[node]=seg[2*node]+seg[2*node+1];
	seg[node]%=p;
}

ll query(int node, int l, int r, int a, int b){
	if(l>b || r<a)	return 0;
	if(a<=l && r<=b)	return seg[node];
	int mid = (l+r)/2;
	return (query(2*node,l,mid,a,b)+query(2*node+1,mid+1,r,a,b))%p;
}

void solve(){

	ms(seg,0);

	fr(i,n){
		
		char op; cin >> op;
		int x,y; cin >> x >> y;

		if(op=='E')
			update(1,1,len,x,y);
		
		else{
			ll val = query(1,1,len,x,y);
			val*=invmod(fastxp(b,len-y+1));
			val%=p;
			cout << val << endl;
		}


	}

}

int main(){

	fastio;

	while(true){
		cin >> b >> p >> len >> n;
		if(!b)	break;
		solve();
		cout << "-"<< endl;
	}

}