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

int main(){

	fastio;
	int q;
	cin >> q;
	while(q--){
		ll s;
		cin >> s;
		ll ini = 0;
		ll fim = 2*(1e9);

		ll best = 0;

		while(fim >= ini){
			ll mid =(ini + fim)/2;
			if((mid*(mid+1))/2 <= s){
				ini = mid + 1;
				best = mid;
			}
			else
				fim = mid-1;
		}

		cout << best << endl;

	}

}
close