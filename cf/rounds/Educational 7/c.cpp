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
const ll MOD = 1e9+7;

int bucket_min[600];
int bucket_max[600];
int v[200200];
int sz;

int query(int l, int r, int x){

	int primeiro = l/sz;
	int ultimo = r/sz;

	while(l<=r && l/sz==primeiro){
		if(v[l]!=x)
			return l+1;
		l++;
	}


	while(l<=r && l/sz<ultimo){


		if(bucket_min[l/sz]==bucket_max[l/sz] && bucket_min[l/sz]==x){
			l+=sz;
			continue;
		}

		for(int i=l;i/sz==l/sz;i++){
			if(v[i]!=x)
				return i+1;
		}


	}

	while(l<=r && l/sz==ultimo){
		if(v[l]!=x)
			return l+1;
		l++;
	}

	return -1;

}

int main(){

	int n,m;
	scanf("%d %d",&n,&m);

	sz=(int)floor(sqrt(n));

	ms(bucket_min,INF);
	ms(bucket_max,-INF);

	fr(i,n){
		scanf("%d",&v[i]);
		bucket_min[i/sz]=min(bucket_min[i/sz],v[i]);
		bucket_max[i/sz]=max(bucket_max[i/sz],v[i]);
	}

	fr(i,m){
		int l,r,x;
		scanf("%d %d %d",&l,&r,&x);
		printf("%d\n",query(--l,--r,x));
	}

}
