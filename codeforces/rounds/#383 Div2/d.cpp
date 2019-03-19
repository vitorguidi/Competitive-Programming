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


int id[1010],sz[1010];
int cost[1010],value[1010],oldvalue[1010],oldcost[1010];
int vis[1010];
vi who[1010];
ll n,m,w;

int amt;
int memo[1010][1010];
vi caras;

int find(int a){
	if(id[a]==a)	return a;
	return id[a]=find(id[a]);
}

void join(int a, int b){
	a=find(a);b=find(b);
	if(a==b)	return;
	if(sz[a]<sz[b])	swap(a,b);
	id[b]=a;
	sz[a]+=sz[b];
	cost[a]+=cost[b];
	value[a]+=value[b];
	for(auto x : who[b])	who[a].pb(x);
}

int pd(int ind, int wgt){
	if(wgt<0)		return -INF;
	if(ind==amt)	return 0;
	int &pdm=memo[ind][wgt];
	if(pdm!=-1)	return pdm;

	pdm=-INF;

	int pega = value[caras[ind]] + pd(ind+1,wgt-cost[caras[ind]]);
	int passa = pd(ind+1,wgt);
	int seletivo = -INF;

	for(auto x : who[caras[ind]]){
		seletivo = max(seletivo, oldvalue[x] + pd(ind+1,wgt-oldcost[x]) );
	}

	return pdm = max({pdm,pega,passa,seletivo});

}

int main(){
      
	fastio;

	cin >> n >> m >> w;

	frr(i,n){
		id[i]=i;
		sz[i]=1;
		who[i].pb(i);
	}

	frr(i,n)	cin >> cost[i];
	frr(i,n)	cin >> value[i];
	frr(i,n)	oldvalue[i]=value[i];
	frr(i,n)	oldcost[i]=cost[i];

	fr(i,m){
		int x,y;
		cin >> x >> y;
		join(x,y);
	}


	set<int> comps;
	frr(i,n)	comps.insert(find(i));

	ms(memo,-1);
	amt = comps.size();

	
	for(auto x : comps)	caras.pb(x);

	cout << pd(0,w) << endl;



}