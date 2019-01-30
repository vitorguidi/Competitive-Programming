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

ll calc(ll x){
	ll ans = 0;
	while(x){
		ans+=x%10;
		x/=10;
	}
	return ans;
}

int main(){
    
	fastio;

	ll x,y;
	cin >> x;
	y=x;
	int cnt = 0;


	if(x<10){
		cout << x << endl;
		return 0;
	}

	while(y){
		cnt++;
		y/=10;
	}
	cnt--;

	ll aux = 1;
	fr(i,cnt)
		aux*=10ll;
	aux--;


	ll ans = 0;
	ans+=calc(aux);
	ans+=calc(x-aux);

	cout << ans << endl;



}

