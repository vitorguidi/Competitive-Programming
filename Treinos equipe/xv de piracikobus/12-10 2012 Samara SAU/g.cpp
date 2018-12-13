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

int main(){
	fastio;
	string s;
	map<char,int> m;
	map <char,int> e;

	getline(cin,s);

	if(s.size() > 26) {
		cout << "IMPOSSIBLE\n";
		return (0);
	}

	fr(i,s.size())
		e[s[i]] = 1;

	fr(i,s.size()){
		if (m[s[i]] == 0){
			m[s[i]] = 1;
			continue;
		}

		fr(j,26){
			if(e['a' + j] == 0){
				m['a' + j] = 1;
				e['a' + j] = 1;
				s[i] = 'a' + j;
				break;
			}

		}
	}

	cout << s << endl;
	

}
