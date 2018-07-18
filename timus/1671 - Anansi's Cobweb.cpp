#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

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
const int MAXN = 100100;

pii edges[100100];
int fodida[100100];
int sz[100100],id[100100];

int find(int p){
	if(id[p]==p)
		return p;
	return id[p]=find(id[p]);
}

void join(int p, int q){
	p=find(p);q=find(q);
	if(p==q)
		return;
	if(sz[p]>sz[q])
		swap(p,q);
	id[p]=q;
	sz[q]+=sz[p];
}

int main(){

	int n,m;
	cin >> n >> m;

	ms(sz,0);
	frr(i,n)
		id[i]=i;

	frr(i,m){
		int x,y;
		cin >> x >> y;
		edges[i]=mp(x,y);
	}
	int q;
	cin >> q;

	vii add;
	fr(i,q){
		int x;
		cin >> x;
		fodida[x]=1;
		add.pb(edges[x]);
	}
	
	reverse(all(add));

	int comp=n;

	frr(i,m){
		
		if(fodida[i])
			continue;

		int x,y;
		x=edges[i].fst;y=edges[i].snd;

		if(find(x)!=find(y)){
			join(x,y);
			comp--;
		}
	}


	vi ans;
	ans.pb(comp);

	fr(i,add.size()){

		int x,y;
		x=add[i].fst;y=add[i].snd;

		if(find(x)!=find(y)){
			comp--;
			join(x,y);
		}

		ans.pb(comp);

	}

	reverse(all(ans));

	for(int i=1;i<ans.size();i++)
		cout << ans[i] << ' ';
	gnl;

}