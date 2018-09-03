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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

vi seq;
vi rems[11];

int calc(ll x){

	int cnt = 0;

	while(x){
		cnt++;
		x=x/10;
	}

	return cnt;

}

int main(){

	int n,k;
	cin >> n >> k;

	fr(i,n){
		int aux; cin >> aux;
		seq.pb(aux);
	}

	sort(all(seq));

	fr(i,n){
		frr(j,10){
			ll num = seq[i];
			ll bago = (ll)pow(10,j);
			bago=bago%k;
			num = num%k;
			num=num*bago;
			num=num%k;
			rems[j].pb(num);
		}	
	}

	frr(i,10)
		sort( all(rems[i]) );
	
	ll ans = 0;

	fr(i,n){

		ll base = seq[i];
		base = base%k;
	
		ll desired = k - base;

		if(desired==k)
			desired=0;

		int len = calc(seq[i]);
		
		auto right = upper_bound(all(rems[len]),desired);
		auto left = lower_bound( all(rems[len]),desired );

		ans+=right-left;

		ll aux = (ll)pow(10,len);
		aux=aux%k;
		aux=aux*seq[i];
		aux=aux%k;

		if(aux==desired)
			ans--;
	
	}

	cout << ans << endl;

}