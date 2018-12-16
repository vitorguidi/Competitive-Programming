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

int v[300300];

int main(){
    
	fastio;

	map<int,int> freq;

	int n;
	scanf("%d",&n);

	frr(i,n)	scanf("%d",&v[i]);

	int ini=1;
	vii ans;

	bool flag = false;

	frr(i,n){
		freq[v[i]]++;
		if(freq[v[i]]==2){
			flag=true;
			ans.pb({ini,i});
			ini=i+1;
			freq.clear();
		}
	}

	if(!flag){
		cout << -1 << endl;
		return 0;
	}

	if(ini!=n+1){
		pii last = ans[ans.size()-1];
		ans.pop_back();
		last.snd=n;
		ans.pb(last);
	}

	cout << ans.size() << endl;
	for(auto x : ans)
		cout << x.fst << " " << x.snd << endl;


}

