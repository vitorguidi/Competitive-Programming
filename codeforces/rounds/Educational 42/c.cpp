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

set<ll> sq;
string s;
ll ans = INF;
string lol;
int len;


ll to_ll(string x){

	ll ans = 0;
	ll base = 1;

	for(int i=x.size()-1;i>=0;i--){
		ans+=base*(x[i]-'0');
		base*=10ll;
	}

	return ans;

}


void brute(int ind, int cnt){

	if(ind==len){

		ll aux = to_ll(lol);
		
		if(lol.size()==0 || lol[0]=='0')
			return;

		if(sq.find(aux)!=sq.end())
			ans=min<ll>(ans,cnt);
		
		return;
	
	}

	lol.pb(s[ind]);
	brute(ind+1,cnt);
	lol.pop_back();

	brute(ind+1,cnt+1);


}

string to_str(ll x){
	
	string s;
	
	while(x){
		s.pb(x%10 + '0');
		x/=10;
	}
	
	reverse(all(s));
	return s;

}

int main(){
    
	fastio;
	ll n; cin >> n;

	s = to_str(n);
	len = s.size();

	for(ll i=1;i*i<=2ll*(ll)1e9;i++)
		sq.insert(i*i);

	brute(0,0);

	cout << (ans != INF ? ans : -1) << endl;

}

