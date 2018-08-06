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

ll check[1000010];
vector<ll> ans;

int main(){

	
	for(ll i=2;i<=1e6;i++){

		if(!check[i]){

			for(int j=i;j<=1e6;j+=i)
				check[j]=1;

			ll aux = i*i;
			while(aux<=1e12){
				ans.pb(aux);
				aux=aux*i;
			}
		}
		
	}

	sort(all(ans));

	int n; cin >> n;
	while(n--){
		ll x,y;
		cin >> x >> y;

		auto left = lower_bound(all(ans),x);
		auto right = upper_bound(all(ans),y);

		int amt =right - left;

		cout << amt << endl;

	}

}