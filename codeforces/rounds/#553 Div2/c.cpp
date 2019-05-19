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
const ll MOD = 1e9+7;

ll fastxp(ll base, ll exp){
    base%=MOD;
    ll ans = 1;
    while(exp){
        if(exp%2)
            ans*=base;
        base*=base;
        base%=MOD;
        ans%=MOD;
        exp/=2;
    }
    return ans;
}

ll invmod(ll x){
    return fastxp(x, MOD-2);
}

ll getsum(ll primeiro, ll amt){

    primeiro%=MOD;
    amt%=MOD;

    ll ultimo = primeiro + 2ll*(amt-1ll);
    ultimo%=MOD;

    ll ans = primeiro+ultimo;
    ans%=MOD;

    ans*=amt;
    ans%=MOD;

    ans*=invmod(2);
    ans%=MOD;

    return ans;

}

ll query(ll x){

    if(x==0)    return 0;

    ll cnt = 0;

    ll num_odd=0;
    ll num_even=0;

    while(x>0){
        ll tira = min(x, 1ll<<cnt);
        x-=tira;
        if(cnt%2)
            num_even+=tira;
        else
            num_odd+=tira;
        cnt++;
    }

    ll ans = getsum(1,num_odd);
    ans+=getsum(2,num_even);
    ans%=MOD;

    return ans;

}


int main(){

	fastio;

    ll l,r;
    cin >> l >> r;

    ll ans = query(r)-query(l-1ll);
    ans%=MOD;
    if(ans<0)
        ans+=MOD;

    cout << ans << endl;

}