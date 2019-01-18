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

int tonum(string a){

	int ini=0;
	int ans=0;

	int base = 1;

	if(a[ini]=='-'){
		ini++;
		base=-1;
	}
	
	for(int i=a.size()-1;i>=ini;i--){
		ans+=base*(a[i]-'0');
		base*=10;
	}

	return ans;

}

bool calc(int a, int b, string op){
	if(op=="==")		return a==b;
	if(op=="<")	return a<b;
	if(op==">")	return a>b;
	if(op=="<=")	return a<=b;
	if(op==">=")	return a>=b;
	if(op=="!=")	return a!=b;
}

int main(){

	int t; cin >> t;
	string s;getline(cin,s);

	while(t--){
		
		getline(cin,s);
		string a;
		int ini=0;

		while(s[ini]!=' '){
			a.pb(s[ini]);
			ini++;
		}

		while(s[ini]==' ')
			ini++;
		
		string op;
		while(s[ini]!=' '){
			op.pb(s[ini]);
			ini++;
		}

		while(s[ini]==' ')
			ini++;
		
		string b;
		while(ini<s.size()){
			b.pb(s[ini]);
			ini++;
		}
		
		int x = tonum(a);
		int y = tonum(b);

		int flag = calc(x,y,op);

		cout << (flag == true ? "true" : "false") << endl; 

	}

}