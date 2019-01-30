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

bool check;

struct Trie{

	int wrd,cnt;
	map<char,Trie> m;

	Trie(){
		wrd=cnt=0;
		m.clear();
	}

	void add(string& s, int i){

		cnt++;

		if(i==s.size()){
			wrd++;
			if(cnt>1)
				check=false;
			return;
		}

		if(!m.count(s[i]))
			m[s[i]]=Trie();

		if(wrd)
			check=false;
		
		m[s[i]].add(s,i+1);
		

	}

};

void solve(){

	Trie T = Trie();

	check = true;

	int n; cin >> n;

	vector<string> aux;

	fr(i,n){
		string s; cin >> s;
		T.add(s,0);
	}

	if(!check)	puts("NO");
	else		puts("YES");

}

int main(){

	fastio;

	int t; cin >> t;
	while(t--)	solve();

}