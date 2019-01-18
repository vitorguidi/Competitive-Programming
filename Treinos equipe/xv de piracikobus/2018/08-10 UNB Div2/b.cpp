#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

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
const int MAXN = 100100;  
const int mod = 1e9+7;

ll freq[27],freq2[27];

int main(){
	fastio; 
	int n,m,p,i; 
	cin>>n>>m; 
	string l;
	getline(cin,l); 
	
	while(n--){ 
		getline(cin,l); 
		for(i=0;i<m;i++) 
			freq[l[i]-'a']++; 
	}	
	
	cin>>p; 
		getline(cin,l); 
	while(p--){ 
		getline(cin,l); 
		fr(i,27) 
			freq2[i]=freq[i];
		ll val=1; 
		for(i=0;i<l.size();i++){
			val*=freq2[l[i]-'a']; 
			val=val%mod; 
			freq2[l[i]-'a']--;
		} 
		cout<<val<<endl;
	}

	return 0;
}