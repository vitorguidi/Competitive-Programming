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
 
ll style1[10100],style2[10100];

vi adj1[10100], adj2[10100];

ll pre1[10100],pos1[10100];
ll pre2[10100],pos2[10100];

ll stamp1[20100],stamp2[20100];
ll sz1[20100],sz2[20100];
ll hash1[20100],hash2[20100],hash3[20100],hash4[20100];

int clk=1;

const ll MOD1 = 1e9+7;
const ll MOD2 = 1e9+9;

ll fastxp(ll base,ll exp,ll MOD){
	ll ans = 1;
	while(exp){
		if(exp%2)
			ans*=base;
		base*=base;
		base%=MOD;
		ans%=MOD;
		exp/=2;
	}
	return ans;
}

ll invmod(ll base, ll MOD){
	return fastxp(base,MOD-2,MOD);
}


void dfs(int u){

	pre1[u]=clk++;
	for(auto x : adj1[u]){
		if(pre1[x])	continue;
		dfs(x);
	}
	pos1[u]=clk++;

}

void dfs2(int u){

	pre2[u]=clk++;
	for(auto x : adj2[u]){
		if(pre2[x])	continue;
		dfs2(x);
	}
	pos2[u]=clk++;

}

void go(){

	int m,n;
	cin >> m >> n;

	fr(i,10100){
		adj1[i].clear();
		adj2[i].clear();
	}

	int root1=-1;

	fr(i,m){
		char st;
		int dad;
		cin >> st >> dad;
		style1[i]=st-'A'+1;
		if(dad==-1)
			root1=i;
		else{
			adj1[dad].pb(i);
		}
	}
	
	ms(pre1,0);
	ms(pos1,0);
	clk=1;
	dfs(root1);
	int root2=-1;

	fr(i,n){
		char st;
		int dad;
		cin >> st >> dad;
		style2[i]=st-'A'+1;
		if(dad==-1)
			root2=i;
		else{
			adj2[dad].pb(i);
		}
	}

	ms(pre2,0);
	ms(pos2,0);
	clk=1;
	dfs2(root2);

	fr(i,m){
		sz1[pos1[i]]=sz1[pre1[i]]=pos1[i]-pre1[i]+1;
	}
	fr(i,n)
		sz2[pos2[i]]=sz2[pre2[i]]=pos2[i]-pre2[i]+1;
	//double hashing begins

	fr(i,m)
		stamp1[pre1[i]]=stamp1[pos1[i]]=style1[i];
	fr(i,n)
		stamp2[pre2[i]]=stamp2[pos2[i]]=style2[i];

	ll base1 = 1;
	ll base2 = 1;
	frr(i,2*m){

		hash1[i]=(hash1[i-1]+stamp1[i]*base1)%MOD1;
		hash2[i]=(hash2[i-1]+sz1[i]*base2)%MOD2;
		
		base1=(base1*31ll)%MOD1;
		base2=(base2*31ll)%MOD2;
	
	}

	base1 = 1;
	base2 = 1;
	
	frr(i,2*n){
	
		hash3[i]=(hash3[i-1]+stamp2[i]*base1)%MOD1;
		hash4[i]=(hash4[i-1]+sz2[i]*base2)%MOD2;
	
		base1=(base1*31ll)%MOD1;
		base2=(base2*31ll)%MOD2;
	
	}

	set<tuple<ll,ll,ll>> repo;

	fr(i,m){

		ll h1 = ( hash1[pos1[i]] - hash1[pre1[i]-1] + MOD1) % MOD1;
		h1*=invmod(fastxp(31,pre1[i]-1,MOD1),MOD1);
		h1%=MOD1;
		
		ll h2 = ( hash2[pos1[i]] - hash2[pre1[i]-1] + MOD2) % MOD2;
		h2*= invmod( fastxp( 31, pre1[i]-1, MOD2), MOD2);
		h2%=MOD2;
		
		// dbg(h1);
		// dbg(h2);

		repo.insert(make_tuple(pos1[i]-pre1[i]+1,h1,h2));
	}

	ll ans=0;

	fr(i,n){

		ll h1 = ( hash3[pos2[i]] - hash3[pre2[i]-1] + MOD1) % MOD1;
		h1*= invmod( fastxp( 31, pre2[i]-1, MOD1), MOD1);
		h1%= MOD1;
		
		ll h2 = (hash4[pos2[i]] - hash4[pre2[i]-1] + MOD2) % MOD2;
		h2*=invmod( fastxp( 31, pre2[i]-1, MOD2), MOD2);
		h2%=MOD2;

		// dbg(h1);
		// dbg(h2);
		// gnl;

		if(repo.find(make_tuple(pos2[i]-pre2[i]+1,h1,h2))!=repo.end())
			ans=max<ll>(ans,pos2[i]-pre2[i]+1);
	
	}

	cout << ans/2 << endl;

}

int main(){

	fastio;
 
	int t; cin >> t;
	while(t--)	go();
 
}