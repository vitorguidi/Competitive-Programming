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

ll cnt[2][2];

int main(){
    
	fastio;

	int n;	cin >> n;
	string a,b;
	cin >> a >> b;

	fr(i,n){
		int x = a[i]-'0';
		int y = b[i]-'0';
		cnt[x][y]++;
	}

	ll ans = 0;

	ans+=cnt[0][0]*cnt[1][0];
	ans+=cnt[0][0]*cnt[1][1];
	
	ans+=cnt[0][1]*cnt[1][0];

	ans+=cnt[1][0]*cnt[0][0];
	ans+=cnt[1][0]*cnt[0][1];

	ans+=cnt[1][1]*cnt[0][0];

	cout << ans/2ll	 << endl;

}

