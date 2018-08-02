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

int sz[110],id[110];

int find(int p){
	if(id[p]==p)
		return p;
	return id[p]=find(id[p]);
}

void merge(int p, int q){
	p=find(p);q=find(q);
	if(p==q)
		return;
	if(sz[p]>sz[q])
		swap(p,q);
	id[p]=q;
	sz[q]+=sz[p];
}

int main(){

	int n,m,cnt=0;

	while(cin >> n){
		
		
		if(!n)
			break;
		
		cin >> m;
		cnt++;
		
		ms(sz,1);
		frr(i,n)
			id[i]=i;
	
		vector< pair<int,pii> > edges;
		vii ans;
		
		fr(i,m){
			int x,y,z;
			cin >> x >> y >> z;
			edges.pb( { z, {x,y} } );
		}
		
		sort(all(edges));

		for(auto el : edges){
			
			int x = el.snd.fst;
			int y = el.snd.snd;

			if(x>y)
				swap(x,y);
			
			if(find(x)!=find(y)){
				merge(x,y);
				ans.pb({x,y});
			}

		}

		cout << "Teste " << cnt << endl;
		
		fr(i,ans.size())
			cout << ans[i].fst << " " << ans[i].snd << endl;
		gnl;
	}

}