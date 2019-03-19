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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll; 

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int calc(char x){
	return x - '0';
}

void solve(){

	ll n,m;
	cin >> n >> m;
	
	string x,y;
	
	m*=60;
	ll ans = 0;

	fr(i,n){
		
		cin >> x; cin >> y;

		ll h1=0;
		h1+=10*60*calc(y[0]);
		h1+=60*calc(y[1]);
		h1+=10*calc(y[3]);
		h1+=calc(y[4]);
	
		ll h2=0;
		h2+=10*60*calc(x[0]);
		h2+=60*calc(x[1]);
		h2+=10*calc(x[3]);
		h2+=calc(x[4]);

		ans+=h1-h2;

	}

	if(ans>=m)
		puts("YES");
	else
		puts("NO");

}

int main(){

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t; cin >> t;

	while(t--)	solve();

}