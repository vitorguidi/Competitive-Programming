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
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int mod = 1e9+7;

ll gcd(ll a, ll b){
	return b==0 ? a : gcd(b,a%b);
}

int sz(ll x){
	int ans=0;
	do{
		ans++;
		x/=10;
	}while(x);
	return ans;
}

bool check(ll x){

	if(x<10)
		return false;

	string s;

	while(x){
		s.pb(x%10+'0');
		x/=10;
	}

	reverse(all(s));

	int l = s.size();
	string s2;

	ll x1=0,x2=0;

	for(int i =0;i<(l+1)/2;i++)
		x1=10*x1+(s[i]-'0');
	for(int i =(l+1)/2;i<s.size();i++)
		x2=10*x2+(s[i]-'0');

	if(x1==0 || x2==0)
		return false;

	return gcd(x1,x2)==1;

}

void solve(){

	ll l,r;
	cin >> l >> r;

	ll ans=-1;

	for(ll i = r;i>=l;i--){
		if(check(i)){
			ans=i;
			break;
		}
	}

	cout << ans << endl;

}

int main(){
	
	fastio;
	int t; 
	cin >> t;
	while(t--)	solve();

}