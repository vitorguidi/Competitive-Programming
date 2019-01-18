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

int n,m,q,age[550];
vi adj[555];
int indice[550];
int backind[550];
bool vis[550];

int dfs(int a){
	vis[a]=1;
	int ans=INF;
	int aux;
	//dbg(a);
	for(auto x:adj[a]){
		if(vis[x])
			continue;
		ans=min(ans,age[backind[x]]);
		aux=dfs(x);

		ans=min(ans,aux);
	}

	return ans;
}

int main(){
	
	scanf("%d %d %d",&n,&m,&q);

	frr(i,n){
		scanf("%d",&age[i]);
		indice[i]=i;
		backind[i]=i;
	}

	int a,b;
	fr(i,m){
		scanf("%d %d",&a,&b);
		adj[b].pb(a);
	}

	char s[60],cf;
	fr(i,q){
		scanf("%c",&cf);
		scanf("%s ",s);
		if(s[0]=='T'){
			scanf("%d %d",&a,&b);
			swap(indice[a],indice[b]);
			backind[indice[a]]=a;
			backind[indice[b]]=b;
		}
		else{
			scanf("%d",&a);
			ms(vis,0);
			int aux=dfs(indice[a]);
			if(aux==INF)
				printf("*\n");
			else
				printf("%d\n",aux);
		}

	}

}
