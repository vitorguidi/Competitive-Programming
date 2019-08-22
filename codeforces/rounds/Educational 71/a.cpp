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
const int MOD = 1e9+7;
 
int main(){
 
	fastio;

	int q; cin >> q;
	while(q--){

		ll pao,frango,carne;
		cin >> pao >> carne >> frango;

		ll pc,pf;
		cin >> pc >> pf;

		ll ans = 0;

		if(pc>pf){
			ll faz = min(pao/2,carne);
			pao-=2*faz;
			ans+=pc*faz;
			faz = min(pao/2,frango);
			ans+=pf*faz;
		}

		else{
			ll faz = min(pao/2,frango);
			pao-=2*faz;
			ans+=pf*faz;
			faz = min(pao/2,carne);
			ans+=pc*faz;
		}

		cout << ans << endl;

	}
 
}