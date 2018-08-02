#include "bits/stdc++.h"
using namespace std;
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)
#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;
typedef vector< vector<ll> > matrix;
const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;
const ll mod = 1e9+7;

int main(){

	int n,m;
	cin >> n >> m;

	if(m<n-1){
		cout << "Impossible" << endl;
		return 0;
	}

	vii ans;
	int cnt=0;

	for(int i=1;i<=n;i++){

		for(int j=i+1;j<=n;j++){
			if(__gcd(i,j)==1){
				ans.pb({i,j});
				cnt++;
			}
			if(cnt==m)
				break;
		}
		if(cnt==m)
			break;

	}

	if(cnt<m){
		cout << "Impossible" << endl;
		return 0;
	}

	cout << "Possible" << endl;
	for(auto x : ans){
		cout << x.fst << " " << x.snd << endl;
	}

}