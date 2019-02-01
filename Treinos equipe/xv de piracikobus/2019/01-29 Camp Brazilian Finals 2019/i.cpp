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
int k,l,m;


ll g[1001000];
int mex(set<int>& x){
	fr(i,4)
		if(x.find(i)==x.end())
			return i;
}
void grundy(){
	g[0] = 0;
	frr(i,1000000){
		int a,b,c;
		a = INF;b = INF;c = INF;
		a = g[i-1];
		set<int> x;
		if((i - k) >= 0)
			b = g[i-k];
		if((i-l) >= 0)
			c = g[i-l];

		x.insert(a);
		x.insert(b);
		x.insert(c);

		g[i] = mex(x);

	}

}


int main(){

	fastio;

	cin >> k >> l >> m;


	grundy();
	ll ans;
	string s;
	fr(i,m){
		int a;
		cin >> a;
		if(g[a] == 0)
			s.pb('B');
		else
			s.pb('A');
	}
	cout << s << endl;



}
