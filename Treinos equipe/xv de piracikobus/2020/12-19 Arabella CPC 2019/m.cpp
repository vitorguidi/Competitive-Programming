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

int main(){

	fastio;

	string s; cin >> s;
	map<char,int> freq;
	for(char c : s)	freq[c]++;
	for(char c = 'a';c<='y';c++) {
		freq[c+1]+=freq[c]/2;
		freq[c]-= 2*(freq[c]/2);
	}

	string ans;
	for(char c = 'z';c>='a';c--) {
		for(int j=0;j<freq[c];j++)	ans+=c;
	}

	cout << ans << endl;

	return 0;

}
