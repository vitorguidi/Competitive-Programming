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

long double v[200200];

void update(ll id, long double val, vector<long double>& bit){
	
	for(int i=id;i<800800;i+=i&-i)
		bit[i]+=val;

}

long double query(ll id, vector<long double>& bit){


	long double ans = 0;

	for(ll i=id;i>0;i-=i&-i)
		ans+=bit[i];

	return ans;


}

int main(){
    
	fastio;

	int n; cin >> n;

	map<long double,ll> id;
	map<ll,long double> rid;

	vector<long double> bit_val(1100100);
	vector<long double> bit_freq(1100100);

	vector<long double> aux;

	frr(i,n){
		long double x; cin >> x;
		aux.pb(x);
		aux.pb(x-1);
		aux.pb(x+1);
		v[i]=x;
	}

	sort(all(aux));
	ll cnt = 10ll;

	for(auto x : aux){
		if(!id[x]){
			id[x]=cnt;
			rid[cnt]=x;
			cnt++;
		}
	}

	frr(i,n)
		v[i]=id[v[i]];

	long double ans = 0ll;

	for(ll i=n;i>0ll;i--){
		
		ll right = v[i]+1ll;
		ll left = v[i]-1ll;

		ll freq_right = query(800800ll,bit_freq) - query(right,bit_freq);
		ll freq_left = query(left-1ll,bit_freq);

		ans+=(-1.0)*rid[v[i]]*(freq_right+freq_left);

		ans+= query(800800,bit_val) - query(right,bit_val);
		ans+= query(left-1ll,bit_val);

		update(v[i],1.0,bit_freq);
		update(v[i],rid[v[i]],bit_val);

	}

	cout << setprecision(0) << fixed;

	cout << ans << endl;


}

