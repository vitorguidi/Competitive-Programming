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

ll v[300300];
ll freq[10];
int main(){
    
	fastio;

	string s; cin >> s;

	int len = s.size();

	ll ans = 0;

	frr(i,len){
		v[i]=s[i-1]-'0';
		if(v[i]%4==0)
			ans++;
	}

	for(int i=1;i<=len-1;i++){
		if((10*v[i]+v[i+1])%4==0)
			ans+=i;
	}


	cout << ans << endl;

}
