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

int main(){

	fastio;

	int n; cin >> n;
	string s;

	cin >> s;
	for(int i=0;i<n-1;i++) {
		s+=' ';
		string c; cin >> c;
		s += c;
	}

	int keys; cin >> keys;
	string ans;
	bool caps = false;
	while(keys--) {
		string key;
		cin >> key;
		if(key == "CapsLock") {
			caps ^= true;
		} else if(key == "Space") {
			ans += ' ';
		} else if(key == "Backspace") {
			if(!ans.empty()) ans.pop_back();
		} else {
			if(caps) ans+= (key[0]-'a')+'A';
			else	 ans+= key[0];
		}
	}
	// cout << s + '-' << endl;

	// cout << ans << endl;

	if(s == ans)	cout << "Correct" << endl;
	else			cout << "Incorrect"   << endl;

	return 0;

}
