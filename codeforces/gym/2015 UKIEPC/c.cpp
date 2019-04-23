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

map<string,int> freq;
map<string,int> used;
map<string,int> seen;
map<int,set<string>> tem;

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

int main(){

	fastio;
	
	int n; cin >> n;
	
	string s;
	getline(cin,s);
	
	int id = 1;
	
	fr(i,n){
	
		getline(cin,s);
		vector<string> aux = prec(s);
		
		int len = aux.size();
		
		for(int i=1;i<len;i++)
			freq[aux[i]]++;
		
		if(!seen[aux[0]])
			seen[aux[0]]=id++;
			
		int cara = seen[aux[0]];
		
		for(int i=1;i<len;i++)
			tem[cara].insert(aux[i]);
		
			
	}
	
	id--;
	
	for(int i=1;i<=id;i++){
		//dbg(i);
		for(auto x : tem[i]){
			used[x]++;
			//dbg(x);
		}
	}
	
	set< pair<int,string> >ans;
	
	for(auto x : freq){
		string cara = x.fst;
		if(used[cara]==id)
			ans.insert(mp(-x.snd,x.fst));
	}
	
	if(ans.empty())
		cout << "ALL CLEAR" << endl;
	else{
		for(auto x : ans)
			cout << x.snd << endl;
	}
	
	
}