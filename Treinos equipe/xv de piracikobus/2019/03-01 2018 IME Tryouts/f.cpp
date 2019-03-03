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

int id[100100],sz[100100];

int cmp;

int find(int a){
	if(a==id[a]	)	return a;
	return id[a]=find(id[a]);
}

void join(int a, int b){
	a=find(a);b=find(b);
	if(a==b)	return;

	cmp--;

	if(sz[a]<sz[b])	swap(a,b);
	sz[a]+=sz[b];
	id[b]=a;

}

int main(){

	fastio;

	int n,m;
	cin >> n>> m;

	frr(i,n){
		id[i]=i;
		sz[i]=1;
	}

	cmp=n;

	vector<pii> are;

	fr(i,m){
		int x,y;
		cin >> x >> y;
		are.pb({x,y});
	}

	vi perm;

	fr(i,m){
		int x; cin >> x;
		x--;
		perm.pb(x);
	}

	reverse(all(perm));

	vi ans;

	fr(i,m){
		ans.pb(cmp);
		join(are[perm[i]].fst,are[perm[i]].snd);
	}

	reverse(all(ans));

	for(auto x : ans)	cout << x << " ";
		gnl;

}