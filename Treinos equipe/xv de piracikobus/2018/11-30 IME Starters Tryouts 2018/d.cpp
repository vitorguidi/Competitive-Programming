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

double bit[100200];

void update(int ind, double val){
	for(int i=ind;i<100200;i+=i&-i)
		bit[i]+=val;

}

double query(int ind){

	double ans = 0.0;
	for(int i=ind;i>0;i-=i&-i)
		ans+=bit[i];
	return ans;

}

int main(){


	int n;
	scanf("%d",&n);

	frr(i,n){
		double x;
		scanf("%lf",&x);
		update(i,x);
	}

	int q;
	scanf("%d",&q);

	fr(i,q){

		int op;
		scanf("%d",&op);

		if(op==1){
			int ind;
			double val;
			scanf("%d %lf",&ind,&val);
			double old_val = query(ind)-query(ind-1);
			update(ind,-old_val);
			update(ind,val);	
		}
		else{
			int l,r;
			scanf("%d %d",&l,&r);
			double ans = query(r)-query(l-1);	
			ans/=(double)(r-l+1);
			printf("%lf\n",ans);
		}

	}

}