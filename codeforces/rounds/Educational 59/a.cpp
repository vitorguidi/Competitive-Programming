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

void solve(){

	int n; cin >> n;

	string s; cin >> s;

	if(s.size()>2){
		cout << "YES" << endl;
		cout << 2 << endl;
		reverse(all(s));
		cout << s[n-1] << " ";
		s.pop_back();
		reverse(all(s));
		cout << s << endl;
		return;
	}

	if(s[0]>=s[1]){
		cout << "NO" << endl;
		return;
	}

	cout << "YES" << endl;
	cout << 2 << endl;

	cout << s[0] << " " << s[1] << endl;

}

int main(){
    
	fastio;

	int q; cin >> q;

	while(q--)	solve();

	

}