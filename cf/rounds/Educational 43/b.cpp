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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int main(){
    
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n,m,k; cin >> n >> m >> k;

	if(0<=k && k<=n-1){
		cout << k+1 << " " << 1 << endl;
		return 0;
	}

	k-=n-1;

	ll x,y;
	x=n;

	ll a = k/(m-1);

	x-=a-1;

	if(x%2)
		y=2;
	else
		y=m;
	
	k-=a*(m-1);


	if(k){
		x--;
		if(x%2)
			y-=k-1;
		else
			y+=k-1;
	}

	cout << x << " " << y << endl;



}