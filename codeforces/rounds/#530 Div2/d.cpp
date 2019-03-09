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

ll sum[100100];
vi nodes[100100];
int pai[100100];
int hgt[100100];
int vis[100100];
int nf[100100];
int v[100100];

void dfs(int v){

	vis[v]=1;

	for(auto x : nodes[v]){
		
		if(vis[x])	continue;

		hgt[x]=1+hgt[v];
		pai[x]=v;
		dfs(x);
		nf[v]+=1+nf[x];
	}

}

bool comp(int a, int b){
	return hgt[a]<hgt[b];
}

int main(){
    
	fastio;

	int n; cin >> n;

	for(int i=2;i<=n;i++){
		int x; cin >> x;
		nodes[x].pb(i);
		nodes[i].pb(x);
	}

	frr(i,n)	cin >> sum[i];

	pai[1]=1;
	hgt[1]=1;
	v[1]=sum[1];

	dfs(1);

	vi ordem;

	frr(i,n){
		if(hgt[i]%2==0)	continue;
		if(i==1)	continue;
		ordem.pb(i);
	}

	sort(all(ordem),comp);

	for(auto x : ordem){

		int dad = pai[x];
		int avo = pai[dad];

		if(sum[x]<sum[avo]){
			cout << -1 << endl;
			return 0;
		}

	}

	for(auto x : ordem){

		int dad = pai[x];
		int avo = pai[dad];

		if(sum[dad]==-1){

			int menor = INF;

			for(auto f : nodes[dad]){
				if(f==pai[dad])	continue;
				menor=min<ll>(menor,sum[f]);
			}

			sum[dad]=menor;
			v[x]=sum[x]-sum[dad];
			v[dad]=sum[dad]-sum[avo];

		}

		else
			v[x]=sum[x]-sum[dad];

	}

	ll tot = 0;

	frr(i,n)	tot+=v[i];

	cout << tot << endl;

}