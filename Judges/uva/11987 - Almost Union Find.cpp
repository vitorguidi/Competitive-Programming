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

int id[200200],sz[200200],sum[200200];
int n,m;

int find(int p){
	
	if(id[p]==p)
		return p;

	return id[p]=find(id[p]);

}

void join(int p, int q){

	int sp=find(p),sq=find(q);

	if(sp==sq)
		return;
	
	id[sp]=sq;

	sz[sq]+=sz[sp];
	sum[sq]+=sum[sp];

	sz[sp]=0;sum[sp]=0;

}

void move(int p, int q){

	int sp=find(p),sq=find(q);
	
	sz[sq]++;
	sum[sq]+=p;
	
	sum[sp]-=p;
	sz[sp]--;
	
	id[p]=sq;

}

int main(){

	while(cin >> n && cin >> m){

		ms(sz,1);

		frr(i,n){
			id[i]=n+i;
			id[n+i]=n+i;
			sum[n+i]=i;
			sz[n+i]=1;
		}

		fr(i,m){
			int x,y,z;
			cin >> x >> y;
			if(x!=3)
				cin >> z;

			if(x==1)
				join(y,z);
			else if(x==2)
				move(y,z);
			else
				cout << sz[find(y)] << " " << sum[find(y)] << endl;

		}

	}

}