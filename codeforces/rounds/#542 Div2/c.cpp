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

vii who[55][55];
map<pii,int> sz;
map<pii,pii> id;
map<pii,int> vis;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int grid[55][55];
int n;
int tag[55][55];
int clk=1;

bool valid(pii a){
	return a.fst>=0 && a.fst<n && a.snd>=0 && a.snd<n && grid[a.fst][a.snd]==0;
}

pii find(pii x){
	if(id[x]==x)	return x;
	return id[x]=find(id[x]);
}

void join(pii a, pii b){
	a=find(a);b=find(b);
	if(a==b)	return;
	if(sz[a]<sz[b])	swap(a,b);
	id[b]=id[a];
	sz[a]+=sz[b];
	for(auto x : who[b.fst][b.snd])	who[a.fst][a.snd].pb(x);
}

void dfs(pii v){

	vis[v]=1;
	tag[v.fst][v.snd]=clk;

	fr(i,4){
		int xf = v.fst + dx[i];
		int yf = v.snd + dy[i];
		pii filho = {xf,yf};
		if(!valid(filho))	continue;
		if(vis[filho])	continue;
		join(v,filho);
		dfs(filho);
	}

}

int main(){
    
	fastio;

	cin >> n;

	pii ini;
	cin >> ini.fst >> ini.snd;
	ini.fst--;ini.snd--;
	pii end;
	cin >> end.fst >> end.snd;
	end.fst--;end.snd--;

	fr(i,n){
		fr(j,n){
			pii cara = {i,j};
			who[i][j].pb(cara);
			sz[cara]=1;
			id[cara]=cara;
		}
	}
	string s; getline(cin,s);

	fr(i,n){
		getline(cin,s);
		fr(j,n)	grid[i][j]=s[j]-'0';
	}

	fr(i,n){
		fr(j,n){
			pii v = {i,j};
			if(vis[v])	continue;
			if(grid[i][j]==1)	continue;
			dfs(v);clk++;
		}
	}

	ini=find(ini);
	end=find(end);


	// cout << find(ini).fst << " - " << find(ini).snd << endl;
	// cout << find(end).fst << " - " << find(end).snd << endl;

	if(ini==end){
		cout << 0 << endl;
		return 0;
	}

	ll cost = 1e18;

	for(auto x : who[ini.fst][ini.snd]){
		for(auto y : who[end.fst][end.snd]){

			ll aux = 0;
			aux+=(x.fst-y.fst)*(x.fst-y.fst);
			aux+=(x.snd-y.snd)*(x.snd-y.snd);
			cost=min(cost,aux);

		}
	}

	ini=find(ini);
	end=find(end);

	cout << cost << endl;

}