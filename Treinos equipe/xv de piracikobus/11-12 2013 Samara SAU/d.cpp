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
	int n;
	cin >> n;
	string s,t,v;
	getline(cin,s);
	getline(cin,s);
	getline(cin,t);
	getline(cin,v);
	string ans;

	fr(i,n){
		if(s[i] == t[i])
			ans.pb(s[i]);
		else if(s[i] == v[i])
			ans.pb(s[i]);
		else if (v[i] == t[i])
			ans.pb(v[i]);
		else
			ans.pb(s[i]);
	}


	cout << ans << endl;
	


}