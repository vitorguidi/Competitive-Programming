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

int sz[210],id[210],check[210],cnt;

int find(int p){
	if(id[p]==p)
		return p;
	return id[p]=find(id[p]);
}

void join(int p, int q){

	p==find(p);q=find(q);
	if(p==q)
		return;

	if(check[p] && !check[q])
		swap(p,q);
	

	if(check[q] && !check[p]){
		id[p]=q;sz[q]+=sz[p];
		return;
	}

	if(sz[p]>sz[q])
		swap(p,q);
	id[p]=q;sz[q]+=sz[p];

}

int main(){

	int t;
	cin >> t;
	while(t--){

		int n,m,k;	
		cin >> n >> m >> k;

		cnt++;

		ms(check,0);ms(sz,1);
		frr(i,n)
			id[i]=i;

		fr(i,k){
			int x;
			cin >> x;
			check[x]=1;
		}



		vector< pair<int,pii> > edges;

		fr(i,m){
			int x,y,z;
			cin >> x >> y >> z;
			edges.pb( mp(z , mp(x,y) ) );
		}

		sort(all(edges));

		int sum=0;


		for(auto are : edges){

			pii coord = are.snd;
			int cost = are.fst;

			int x = find(coord.fst);
			int y = find(coord.snd);

			if(x==y)
				continue;

			if(check[x] && check[y])
				continue;

			join(x,y);
			sum+=cost;

		}

		cout << "Case #" << cnt << ": " << sum << endl;
		
	}

}