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

    ll n,m,r;
    cin >> n >> m >> r;

    ll buy = INF;

    frr(i,n){
        ll x; cin >> x;
        buy = min(buy,x);
    }

    ll sell = 0;

    frr(i,m){
        ll x; cin >> x;
        sell = max(sell,x);
    }

    ll tem = r/buy;

    ll sobra = r%buy;

    ll profit = sell*tem;

    cout << max(r,sobra + profit) << endl;

}