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
#define olar cout << "pira" << endl

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll; 

const int INF = 0x3f3f3f3f;

ll cards[1100100];
int n,k;

bool check(ll x){

	int cnt=0;
	int ini=0;
	
	while(ini<n){
		
		ll aux = 1;
		ll mx = -INF;
		int amt=0;
	
		while(aux<=x && ini<n){
			
			amt++;
			mx=max(mx,cards[ini]);
			
			if(mx*amt<=x){
				aux=mx*amt;
				ini++;
			}

			else
				break;
		}
		
		cnt++;
		if(cards[ini]>x)
			return false;
		
	}
	
	return cnt<=k;

}

void solve(){

	cin >> n >> k;

	fr(i,n)
		cin >> cards[i];

	ll ini=1,end=(ll)1e12;
	ll ans = (ll)1e13;
	
	fr(i,200){
	
		ll mid = (ini+end)/2;
	
		if(check(mid)){
			ans=min(ans,mid);
			end=mid-1;
		}
	
		else
			ini=mid+1;
	
	}

	cout << ans << endl;

}

int main(){

	int t; cin >> t;
	while(t--)	solve();

}