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

	int n,s;
	cin >> n >> s;
	vector<int> time;

	int h,m,t;

	fr(i,n){
		cin >> h >> m;
		t=60*h+m;
		time.pb(t);
	}

	if(time[0]>s){
		cout << "0 0" << endl;
		return 0;
	}

	frr(i,n-1){
		if(time[i-1]+s+1<=time[i]-s-1){
			cout << (time[i-1]+s+1)/60 << " " << (time[i-1]+s+1)%60 << endl;
			return 0;
		}
	}

	cout << (time[n-1]+s+1)/60 << " " << (time[n-1]+s+1)%60 << endl;
	
}