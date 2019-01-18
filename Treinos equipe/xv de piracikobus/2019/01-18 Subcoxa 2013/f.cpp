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

ll v[100100];
map<ll,ll> freq;

int main(){

	fastio;

	int n; cin >> n;

	ll sum=0;

	frr(i,n){
		ll x; cin >> x;
		x*=3ll;
		sum+=x;
		v[i]=x+v[i-1];
		if(i!=n)	freq[v[i]]++;
		else		freq[0]++;
	}

	ll dist = sum/3ll;

	ll ans = 0;

	fr(i,n){
		ll left = (v[i]-dist+sum)%sum;
		ll right = (v[i]+dist+sum)%sum;
		ll aux = freq[left]*freq[right];
		ans+=freq[left]*freq[right];
	}

	cout << ans/3ll << endl;

}
