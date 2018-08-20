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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int main(){
	fastio;
	ll n,l,v[11234]; 
	cin>>n>>l; 
	fr(i,n) 
		cin>>v[i]; 
	ll mini,maxi,k; 
	
	fr(i,n-l+1){
		mini=llINF;
		maxi=-mini;
		for(k=i;k<i+l;k++){
			maxi=max(maxi,v[k]); 
			mini=min(mini,v[k]);
		} 
		cout<<maxi-mini<<' ';
	}
	gnl;	
		return 0;
	}