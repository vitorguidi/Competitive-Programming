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
map<string,int> email;
int n;

void solve(string s){
	string aux;
	bool m,a;
	m=0,a=0;
	int pos=0;
	while(m==0 && a==0){
		if(s[pos]=='+'){
			m=1;
			pos++;
			continue;
		}
		if(s[pos]=='@'){
			a=1;
			pos++;
			continue;
		}
		if(s[pos]=='.'){
			pos++;
			continue;
		}

		aux.pb(s[pos]);
		pos++;
	}

	while(m && a==0){
		if(s[pos]=='@')
			a=1;
		pos++;
	}
	aux.pb('@');

	while(pos!=s.size()){
		aux.pb(s[pos]);
		pos++;
	}

	email[aux]++;
}

int main(){

	fastio;
	cin>>n;

	string s;
	fr(i,n){
		cin>>s;
		solve(s);
	}

	cout<<email.size()<<endl;
}
