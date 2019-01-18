#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;
const ll mod=1e9+7;

vi nodes[50500];
int vis[50500];
string s;

bool check(char x){
	return x!='?' && x!='#';
}

char dfs(int v){

	vis[v]=1;
	int ans=1;

	char bizu = s[v];

	for(auto x : nodes[v]){
		
		if(vis[x])	continue;

		char aux = dfs(x);

		if(bizu=='?' && check(aux))
			bizu=aux;
		if(check(bizu) && check(aux) && bizu!=aux)
			bizu='#';
		if(aux=='#')
			bizu=aux;

	}

	return bizu;

}

int main(){
	fastio; 
	int T;
	cin >> T;

	while(T--){

		ms(vis,0);

		fr(i,50500)
			nodes[i].clear();
	
		int n,q,a,b,flag = 1;

		cin >> n;
		cin >> q;
		
		getline(cin,s);
		getline(cin,s);

		fr(i,n)
			nodes[i].pb(n-1-i);
		
		fr(i,q){
			int a,b;
			cin >> a >> b;
			a--;b--;
			nodes[a].pb(b);
			nodes[b].pb(a);
		}

		ll ans = 1ll;

		fr(i,n){
			if(!vis[i]){

				char aux = dfs(i);
				if(aux=='?')
					ans*=26;
				if(aux=='#')
					ans=0;
				ans%=mod;
			}
		}

		cout << ans << endl;

	}
	
}