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

ll v[200200];
int n;

int main(){
    
	fastio;

	cin >> n;

	ll x; cin >> x;
	v[0]=0;
	v[n-1]=x;

	for(int i=1;i<n/2;i++){
		
		ll left = 0;
		ll right;

		cin >> right;

		if(left<v[i-1]){
			left=v[i-1];
			right-=left;
		}

		if(v[n-i]<right){
			ll delta = abs<ll>(v[n-i]-right);
			left+=delta;
			right-=delta;
		}		

		v[i]=left;
		v[n-1-i]=right;

	}

	fr(i,n){
		cout << v[i] << " ";
	}
	gnl;

}