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

string as,bs;
int cnt[12];

string stringify(ll x){

	string ans;

	do{
		ans.pb('0'+x%10);
		x/=10ll;
	}while(x);

	reverse(all(ans));
	return ans;

}

ll to_num(string x){
	ll ans = 0;
	ll base = 1ll;
	int len = x.size()-1;
	for(int i=len;i>=0;i--){
		ans+=(x[i]-'0')*base;
		base*=10ll;
	}
	return ans;
}

ll tenpow(int x){
	ll ans = 1;
	fr(i,x)
		ans*=10;
	return ans;
}

ll get_min(){

	string s;
	fr(i,10){
		if(cnt[i])
			fr(j,cnt[i])
				s.pb(i+'0');
	}

	return to_num(s);

}

int main(){
    
	fastio;

	ll a,b; cin >> a >> b;

	as=stringify(a);
	bs=stringify(b);

	if(as.size()<bs.size()){
		sort(all(as));
		reverse(all(as));
		cout << as << endl;
		return 0;
	}

	for(auto x : as)
		cnt[x-'0']++;

	int len = as.size();
	len--;

	ll ans = 0;

	for(ll i=len;i>=0;i--){

		for(ll j=9;j>=0;j--){

			if(!cnt[j])			continue;

			ll cand = j*tenpow(i);
			cnt[j]--;

			if(ans+cand+get_min()<=b){
				ans=ans+cand;
				break;
			}

			cnt[j]++;

		}


	}

	cout << ans << endl;
	

}

