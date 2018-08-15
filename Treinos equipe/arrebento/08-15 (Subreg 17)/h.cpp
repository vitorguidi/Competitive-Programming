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
#define pira cout << "pira" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

ll ori(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3){
	return ((x2-x1)*(y3-y2) - (x3-x2)*(y2-y1));
}

int main(){
    vector<ll> x, y;
    ll xa, xb, n, cont, ans, i1, i2;

    cin >> n >> xa >> xb;

    fr (i, n){
    	cin >> i1 >> i2;
    	x.pb(i1);
    	y.pb(i2);
    }

	ans = 0;
    fr(i, n){
    	cont = 1;

    	fr(j, n){
    		if (i != j){
    			if(ori(xa, 0, x[i], y[i], x[j], y[j]) < 0 && ori(xb, 0, x[i], y[i], x[j], y[j]) > 0) cont++;
    			//if(lint(x[i g ], y[i], x[j], y[j], xa, xb) && lint(x[i], y[i], x[j], y[j], xb, xa)) cont++;
    		}
    	}	

    	ans = max(ans, cont);
    }

    cout << ans << endl; 

}