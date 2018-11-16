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

int v[200200];
map<int,int> freq;

int main(){
    
	fastio;

	ll acum = 0;

	int n; cin >> n;

	frr(i,n){
		cin >> v[i];
		freq[v[i]]++;
		acum+=v[i];
	}

	vi ans;

	frr(i,n){
		acum-=v[i];
		freq[v[i]]--;
	
		if(acum%2ll==0 && freq[acum/2ll]>0){
			acum;
			ans.pb(i);
		}
		freq[v[i]]++;
		acum+=v[i];
	}

	cout << ans.size() << endl;
	for(auto x : ans)
		cout << x << " ";
	gnl;

}

