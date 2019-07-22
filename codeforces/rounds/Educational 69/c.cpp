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

vector<ll> v;
ll n,k;

bool comp(ll a, ll b){
    int difa = v[a+1]-v[a];
    int difb = v[b+1]-v[b];
    return difa<difb;
}

int main(){

	fastio;

    cin >> n >> k;

    v.resize(n);

    fr(i,n)
        cin >> v[i];

    if(n==k){
        cout << 0 << endl;
        return 0;
    }

    if(k==1){
        cout << abs(v[n-1]-v[0]) << endl;
        return 0;
    }


    vi aux;
    fr(i,n-1)
        aux.pb(i);

    sort(all(aux),comp);

    vector<ll> ans;

    fr(i,k-1){
        ans.pb(aux[n-2-i]);
    }

    sort(all(ans));

    int ini=0;

    ll to = 0;

    for(auto x : ans){
        ll mn = INF;
        ll mx = -1;
        for(int i=ini;i<=x;i++){
            mn=min(mn,v[i]);
            mx=max(mx,v[i]);
        }
        to+=abs(mn-mx);
        ini=x+1;
    }

    ll mn = INF;
    ll mx = -1;
    for(int i=ini;i<=n-1;i++){
        mn=min(mn,v[i]);
        mx=max(mx,v[i]);
    }
    to+=abs(mn-mx);

    cout << to << endl;


}