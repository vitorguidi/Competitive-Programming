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
	int n;
	cin >> n;
	vi ans;

	int a;
	fr(i,n){
		cin >> a;
		if(a%2 == 0)
			ans.pb(1);
		else
			ans.pb(0);
	}

	int gru = 0;

	fr(i,n)
		gru = gru^ans[i];

	if(gru == 0) cout <<"Mike"<<endl;
	else cout << "Constantine"<<endl;

}
