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
#define LAU cout << "LAW" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int main(){
	fastio;
	ll t,soma;
	cin >> t;
	while(t--){
		soma=0;
		int n; cin >> n;
		vi seq;
		int mdc = 0;
		fr(i,n){
			int aux; cin >> aux;
			seq.pb(aux);
			mdc = __gcd(mdc,aux);
			soma+=aux;
		}
			
		cout<<soma<<' '<<mdc<<endl;	
		seq.clear();
	}

}