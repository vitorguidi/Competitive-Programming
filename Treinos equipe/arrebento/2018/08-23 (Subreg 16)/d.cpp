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

ll a,b,c,d;

bool check(ll x){

	if(x%b==0)
		return false;
	if(d%x==0)
		return false;
	if(c%x!=0)
		return false;
	if(x>c)
		return false;

	return true;

}

int main(){

	
	cin >> a >> b >> c >> d;

	for(ll i=1;i*i<=c;i++){
		
		if(check(a*i)){
			cout << a*i << endl;
			return 0;
		}

	}

	cout << -1 << endl;
}