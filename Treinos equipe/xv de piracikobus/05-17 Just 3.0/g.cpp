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
#define olar cout << "pira" << endl
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll; 

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

char s[100100];
int ans[100100];
int len;

struct Trie{
	
	int wrd,cnt;
	map<char,Trie> m;

	Trie(){
		wrd=cnt=0;
		m.clear();
	}

	void add(int i){
		cnt++;
		ans[i]=max(ans[i],cnt);
		if(i==len){
			wrd++;
			return;
		}
		if(!m.count(s[i]))
			m[s[i]]=Trie();
		m[s[i]].add(i+1);
	}

	int dfs(int lvl, int now){
		if(now==lvl)	return cnt;
		int amt = cnt;
		for(int i=0;i<26;i++){
			if(!m.count(i+'a'))	continue;
			amt=max(amt,m[i+'a'].dfs(lvl,now+1));
		}
		ans[now]=max(ans[now],amt);
		return ans[now];
	}

};

void solve(){

	Trie T = Trie();

	int n,q;
	scanf("%d %d",&n,&q);
	
	ms(ans,0);

	fr(i,n){
		scanf("%s",s);
		len=strlen(s);
		for(int i=0;i<(len+1)/2;i++)
			swap(s[i],s[len-1-i]);
		T.add(0);
	}


	fr(i,q){
		int l;
		scanf("%d",&l);
		printf("%d\n",ans[l]);
	}

}

int main(){


	int t;
	scanf("%d",&t);
	while(t--)	solve();

}