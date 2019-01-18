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
	int T;
	cin >> T;
	string s1,s2; 
	getline(cin,s1); 
	while(T--){
		getline(cin,s1); 
		getline(cin,s2);
		int freq[30],freq2[30]; 
		ms(freq,0);
		ms(freq2,0);
		fr(i,s1.size())
			freq[s1[i]-'a']++;
		fr(i,s2.size())
			freq2[s2[i]-'a']++;
		int sum=0; 
		fr(i,30){
			sum+=abs(freq[i]-freq2[i]);
		}
		cout<<sum<<endl;

	}

}