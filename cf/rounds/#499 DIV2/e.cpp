#include "bits/stdc++.h"
using namespace std;
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)
#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;
typedef vector< vector<ll> > matrix;
const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;
const ll mod = 1e9+7;

ll gcd(int a, int b){
	return b==0? a : gcd(b,a%b);
}

int main(){

	int n,k;
	cin >> n >> k;

	vi notes;
	
	fr(i,n){
		int x;cin >> x;
		notes.pb(x);
	}

	ll mdc = 0;

	fr(i,n)
		mdc=gcd(mdc,notes[i]);
	
	map<int,int> cnt;

	vi ans;
	ll factor = 1;
	
	while(true){
		ll aux = factor*mdc;
		aux=aux%k;
		if(cnt[aux])
			break;
		ans.pb(aux);
		cnt[aux]++;
		factor++;
	}

	sort(all(ans));
	cout << ans.size() << endl;
	for(auto x : ans)
		cout << x << " ";
	gnl;

}