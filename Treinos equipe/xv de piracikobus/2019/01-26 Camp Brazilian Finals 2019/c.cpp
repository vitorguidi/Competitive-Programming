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

int id[100100],sz[100100];
int n,m;

vector<tuple<char,int,int,int>> qry;
vii nodes[100100];

ll flag[100100];
ll vis[100100];
ll hgt[100100];
ll wgt[100100];
int memo[100100][23];

int find(int a){
	if(id[a]==a)	return a;
	return id[a]=find(id[a]);
}

void join(int a, int b){
	a=find(a);
	b=find(b);
	if(a==b)	return;

	if(a==0){
		id[b]=a;
		sz[a]+=sz[b];
		return;
	}
	if(b==0){
		id[a]=b;
		sz[b]+=sz[b];
		return;
	}

	if(sz[a]<sz[b])	swap(a,b);
	id[b]=a;
	sz[a]+=sz[b];
}

void dfs(int x){
	
	vis[x]=1;
	
	for(auto filho : nodes[x]){
	
		if(vis[filho.snd])	continue;
	
		memo[filho.snd][0]=x;
	
		for(int i=1;i<=20;i++)
			memo[filho.snd][i]=memo[memo[filho.snd][i-1]][i-1];
	
		hgt[filho.snd]=1+hgt[x];
		wgt[filho.snd]=wgt[x]+filho.fst;
	
		dfs(filho.snd);
	
	}
}

int lca(int a, int b){

	if(hgt[a]<hgt[b])	swap(a,b);

	for(int i=20;i>=0;i--){
		if(hgt[memo[a][i]]>=hgt[b])
			a=memo[a][i];
	}

	if(a==b)	return a;

	for(int i=20;i>=0;i--){
		if(memo[a][i]!=memo[b][i]){
			a=memo[a][i];
			b=memo[b][i];
		}
	}

	return memo[a][0];

}

void reset(){
	fr(i,n+1){
		id[i]=i;
		sz[i]=1;
	}

	fr(i,n+1)	nodes[i].clear();
	ms(flag,0);qry.clear();
	ms(vis,0);ms(memo,0);
	ms(hgt,0);ms(wgt,0);
}

void solve(){

	reset();
	
	fr(i,m){
	
		char op; cin >> op;
	
		if(op=='?'){
			int a,b; cin >> a >> b;
			if(find(a)!=find(b))
				flag[i]=0;
			else
				flag[i]=1;
			qry.pb(make_tuple('?',a,b,flag[i]));
		}
	
		else{
			int a,b,w;
			cin >> a >> b >> w;
			if(find(a)==find(b))	continue;
			nodes[a].pb({w,b});
			nodes[b].pb({-1*w,a});
			join(a,b);
		}
	
	}

	for(int i=0;i<=20;i++)
		memo[0][i]=0;

	frr(i,n){
		if(vis[find(i)])	continue;
		memo[i][0]=0;
		dfs(find(i));
	}

	for(auto x : qry){

		if(get<0>(x)=='!')	continue;
		
		if(get<3>(x)==0)
			cout << "UNKNOWN" << endl;
		
		else{
			int a = get<1>(x);
			int b = get<2>(x);
			int aux = lca(a,b);
			ll ans = wgt[b]-wgt[a];
			cout << ans << endl;
		}

	}

}

int main(){
	fastio;
	n=1;
	while(n){
		cin >> n >> m;
		if(!n)	break;
		solve();
	}
}
