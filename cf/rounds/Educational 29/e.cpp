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

ll seg[4*800600];
ll bit[800800];
ll v[800600];

ll query_bit(int ind){
	ll ans = 0;
	for(int i=ind;i>0;i-=i&-i)
		ans+=bit[i];
	return ans;
}

void update(int ind, ll val){
	for(int i=ind;i<800800;i+=i&-i)
		bit[i]+=val;	
}

void build(int node, int l, int r){
	
	if(l==r){
		seg[node]=v[l];
		return;
	}
	
	int mid	= (l+r)/2;
	
	build(2*node,l,mid);		
	build(2*node+1,mid+1,r);

	seg[node] = min<ll>(seg[2*node] , seg[2*node+1]);	

}

int query_seg(int node, int l, int r, int a, int b){	

	if (a>r || b<l)		return INF;		

	if(a<=l && r<=b)	return seg[node];	

	int mid=(l+r)/2;
	
	return min<ll>(query_seg(2*node,l,mid,a,b) , query_seg(2*node+1,mid+1,r,a,b) );

}


int main(){
    
	fastio;

	int n; cin >> n;

	vii coisos;
	vi coord;

	map<int,int> id;

	fr(i,n){
		int x,y; cin >> x >> y;
		coisos.pb({x,y});
		coord.pb(x);
		coord.pb(y);
		coord.pb(x+1);
		coord.pb(y+1);
	}

	sort(all(coord));

	int cnt = 1;

	for(auto x : coord)
		if(!id[x])
			id[x]=cnt++;
	
	cnt--;

	fr(i,n){
		coisos[i].fst=id[coisos[i].fst];
		coisos[i].snd=id[coisos[i].snd];
	}

	for(auto x : coisos){
		update(x.fst,1ll);
		update(x.snd+1,-1);
	}

	frr(i,cnt){
		v[i]=query_bit(i);
		if(!v[i])	v[i]=INF;
	}

	build(1,1,cnt);

	fr(i,n){

		pii x = coisos[i];
		ll val = query_seg(1,1,cnt,x.fst,x.snd);

		if(val>1){
			cout << i+1 << endl;
			return 0;
		}
	}

	cout << -1 << endl;

	

}

