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

bool is_prime(ll x){
	if(x==1)	return false;
	for(ll i =2ll;i*i<=x;i++)
		if(x%i==0)
			return false;
	return true;
}

int main(){
    
	fastio;

	int t; cin >> t;
	while(t--){
		ll a,b; cin >> a >> b;
		if(a-b==1 && a+b==1)
			cout << "NO" << endl;
		else if(a-b!=1 && a+b!=1)
			cout << "NO" << endl;
		else if(is_prime(a-b) || is_prime(a+b))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

}

