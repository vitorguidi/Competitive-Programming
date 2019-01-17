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

string aux;
int amt;

struct Trie{
	
	int cnt,wrd;
	map<char,Trie> m;

	Trie(){
		cnt=wrd=0;
		m.clear();
	}

	void add(string& s, int i){
		cnt++;
		if(i==s.size()){
			wrd++;
			return;
		}
		if(!m.count(s[i]))
			m[s[i]]=Trie();
		m[s[i]].add(s,i+1);
	}

	 void dfs(string& s, int i){
	 	

	 	if(i>s.size() && wrd){
	 		amt++;
	 		cout << aux << endl;
	 	}

	 	for(int j=0;j<26;j++){
	 		if(i<s.size() && s[i]!='a'+j)
	 			continue;
	 		if(!m.count('a'+j))
	 			continue;
	 		aux.pb('a'+j);
	 		m['a'+j].dfs(s,i+1);
	 		aux.pop_back();
	 	}

	 }

};

int main(){

	fastio;

	Trie T = Trie();
	int n; cin >> n;

	fr(i,n){
		string s;
		cin >> s;
		T.add(s,0);
	}

	int k; cin >> k;

	frr(i,k){
		cout << "Case #" << i << ":" << endl;
		string s;
		cin >> s;
		amt=0;
		T.dfs(s,0);
		if(!amt)
			cout << "No match." << endl;
	}



}