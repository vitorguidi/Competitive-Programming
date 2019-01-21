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
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

int check[100100];
vi seg[400400];

vi merge(vi& a, vi& b){
	vi ans;
	int inia=0;
	int inib=0;
	int lena=a.size();
	int lenb=b.size();
	while(inia<lena && inib<lenb){
		if(a[inia]<=b[inib])
			ans.pb(a[inia++]);
		else
			ans.pb(b[inib++]);
	}
	while(inia<lena)
		ans.pb(a[inia++]);
	while(inib<lenb)
		ans.pb(b[inib++]);
	return ans;
}

void build(int node, int l, int r){
	if(l==r){
		seg[node]={check[l]};
		return;
	}
	int mid = (l+r)/2;
	build(2*node,l,mid);
	build(2*node+1,mid+1,r);
	seg[node]=merge(seg[2*node],seg[2*node+1]);
}

int query(int node, int l, int r, int a, int b, int val){

	if(r<a || l>b)	return 0;


	if(a<=l && r<=b){
		int amt = upper_bound(all(seg[node]),val)-seg[node].begin();
		return amt;
	}

	int mid = (l+r)/2;

	return query(2*node,l,mid,a,b,val) + query(2*node+1,mid+1,r,a,b,val);


}

int main(){

	for(ll i=2;i<=100000;i++){
		if(!check[i]){
			check[i]=i;
			for(ll j=i;j<=100000;j+=i)
				check[j]=max<ll>(check[j],i);
		}
	}

	check[1]=INF;

	build(1,1,100000);

	int q;
	scanf("%d",&q);

	while(q--){
		
		ll n,k;
		scanf("%lld %lld",&n,&k);
		
		ll ans = query(1,1,100000,1,n,k);

		printf("%lld\n",ans);

	}



}
