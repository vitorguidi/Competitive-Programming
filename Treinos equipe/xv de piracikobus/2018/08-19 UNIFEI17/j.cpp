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
#define otp(x) cout << x << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int maxn = 1e7+9;

int v[100200];
vi seg[400800];
double memo[82][82][82][163];

vi merge(vi &a, vi &b){

	vi c;

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
		vi aux;
		aux.pb(v[r]);
		seg[node]=aux;
		return;
	}

	int mid = (l+r)/2;

	build(2*node,l,mid);
	build(2*node+1,mid+1,r);

	seg[node]=merge(seg[2*node],seg[2*node+1]);

}

vi query(int node, int l, int r, int a, int b){

	if(l>r || r<a || l>b){
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

double solve(int b, int r, int z, int check ){

	if(z==0){
		
		if(check>80)
			return 1.0;
		
		return 0.0;
	}

	double &pdm = memo[b][r][z][check];
	
	if(pdm!=-5.0)
		return pdm;

	pdm = 0.0;

	if(b)
		pdm+=solve(b-1,r,z-1,check+1)*( double(b)/double(b+r) );
	if(r)
		pdm+=solve(b,r-1,z-1,check-1)*( double(r)/double(b+r) );

	return pdm;


}

int main(){

	fastio;

	int n,q;
	cin >> n;
	
	frr(i,n)
		cin >> v[i];

	build(1,1,n);

	fr(i,82)
		fr(j,82)
			fr(k,82)
				fr(l,163)
					memo[i][j][k][l]=-5.0;

	cin >> q;

	frr(i,q){

		int y,z,l,r;
		cin >> l >> r >> y >> z;

		vi aux = query(1,1,n,l,r);

		vector<int>::iterator tot = lower_bound(all(aux),y);
		
		int boas = aux.end() - tot; //num de boas
		int ruins = r-l+1 - boas;

		cout << setprecision(6) << fixed;
		cout << solve(boas,ruins,z,80) << endl;	//80 eh offset

	}


}