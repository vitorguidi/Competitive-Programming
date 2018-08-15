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

#define otp(x) cout << x << endl
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

ll mdc(ll a, ll b){
	return b==0 ? a : mdc(b,a%b);
}

ll mmc(ll a, ll b){
	ll aux;
	aux = a*b;
	return a*b/mdc(a,b);
}

int main(){
    
    ll n,l; cin >> n >> l;
    vector<ll> seq;

    fr(i,n){
    	ll aux; cin >> aux;
    	seq.pb(aux);
    }

    ll bango = 1;

    fr(i,n)
    	bango=mmc(seq[i],bango);

    int bigulho = 0;
    int cara = INF;

    for(int i=1;i<=l;i++){
    
    	ll aux = mmc(i,bango);
    
    	if(aux<=l && aux>bigulho){
    		bigulho = aux;
    		cara = i;
    	}
    
    }

    otp(cara);


}

