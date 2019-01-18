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
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

vector<ll> aux;
ll v[1010];
ll memo[1010];
ll n,c,t1,t2;

ll pd(int ind){

	if(ind==n)	return 0;

	ll &pdm = memo[ind];
	if(pdm!=-1)	return pdm;

	ll ini = aux[ind];

	pdm=llINF;

	int nxt = upper_bound(all(aux),t1+ini) - aux.begin();
	pdm=min<ll>(t1+pd(nxt),pdm);

	nxt = upper_bound(all(aux),t2+ini) - aux.begin();
	pdm=min<ll>(t2+pd(nxt),pdm);

	return pdm;

}

int main(){

	fastio;

	cin >> n >> c >> t1 >> t2;

	fr(i,n)
		cin >> v[i];

	ll ans = llINF;

	fr(i,n){

		aux.clear();

		fr(j,n){

			ll val = v[(j+i)%n]-v[i];
			if(val<0)	val+=c;
			aux.pb(val);
			//ans=min<ll>(ans,pd(0));
		}

		ms(memo,-1);

		ans=min<ll>(ans,pd(0));

	}	

	cout << ans << endl;

}
