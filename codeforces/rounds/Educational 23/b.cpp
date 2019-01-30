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

ll par;
ll terc;

vector<ll> v;

int main(){
    
	fastio;
	ll n; cin >> n;

	map<ll,ll> cnt;

	v.resize(n);

	fr(i,n){
		cin >> v[i];
		cnt[v[i]]++;
	}

	sort(all(v));

	set<int> caras;

	caras.insert(v[0]);
	caras.insert(v[1]);
	caras.insert(v[2]);

	if(caras.size()==1){
		ll aux = cnt[v[0]];
		ll ans = aux*(aux-1ll)*(aux-2ll);
		ans/=6ll;
		cout << ans << endl;
		return 0;
	}

	else if(caras.size()==3){
		cout << cnt[v[2]] << endl;
		return 0;
	}

	if(v[0]==v[1])
		cout << cnt[v[2]] << endl;
	else{
		ll aux = cnt[v[2]];
		ll ans = aux*(aux-1ll);
		ans/=2ll;
		cout << ans << endl;
	}


}

