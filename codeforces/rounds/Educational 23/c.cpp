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

ll n,s;

bool check(ll x){

	ll num = x;
	ll sum =0;

	do{
		sum+=x%10ll;
		x/=10ll;
	}while(x);

	return num-sum>=s;

}

int main(){
    
	fastio;

	cin >> n >> s;

	ll ini=1;
	ll end=n;

	ll best = (ll)1e18+100;

	while(ini<=end){
		
		ll mid=(ini+end)/2ll;

		if(check(mid)){
			best=min<ll>(best,mid);	//tenta diminuir
			end=mid-1;
		}
		else
			ini=mid+1;

	}

	cout << (best<=n ? (n-best+1ll) : 0) << endl;

}

