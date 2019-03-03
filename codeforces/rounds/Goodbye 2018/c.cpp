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

set<int> divisors;
ll n; 

void go(ll val){

	set<ll> ans;
	ans.insert(1);
	ans.insert((val*(val+1ll))/2ll);

	for(auto i : divisors){

		if(i==1)	continue;
		if(i>val/2)	break;

		ll lol = n/i;
		ll amt = lol;

		amt += ( (lol*(lol-1ll)*i)/2ll );

		ans.insert(amt);


	}

	for(auto x : ans)	cout << x << ' ';
	gnl;

}

int main(){
    
	fastio;

	cin >> n;

	for(ll i=1;i*i<=n;i++){
		if(n%i==0){
			divisors.insert(i);
			divisors.insert(n/i);
		}
	}

	go(n);
	

}