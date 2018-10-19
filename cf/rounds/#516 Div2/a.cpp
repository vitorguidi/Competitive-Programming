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

bool check(int x, int y, int z){
	return (x<y+z) && (y<x+z) && (z<x+y);
}

int main(){
    
	fastio;

	int a,b,c; cin >> a >> b >> c;

	if(check(a,b,c)){
		cout << 0 << endl;
		return 0;
	}

	int ans = INF;

	fr(dx,101){
		fr(dy,101){
			fr(dz,101){
				if(check(a+dx,b+dy,c+dz))
					ans=min(ans,dx+dy+dz);
			}
		}
	}

	cout << ans << endl;

}

