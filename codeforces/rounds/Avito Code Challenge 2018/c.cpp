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

int deg[100100];
vi nodes[100100];
int nf[100100];
int n;

void dfs(int v,int p){

	for(auto x : nodes[v]){
		if(x==p)	continue;
		nf[v]++;
		dfs(x,v);
		nf[v]+=nf[x];
	}

}


int main(){
    
	fastio;

	cin >> n;

	fr(i,n-1){
		int u,v;
		cin >> u >> v;
		deg[u]++;
		deg[v]++;
		nodes[u].pb(v);
		nodes[v].pb(u);
	}

	int cnt=0;
	int cara;
	frr(i,n){
		if(deg[i]>2){
			cara=i;
			cnt++;
		}
	}	

	if(cnt>1){
		cout << "No" << endl;
		return 0;
	}

	if(cnt==0){
		frr(i,n){
			if(deg[i]==1){
				cara=i;
				break;
			}
		}
	}

	dfs(cara,-1);

	vi folhas;

	frr(i,n)
		if(!nf[i])	folhas.pb(i);

	cout << "Yes" << endl;
	cout << folhas.size() << endl;
	for(auto x : folhas)	cout << cara << " " << x << endl;

}