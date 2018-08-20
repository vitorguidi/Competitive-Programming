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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int v[100100];
vi seg[400400];

vi merge(vi& a, vi& b){

	vi c;

	int inia=0, inib=0;
	int la=a.size(),lb=b.size();

	while(inia<la && inib<lb){
	
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
		vi aux;
		aux.pb(v[r]);
		seg[node]=aux;
		return;
	}

	int mid = (l+r)/2;

	build(2*node,l,mid);
	build(2*node+1,mid+1,r);

	seg[node] = merge( seg[2*node] , seg[2*node+1] );

}

vi query(int node, int l, int r, int a, int b){

	if(r<a || l>b || l>r){
		vi aux;
		return aux;
	}

	if(a<=l && r<=b)
		return seg[node];

	int mid = (l+r)/2;

	vi left = query(2*node,l,mid,a,b);
	vi right = query(2*node+1,mid+1,r,a,b);

	return merge(left,right);

}

ll solve(int len, int k){

}

int main(){

	int n,q;

	cin >> n;

	frr(i,n)
		cin >> v[i];

	build(1,1,n);

	cin >> q;

	frr(i,q){

		int l,r,y,z;
		cin >> l >> r >> y >> z;

		vi aux = query(1,1,n,l,r);

		vector<int>::iterator id = lower_bound(all(aux),y);
		int amt = id - aux.begin();

		//cout << amt << endl;

	}

}