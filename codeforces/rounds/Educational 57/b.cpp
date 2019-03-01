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
const ll MOD =  998244353;

ll solve(string x){

	char aux = x[0];
	ll l,r;

	fr(i,x.size()){
		if(x[i]!=x[0]){
			l=i;
			break;
		}
	}

	return l+1;

}

int main(){
    
	fastio;

	int n; cin >> n;	

	string s; cin >> s;


	char l = s[0];
	char r = s[n-1];

	if(l==r){

		int x,y;

		fr(i,n)
			if(s[i]!=l){
				x=i;
				break;
			}

		for(int i=n-1;i>=0;i--){
			if(s[i]!=l){
				y=i;
				break;
			}
		}

		ll ans = ll(x+1)*ll(n-y);
		ans%=MOD; 

		cout << ans << endl;
		return 0;

	}

	ll ans = 0;

	ans+=solve(s);
	ans%=MOD;

	reverse(all(s));

	ans+=solve(s);
	ans--;
	ans%=MOD;

	cout << ans << endl;


}