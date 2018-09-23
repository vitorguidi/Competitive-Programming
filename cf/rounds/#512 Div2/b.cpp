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
#define pira cout << "pira" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int n,d;

bool check(int x, int y){
	return (y>=-1*x+d) && (y<=x+d) && (y<=-1*x+2*n-d) && (y>=x-d);
}

int main(){
    
	fastio;

	cin >> n >> d;

	int m; cin >> m;

	fr(i,m){
		int x,y; cin >> x >> y;
		if(check(x,y))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

}

