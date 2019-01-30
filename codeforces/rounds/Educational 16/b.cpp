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

ll acuml[300300];
ll acumr[300300];

int main(){
    
	fastio;

	ll n; cin >> n;

	vector<ll> v(n);
	fr(i,n)	cin >> v[i];
	sort(all(v));

	fr(i,n)	acuml[i+1]=acumr[i+1]=v[i];

	for(int i=n;i>0;i--)	acumr[i]+=acumr[i+1];
	for(int i=1;i<=n;i++)	acuml[i]+=acuml[i-1];

	ll bd = 5ll*(ll)1e18;
	int best = -1;

	for(ll i=1;i<=n;i++){

		ll dist = 0;

		dist+= abs<ll>( (i-1ll)*v[i-1] - acuml[i-1] );
		
		dist+= abs<ll>( acumr[i+1] - (n-i)*v[i-1] );
		
		if(dist<bd){
			bd=dist;
			best=v[i-1];
		}

	}
	
	cout << best << endl;

}

