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
typedef pair<double,double> point;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;

const double pi = acos(-1);

string hard = "bcdgknpt";
set<int> hardc;
string nearest;
string gritinho[26];

vector<string> prec(string s){

	int n = s.size();
	
	vector<string> ans;
	
	int ini=0;
	while(ini<n){
	
		string aux;
	
		while(ini<n && s[ini]!=' ')
			aux.pb(s[ini++]);
		
		ini++;
		
		ans.pb(aux);
	
	}
	
	return ans;

}

bool tem(char x){

	return hardc.find(x)!=hardc.end();

}

void solve(string& s){

	bool up = false;
	
	if(s[0]>='A' && s[0]<='Z')	up=true;

	// regra 1
	s[0]=tolower(s[0]);
	s[0]=nearest[s[0]-'a'];
	
	//regra2
	
	int ini=0;
	int len = s.size();
	bool flag = false;
	
	while(ini<len){
	
		if(s[ini]=='-'){
			flag=true;
		}
		else if(flag){
			if(tem(s[ini]))
				s[ini]=s[0];
		}
		ini++;
	}
	
	//regra 3
	if(tem(s[s.size()-1]))
		s+=gritinho[s[s.size()-1]-'a'];
		
	if(up)	s[0]=toupper(s[0]);
	
}

int main(){

	fastio;
	
	string s;
	getline(cin,s);
	
	for(auto x : hard)	hardc.insert(x);
	
	fr(i,26)	nearest.pb('a'+i);
	
	fr(i,26){
	
		char cara = nearest[i];
		
		int dist = INF;
		char ans = 'a';
		
		for(auto x : hard){
			
			if(abs(int(x-cara)<dist)){
				dist=x-cara;
				dist=abs(dist);
				ans=x;
			}
			else if(abs(int(x-cara)==dist)){
				ans=min(ans,x);
			}
		
		}
		
		nearest[i]=ans;
	
	}
	
	for(auto x : hardc){
	
		string c1 = "a";
		string c2 = "o";
		string c3 = "u";
		
		string coiso;
		
		int ans = INF;
		
		if(abs(c1[0]-x)<ans){
			coiso =c1[0];
			ans=abs(c1[0]-x);
		}
		if(abs(c2[0]-x)<ans){
			coiso =c2[0];
			ans=abs(c2[0]-x);
		}
		if(abs(c3[0]-x)<ans){
			coiso =c3[0];
			ans=abs(c3[0]-x);
		}
		
		gritinho[x-'a']=coiso+'h';
	
	}
	
	vector<string> v = prec(s);
	
	fr(i,v.size())	solve(v[i]);
	
	string printada;
	
	for(auto x : v){
		for(auto y : x){
			if(y!='-')
				printada.pb(y);
		}
		printada.pb(' ');
	}
	printada.pop_back();
	cout << printada << endl;

}