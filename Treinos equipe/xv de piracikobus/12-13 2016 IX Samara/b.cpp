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

int main(){
	fastio;
	int n; 
	vi f; 
	cin>>n; 
	frr(i,n){
		int x;
		cin>>x; 
		if( x== i)
			f.pb(x);
	}
	cout<<(f.size() + 1)/2<<endl; 

	if(f.size()%2){
		for(int i=1;i < f.size()-1 ; i+=2 )
			cout<<f[i]<<' '<<f[i-1]<<endl; 
	
		frr(i,n){
			if(f[f.size()-1] != i){
				cout<<f[f.size()-1]<<' '<<i<<endl;
				break;	
			}
		}
	}
	else{
		for(int i=1;i < f.size() ; i+=2 )
			cout<<f[i]<<' '<<f[i-1]<<endl; 
	}


}