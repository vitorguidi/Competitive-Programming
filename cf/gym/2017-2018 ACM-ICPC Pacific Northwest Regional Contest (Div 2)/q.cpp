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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;


ll n; 
ll total;

ll query(ll x){

	return ( (x)*(2*n-x-1) )/2;

}

ll min(ll a, ll b){
	if(a<=b)
		return a;
	return b;
}

int main(){
    cin >> n;

	ll total = (n*(n-1))/2;

	ll ini=1;
	ll end = n;
	ll mid=(ini+end)/2;
	ll ans = mid;
	

	frr(i,300){
	
		mid=(ini+end)/2;
		if(mid==0)
			break;

		if(query(mid)>=(total+1)/2){
			ans=min(ans,mid);
			end=mid-1;
		}
		else
			ini=mid+1;

	}

	cout << ans << endl;

}

