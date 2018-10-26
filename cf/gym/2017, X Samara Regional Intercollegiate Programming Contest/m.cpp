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
const ll MOD = 1e9+7;

ll n,tot,freq[200200];
stack<ll> matar,morrer;


int main(){

	fastio;
	cin>>n; 
	ll x;
	frr(i,n){
		cin>>x;
		freq[i]=x; 
		tot+=x;
		if(x!=0)
			matar.push(i); 
		else 
			morrer.push(i);
	}
	if(tot>n-1){
		cout<<"NO"<<endl; 
		return 0;
	}
	cout<<"YES"<<endl;
	while(matar.size()!=0){
		ll a,q; 
		a=matar.top(); 
		matar.pop(); 
		q=freq[a];
		while(q--){
			cout<<a<<' '<<morrer.top()<<endl; 
			morrer.pop();
		}
		morrer.push(a);
	}
}