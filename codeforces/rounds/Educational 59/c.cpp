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

ll cost[200100];
string s;

int main(){
    
	fastio;

	int n,k;
	cin >> n >> k;

	fr(i,n)	cin >> cost[i];

	cin >> s;

	int ini=0;
	int end=0;

	ll ans = 0;

	while(ini<n){

		vector<ll> aux;
		while(s[ini]==s[end] && end<n){
			aux.pb(cost[end]);
			end++;
		}

		sort(all(aux));
		reverse(all(aux));

		ll len = min<ll>(aux.size(),k);

		fr(i,len)	ans+=aux[i];

		ini=end;

	}

	cout << ans << endl;

}