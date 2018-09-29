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
const int mod = 1e9+7;

map<string,int> id;
ll memo[1200000];
int n,m;
vi nodes[20];
int req[20];
int w[20];
int vis[20];
string s;

bool check(int mask, int chave){
	return ((mask^chave)&chave)==0;
}

ll pd(int mask){

	ll &pdm=memo[mask];
	if(pdm!=-1)	return pdm;

	pdm=0;

	fr(i,n){
		if(mask&(1<<i))
			continue;
		if(check(mask,req[i]))
			pdm = max( pdm , (__builtin_popcount(mask) + 1)*w[i] + pd(mask|(1<<i)) );
	}

	return pdm;

}

void dfs(int v){
	vis[v]=1;
	for(auto x : nodes[v]){
		if(vis[x])	continue;
		dfs(x);
	}
}

bool ehletra(char x){
	return (x>='a' && x<='z') || (x>='A' && x<='Z');
}

int tonum(string s){
	int len = s.size()-1;
	int ans = 0;
	int base =1;
	for(int i=len;i>=0;i--){
		ans+=(s[i]-'0')*base;
		base*=10;
	}
	return ans;
}

void solve(){
	
	cin >> n >> m;
	getline(cin,s);

	fr(i,n)
		nodes[i].clear();

	int cnt = 0;

	fr(i,n){

		getline(cin,s);
		string from,num;

		int ini=s.size()-1;
		while(s[ini]!=' '){
			num.pb(s[ini]);
			ini--;
			s.pop_back();
		}
		reverse(all(num));
		
		int amt = tonum(num);
		s.pop_back();
		
		id[s]=cnt;
		w[cnt]=amt;
		cnt++;

	}

	fr(i,m){

		getline(cin,s);
		string from,to;
		int ini = s.size()-1;
		
		while(s[ini]!='>'){
			to.pb(s[ini]);
			ini--;
			s.pop_back();
		}
		to.pop_back();
		reverse(all(to));

		while(!ehletra(s[ini])){
			ini--;
			s.pop_back();
		}
		from=s;
	
		nodes[id[to]].pb(id[from]);

	}

	fr(i,cnt){
		ms(vis,0);
		dfs(i);
		int mask=0;
		fr(j,n){
			if(j==i || !vis[j])	continue;
			mask=mask|(1<<j);
		}
		req[i]=mask;
	}

	ms(memo,-1);
	cout << pd(0) << endl;

}

int main(){

	fastio;
	int t; cin >> t;
	getline(cin,s);
	while(t--)	solve();

}