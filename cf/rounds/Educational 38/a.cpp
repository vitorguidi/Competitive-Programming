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
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

bool vowel(char x){
	return (x=='a' || x=='e' || x=='i' || x=='o' || x=='u' || x=='y');
}

string lol(string s){

	int n = s.size();


	fr(i,n-1){
		if( vowel(s[i]) && vowel(s[i+1]))  
			s[i+1]='#';
	}

	string aux;

	for(auto x : s)
		if(x!='#')
			aux.pb(x);

	return aux;


}

int main(){
    
	fastio;

	int n; cin >> n;
	string s; cin >> s;

	while(s!=lol(s))
		s=lol(s);

	cout << s << endl;
}

