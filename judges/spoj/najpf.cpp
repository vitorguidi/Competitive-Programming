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

string s,p;
int pi[2100100];

void pre () {

	p += '#';

	pi[0] = pi[1] = 0;

	for (int i = 2; i <= p.size(); i++) {		//indexando a string de 1, p[i-1] eh pra compensar isso

		pi[i] = pi[i-1];

		while (pi[i] > 0 and p[pi[i]] != p[i-1])
			pi[i] = pi[pi[i]];

		if (p[pi[i]] == p[i-1])
			pi[i]++;

	}
}

vi kmp(){

	pre ();

	vi ans;
	int k = 0;
	int m = p.size() - 1;

	for (int i = 0; i < s.size(); i++) {
		
		while (k > 0 and p[k] != s[i])
			k = pi[k];
		
		if (p[k] == s[i])
			k++;

		if (k == m)
			ans.pb(i-m+2);
	}

	return ans;

}

void solve(){

	cin >> s;
	cin >> p;

	vi ans = kmp();

	if(!ans.size()){
		cout << "Not Found" << endl << endl;
		return;
	}

	cout << ans.size() << endl;
	for(auto x : ans)
		cout << x << " ";
	gnl;gnl;

}

int main(){

	fastio;
	int t;cin>>t;
	getline(cin,s);
	while(t--)	solve();

}