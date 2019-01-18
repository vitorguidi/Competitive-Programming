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

void solve(){
	ll n,m, cap[112345],move[112345],ans[112345];
	ms(cap,0); ms(move,0);ms(ans,0);
	cin>>n>>m;
	fr(i,n){
		cin>>cap[i];
	} 

	fr(i,m){
		ll x,y; 
		cin>>x>>y; 
		move[x-1]+=y;
	}

	ll sum=0;
	fr(i,n){
		sum+=move[i]; 
		if(sum>cap[i]){
			ans[i]=cap[i];
			sum-=cap[i];
		}
		else{
			ans[i]=sum;
			sum=0;
		} 
	}	
	
	cout<<sum<<endl; 
	fr(i,n){
		cout<<ans[i];
		if(i!=n-1)
			cout << " "; 
	}
	gnl;
}




int main(){

	fastio;
	int t; 
	cin>>t; 
	while(t--) solve();

}