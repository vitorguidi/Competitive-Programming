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
const ll MOD = 1e9+7;

int v[100100];
pll seg[400400];

pll operator+(pll a, pll b){
	return mp(a.fst+b.fst,a.snd+b.snd);
}

void build(int node, int l, int r){
	
	if(l==r){
		seg[node]=mp(v[l]==0,v[l]==1);
		return;
	}
	
	int mid	= (l+r)/2;
	
	build(2*node,l,mid);		
	build(2*node+1,mid+1,r);

	seg[node] = seg[2*node] + seg[2*node+1];	

}

pll query(int node, int l, int r, int a, int b){	

	if (a>r || b<l)		return {0ll,0ll};		

	if(a<=l && r<=b)	return seg[node];	

	int mid=(l+r)/2;
	
	return query(2*node,l,mid,a,b) + query(2*node+1,mid+1,r,a,b);

}

ll fastxp(ll base, ll exp){

	ll ans = 1ll;

	while(exp){
		if(exp%2)
			ans*=base;
		base*=base;
		base%=MOD;
		ans%=MOD;
		exp/=2ll;
	}

	return ans;

}

ll solve(ll a, ll b){

	ll x1 = fastxp(2,a);
	ll x2 = fastxp(2,b) -1ll;
	if(x2<0)	x2+=MOD;

	return (x1*x2)%MOD;

}

int main(){
    
	fastio;

	int n,q; cin >> n >> q;
	string s; cin >> s;

	frr(i,n)
		v[i]=s[i-1]-'0';

	build(1,1,n);

	fr(i,q){
		int l,r;
		cin >> l >> r;
		pll aux = query(1,1,n,l,r);
		cout << solve(aux.fst,aux.snd) << endl;
	}



}

