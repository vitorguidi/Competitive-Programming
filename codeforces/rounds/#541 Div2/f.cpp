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

int id[200200];
int sz[200200];
vi ans[200200];

int find(int a){
	if(id[a]==a)	return a;
	return id[a]=find(id[a]);
}

void join(int a, int b){
	a=find(a);b=find(b);
	if(a==b)	return;
	if(sz[a]<sz[b])	swap(a,b);
	id[b]=id[a];
	sz[a]+=sz[b];
	for(auto x : ans[b])	ans[a].pb(x);
}

int main(){
    
	fastio;

	
	int n; cin >> n;

	frr(i,n){
		id[i]=i;
		ans[i].pb(i);
		sz[i]=1;
	}

	fr(i,n-1){
		int x,y;
		cin >> x >> y;
		join(x,y);
	}

	for(auto x : ans[find(1)])	cout << x << " ";
	gnl;


}