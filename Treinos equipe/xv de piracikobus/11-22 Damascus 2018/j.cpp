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
const int MOD = 1e9+7;

ll l1,r1,p1,d1,l2,r2,p2,d2,k;
ll anda1(int pos){
	if(pos==l1 && d1==0)
		d1=1;
	if(pos==r1 && d1==1)
		d1=0;

	if(d1==0)
		pos--; 
	else
		pos++; 
	return pos;
}

int anda2(int pos){
	if(pos==l2 && d2==0)
		d2=1;
	if(pos==r2 && d2==1)
		d2=0;

	if(d2==0)
		pos--; 
	else
		pos++; 

	return pos;
}

void solve(){
	cin>>l1>>r1>>p1>>d1; 
	cin>>l2>>r2>>p2>>d2; 
	cin>>k;
	ll ans=0;
	fr(i,k){
		p1=anda1(p1); 
		p2=anda2(p2);
		if(p1==p2)
			ans++; 
	}
	cout<<ans<<endl;
}

int main(){
	fastio; 
	int t; 
	cin>>t; 
	while(t--) solve();
}