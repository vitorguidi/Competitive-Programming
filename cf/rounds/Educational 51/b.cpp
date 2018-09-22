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

ll gcd(ll a, ll b){
	return b==0 ? a : gcd(b,a%b);
}

int main(){
    
	fastio;

	ll l,r;
	cin >> l >> r;

	vector<pll> ans;
	bool flag = true;

	for(ll i=l+1;i<=r;i+=2){
		ans.pb({i,i-1});
		if(gcd(i,i-1)!=1)
			flag=false;
	}

	if(!flag)
		cout << "NO" << endl;
		
	else{
		cout << "YES" << endl;
		for(auto x : ans)
			cout << x.fst << " " << x.snd << endl;
	}

}

