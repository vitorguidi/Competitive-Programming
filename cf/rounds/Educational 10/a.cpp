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

int main(){
    
	fastio;

	ll h1,h2;
	ll a,b;

	cin >> h1 >> h2 >> a >> b;
	
	h1-=a*4ll;

	for(ll i=1;i<=10000000;i++){
		
		for(ll j=1;j<=12;j++){
			h1+=a;
			if(h1>=h2 && j>=4){
				cout << i-1 << endl;
				return 0;
			}
		}
		
		h1-=12ll*b;
	}

	cout << -1 << endl;

}

