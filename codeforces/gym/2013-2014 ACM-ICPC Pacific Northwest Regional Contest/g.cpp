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
 
ll v[110];



ll f(ll x){

	if(v[x])	return v[x];

	return v[x]= f(x-1)+f(x-2)+f(x-3)+f(x-4);

}

int main(){

	fastio;

	v[0]=1;
	v[1]=1;
	v[2]=2;
	v[3]=4;

	int t;cin >> t;
	while(t--){
		ll x; cin >> x;
		cout << f(x) << endl;
	}	
 
}