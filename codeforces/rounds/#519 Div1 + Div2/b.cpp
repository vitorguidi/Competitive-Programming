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

int a[1010];
int v[1010];
int lol[1010];
int n;

bool check(int x){

	for(int i=x+1;i<=n;i++)
		if(v[i]!=v[i-x])
			return false;

	return true;

}

int main(){
    
	fastio;

	cin >> n;
	
	for(int i=1;i<=n;i++){
		cin >> a[i];
		v[i]=a[i]-a[i-1];
	}

	vi ans;
	for(int i=1;i<=n;i++)
		if(check(i))
			ans.pb(i);

	cout << ans.size() << endl;
	for(auto x : ans)
		cout << x << " ";
	gnl;


}

