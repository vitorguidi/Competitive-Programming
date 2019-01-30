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

ll bit[200200];

void update(ll ind, ll val){
	for(int i=ind;i<200200;i+=i&-i)
		bit[i]+=val;
}

ll query(ll ind){
	ll ans = 0;
	for(int i = ind;i>0;i-=i&-i)
		ans+=bit[i];
	return ans;
}

int main(){
    
	fastio;

	ll n,k; cin >> n >> k;

	ll mx=0;

	frr(i,n){
		ll x; cin >> x;
		mx=max<ll>(mx,x);
		update(1,1);
		update(x+1,-1);
	}

	int cnt = 0;

	ll ini = mx;

	while(ini>0){
		ll amt = 0;
		if(query(ini)==n)
			break;
		while(amt+query(ini)<=k && ini>0 && query(ini)!=n){
			amt+=query(ini);
			ini--;
		}
		cnt++;
	}

	cout << cnt << endl;

}

