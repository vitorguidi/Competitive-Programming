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
#define pira cout << "pira" << endl

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int cost[200100];
int deg[200200];
vi nodes[200200];
int vis[200200];

int dfs(int v){

	int ans = cost[v];
	vis[v]=1;

	for(auto x : nodes[v]){
	
		if(!vis[x]){
			int aux =dfs(x);
			ans=min(ans,aux);
		}

	}
	
	return ans;

}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    frr(i,n)
    	cin >> cost[i];



    frr(i,n){
    	int x; cin >> x;
    	nodes[i].pb(x);
    	deg[x]++;
   
    }

    set<int> fila;

    frr(i,n){
    	if(!deg[i]){
    		fila.insert(i);
    		vis[i]=1;
    	}
    }
    
    while(!fila.empty()){
    	
    	int v = *fila.begin();
    	fila.erase(fila.begin());
    	
    	for(auto x : nodes[v]){
    		deg[x]--;
    		if(!deg[x]){
    			fila.insert(x);
    			vis[x]=1;
    		}
    	}

    }

  	
    int ans = 0;

   	frr(i,n){
   		if(!vis[i])
   			ans+=dfs(i);
   	}

    cout << ans << endl;

}

