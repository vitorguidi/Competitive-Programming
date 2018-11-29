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

	int t; cin >> t;
	while(t--){

		int n,x,y,d;
		cin >> n >> x >> y >> d;

		int ans = INF;

		int norm = abs(x-y);

		if(norm%d==0)
			ans=min(ans,norm/d);

		if(abs(y-1)%d==0)
			ans=min( ans, abs(y-1)/d + (abs(x-1)+d-1)/d );

		if(abs(n-y)%d==0)
			ans=min(ans, abs(n-y)/d + (abs(x-n)+d-1)/d);


		cout << (ans!=INF ? ans : -1) << endl;
		


	}

}

