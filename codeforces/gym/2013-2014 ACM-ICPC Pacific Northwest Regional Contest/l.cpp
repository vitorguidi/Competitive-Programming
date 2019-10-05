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
 
map<string,string> dict;

vector<string> parse(string s){

	vector<string> ans;

	string buffer;

	int ini=0;

	while(ini<s.size()){
		if(s[ini]==' '){
			ans.pb(buffer);
			buffer.clear();
		}
		else{
			buffer.pb(s[ini]);
		}
		ini++;
	}

	if(!buffer.empty())
		ans.pb(buffer);

	return ans;

}

vector<string> parse2(string s){

	vector<string> ans;

	string buffer;

	set<char> lol;

	
	lol.insert(',');
	lol.insert('.');
	lol.insert('!');
	lol.insert(';');
	lol.insert('?');
	lol.insert('(');
	lol.insert(')');
	lol.insert(' ');


	int ini=0;

	while(ini<s.size()){

		if(lol.find(s[ini])!=lol.end()){
			if(!buffer.empty())
				ans.pb(buffer);
			buffer.clear();
		}
		
		else{
			buffer.pb(s[ini]);
		}
		
		ini++;
	
	}

	if(!buffer.empty())
		ans.pb(buffer);

	return ans;

}

int main(){

	fastio;
 
	int n; cin >> n;

	string s;
	getline(cin,s);

	fr(i,n){

		getline(cin,s);

		// fr(i,s.size())
		// 	s[i]=tolower(s[i]);
		
		vector<string> ans = parse(s);
		string lang = ans[0];
		
		for(int i=1;i<ans.size();i++){
			for(int j=0;j<ans[i].size();j++)
				ans[i][j]=tolower(ans[i][j]);
			dict[ans[i]]=lang;
		}

		// cout << lang << endl;
		// for(int i=1;i<ans.size();i++)
		// 	cout << ans[i] << endl;
		// gnl;
	
	}

	getline(cin,s);

	while(getline(cin,s)){

		fr(i,s.size())
			s[i]=tolower(s[i]);

		vector<string> phrase = parse2(s);

		string lang;

		for(auto x : phrase)
			if(dict.count(x)!=0)
				lang=dict[x];

		cout << lang << endl;

	}
 
}