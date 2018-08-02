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
 
int sz[100100],id[100100];
map<int,int> check;
 
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
 
	int n,m;
 
	cin >> n >> m;
	
	frr(i,n){
		sz[i]=1;
		id[i]=i;
	}
 
	fr(i,m){
		int x,y;
		cin >> x >> y;
		merge(x,y);	
	}
 
 
	int cnt=0;
 
	frr(i,n){
		if(!check[id[find(i)]]){
			cnt++;
			check[find(i)]=1;
		}
	}
	cout << cnt << endl;
 
} 