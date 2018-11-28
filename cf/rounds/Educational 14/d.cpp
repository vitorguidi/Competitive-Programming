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

int id[1100100],sz[1100100];
int v[1100100];
int ans[1100100];
int cnt[1100100];

vi comp[1100100];

int find(int a){
	if(id[a]==a)	return a;
	return id[a]=find(id[a]);
}


void join(int a, int b){
	a=find(a);
	b=find(b);
	if(a==b)	return;
	if(sz[a]<sz[b])	swap(a,b);
	id[b]=a;
	sz[a]+=sz[b];
}


int main(){
    
	fastio;

	int n,m; cin >> n >> m;


	frr(i,n)	cin >> v[i];

	frr(i,n)	id[i]=i;
	frr(i,n)	sz[i]=1;


	fr(i,m){
		int a,b; cin >> a >> b;
		join(a,b);
	}

	frr(i,n)	comp[ find(i) ].pb(v[i]);

	frr(i,n)	sort( all(comp[i]) );

	frr(i,n){
		int cara = find(i);
		ans[i]=comp[cara][sz[cara]-1];
		sz[cara]--;
		comp[cara].pop_back();
	}

	frr(i,n)	cout << ans[i] << " ";
	gnl;


}

