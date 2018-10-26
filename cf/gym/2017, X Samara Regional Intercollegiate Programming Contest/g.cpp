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
	string s[222345];
	getline(cin,s[0]);

	frr(i,n)
		getline(cin,s[i]);

	int m;
	cin >> m;

	vii v;

	fr(i,m){
		int a,b;
		cin >> a >> b;
		v.pb(mp(a,b));
	}

	int len = v.size();
	int p = len-1;

	int ct = 0;
	int proc = 1;

	for(int i = p;i>=0;i--){
		if(v[i].fst == proc){
			ct++;
			proc = v[i].snd;
		}
	}

	fr(j,ct){
		cout <<"I_love_";
	}
	cout<<s[proc]<<endl;
}
