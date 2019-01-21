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

int val;
int t;
map<ll,ll> id;

struct Trie{

	int wrd,cnt;
	map<char,Trie> m;

	Trie(){
		wrd=cnt=0;
		m.clear();
	}

	void add(ll i, ll x){
		
		cnt++;
		
		if(i==-1){
			wrd++;
			return;
		}
		
		ll bit = (1ll<<i)&x;
		if(bit)	bit=1;

		if(!m.count(bit))
			m[bit]=Trie();
		
		m[bit].add(i-1,x);

	}

	void dfs(ll i, ll resp,ll x){
		
		if(i==-1){
			val=resp;
			return;
		}
			
		ll bit = (1ll<<i)&x;
		if(bit)	bit=1;

		if(bit==0){

			if(m.count(1))
				m[1].dfs(i-1,resp|(1ll<<i),x);
			else
				m[0].dfs(i-1,resp,x);

		}

		else{

			if(m.count(0))
				m[0].dfs(i-1,resp,x);
			else
				m[1].dfs(i-1,resp|(1ll<<i),x);

		}

	}

};


void solve(){

	int n,q;
	scanf("%d %d",&n,&q);

	id.clear();

	Trie T = Trie();

	frr(i,n){
		int x;
		scanf("%d",&x);
		T.add(33,x);
		if(!id[x])
			id[x]=i;
	}

	fr(i,q){
		int x;
		scanf("%d",&x);
		T.dfs(33,0,x);
		val=id[val];
		printf("%d\n",val);
	}

	if(t)	printf("\n");

}

int main(){

	scanf("%d",&t);
	while(t--)
		solve();

}