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

pair<int,pii> edj[1123456]; 
int n,adj[1123][1123],k; 
int id[1123];
int tree[1123];
int vis[1123];

int find(int a){
	if(a==id[a])
		return a; 
	return(id[a]=find(id[a]));
}

void join(int a,int b){
	a=find(a); 
	b=find(b); 
	id[b]=a;	
}

ll kruskal(){
	ll mx=0; 
	for(int i=k-1;i>=0;i--){
		int a,b; 
		a=edj[i].snd.fst;
		b=edj[i].snd.snd;
		if(find(a)!=find(b)){
			join(a,b);
			mx+=edj[i].fst; 
			adj[a][b]=adj[b][a]=1;
		}
	}
	return(mx);
}

void dfs(int v){
	vis[v] = 1;

	frr(i,n){
		if (adj[i][v] == 1 && vis[i]!=1){
			tree[i] = v;
			dfs(i);
		}
	}

}



int main(){

	cin>>n;	
	int i,j,x;
	k=0; 
	for(i=2;i<=n;i++)
		for(j=1;j<i;j++){
			cin>>x;
			edj[k].fst=x;
			edj[k].snd.fst=i;
			edj[k].snd.snd=j; 
			k++;
		}
	sort(edj,edj+k);	
	frr(ii,n)
		id[ii]=ii;
	
	ll sum=kruskal();
	dfs(1);
	cout << sum << endl;
	//frr(i,n){
	//	frr(j,n){
	//		cout << adj[i][j] <<' ';
	//	}
	//	gnl;
	//}
	for(i = 2;i<=n;i++){
		cout << tree[i] << endl;
	}
	
}