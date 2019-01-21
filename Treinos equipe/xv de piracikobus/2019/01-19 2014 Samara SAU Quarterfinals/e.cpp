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
int freq[3000];
int main(){
	fastio;
	string s;

	cin>>s;
	bool ok=1;
	fr(i,s.size())
		freq[s[i]-'a']++;

	sort(freq,freq+30);	
	
	if(s.size()%2){
		cout<<"NO"<<endl;
		return 0;
	}	
	if(freq[29]>(s.size()/2)){
		cout<<"NO"<<endl;
	}
	else
		cout<<"YES"<<endl;
}
