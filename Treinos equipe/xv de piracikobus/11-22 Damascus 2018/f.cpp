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
const int MOD = 7901;

ll fat[1123],n,freq[1123],t; 



int main(){
	fastio;
	fat[0]=1;
	frr(i,1000)
		fat[i]=(fat[i-1]*i)%MOD; 
	cin>>t; 
	while(t--){
		ms(freq,0);
		ll ans=1; 
		cin>>n;
		ll x; 
		fr(i,n){
			cin>>x; 
			freq[x]++;
		}
		fr(i,1001){
			ans=(ans*fat[freq[i]])%MOD;
		}
		cout<<ans<<endl;	
	}	

}