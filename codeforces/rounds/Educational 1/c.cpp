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
#define olar cout << "pira" << endl
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll; 

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const long double pi = acos(-1.0);

int main(){

	int n; cin >> n;
	vector<pair<long double,int>> v;

	frr(i,n){
		ll x,y; cin >> x >> y;
		long double p = atan2(y,x);
		if(p<0)	p+=2.0*pi;
		v.pb({p*180.0/pi,i});
	}

	sort(all(v));
	v.pb({v[0].fst+360,v[0].snd});
	long double ans = 1e18;

	int a,b;

	frr(i,n){
		if(v[i].fst-v[i-1].fst<ans){
			ans=v[i].fst-v[i-1].fst;
			a=v[i].snd;
			b=v[i-1].snd;
		}
	}

	cout << a << " " << b << endl;
	
} 