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

int n,x;
int id[1010];
int sz[1010];

int find(int x){
	if(id[x]==x)	return x;
	return id[x]=find(id[x]);
}

void join (int a, int b){
	a=find(a);b=find(b);
	if(a==b)	return;
	if(sz[a]<sz[b])	swap(a,b);
	id[b]=a;
	sz[a]+=sz[b];
}

int main(){

	fastio;

	cin >> n >> x;
	vi v;
	fr(i,n){
		int k; cin >> k;
		v.pb(k);
	}

	sort(all(v));

	for(int i=0;i<n;i++){
		sz[i]=1;
		id[i]=i;
	}

	for(int i=1;i<n;i++){
		if(v[i]-v[i-1]<=x)
			join(i,i-1);
	}

	int ans = 0;
	for(int i=0;i<n;i++){
		ans=max(ans,sz[find(i)]);
	}

	cout << ans << endl;

}
