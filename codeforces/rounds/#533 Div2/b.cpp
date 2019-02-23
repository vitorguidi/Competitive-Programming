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
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int ans[30];

int main(){
    
	fastio;

	int n,k; cin >> n >> k;

	vector<string> repo;
	string s; cin >> s;

	int len = s.size();

	for(int i=0;i<len;i++){

		char x = s[i];
		string aux; aux.pb(x);

		while(i+1<n && s[i+1]==s[i]){
			i++; aux.pb(x);
		}

		ans[x-'a']+=aux.size()/k;

	}	

	int cnt = 0;

	fr(i,26)	cnt=max(cnt,ans[i]);

	cout << cnt << endl;

}