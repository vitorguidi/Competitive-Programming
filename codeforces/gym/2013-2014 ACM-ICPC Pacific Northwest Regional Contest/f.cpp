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
 
void go(ll n){

	set<ll> div;
	ll ans = 1;

	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			div.insert(i);
			ans+=i;
			if(i!=n/i){
				div.insert(n/i);
				ans+=n/i;
			}
		}
	}

	if(ans!=n)
		cout << n << " is NOT perfect." << endl;
	else{
		cout << n << " = 1";
		for(auto x : div)
			cout << " + " << x;
		cout << endl;
	}


}

int main(){

	fastio;
	ll n; 
	while(cin >> n){
		if(n==-1)	break;
		go(n);
	}
 
}