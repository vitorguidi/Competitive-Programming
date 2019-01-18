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

ll to_int(string x, ll k){

	int len = x.size();
	len--;

	ll ans = 0;
	ll base=1;

	if(x[0]=='-'){
		reverse(all(x));
		x.pop_back();
		reverse(all(x));
		base=-1;
		len--;
	}

	fr(i,x.size())
		if(x[i]=='?')
			x[i]='0'+k;

	for(int i=len;i>=0;i--){
		ll dig = x[i]-'0';
		ans+=base*dig;
		base*=10ll;
	}

	return ans;

}

ll calc(ll a, ll b, char x){

	if(x=='+')
		return a+b;
	if(x=='-')
		return a-b;
	if(x=='*')
		return a*b;

}

bool op(char x){
	return (x=='-' ||x=='+' || x=='*');
}

void solve(){

	string s; getline(cin,s);

	int cnt[12];
	ms(cnt,0);

	for(auto x : s){
		if(x=='?' || x=='-' || x=='+' || x=='*' || x=='=')
			continue;
		cnt[x-'0']++;
	}

	string primo;
	int ini=0;

	if(s[ini]=='-')
		primo.pb(s[ini++]);		//trata do caso negativo

	while(!op(s[ini]))
		primo.pb(s[ini++]);		//pega os digitos do primeiro operando


	char opera;
	opera = s[ini++];			//pega operacao

	string segundo;

	while(s[ini]!='=')			//pega digitos do segundo operando		
		segundo.pb(s[ini++]);

	
	ini++;						//skipa o '='

	string result;

	for(int i=ini;i<s.size();i++)
		result.pb(s[i]);


	for(int i=0;i<10;i++){
		
		ll a,b,c;

		if( (primo[i]=='?' && primo.size()>1) && !i )
			continue;

		if( (segundo[i]=='?' && segundo.size()>1) && !i )
			continue;

		if( (result[i]=='?' && result.size()>1) && !i )
			continue;

		if(primo[0]=='-' && primo[1]=='?' && !i)
			continue;
		
		if(segundo[0]=='-' && segundo[1]=='?' && !i)
			continue;
		
		if(result[0]=='-' && result[1]=='?' && !i)
			continue;

		a=to_int(primo,i);
		b=to_int(segundo,i);
		c=to_int(result,i);
		
		if(calc(a,b,opera)==c && !cnt[i]){
			cout << i << endl;
			return;
		}

	}

	cout << -1 << endl;


}

int main(){

	fastio;

	int t; cin >> t;
	string x;
	getline(cin,x);
	while(t--)	solve();

}
