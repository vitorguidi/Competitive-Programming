#include "bits/stdc++.h"
using namespace std;

#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define ms(x, v) memset(x, v, sizeof x)
#define all(x)	x.begin(),x.end()
#define grtp greater<pair<int,int>>()
#define grti greater<int>()
#define dbg(x) cout << #x << " = " << x << endl
#define gnl cout << endl

const int INF = 0x3f3f3f3f;

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int main(){
	int n,a,b;
	cin >> n >> a >> b;
	vector<int> hls;
	
	int fh;
	cin >> fh;

	int sum=fh;

	fr(i,n-1){
		int si;
		cin >> si;
		hls.pb(si);
		sum+=si;
	}

	if(fh*a/sum>=b){
		cout << 0 << endl;
		return 0;
	}

	sort(all(hls),grti);

	int cnt=0;
	fr(i,n-1){
		cnt++;
		sum-=hls[i];
		if(fh*a/sum>=b){
			cout << cnt << endl;
			return 0;
		}
	}

}