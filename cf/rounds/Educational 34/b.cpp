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

int main(){
    
	fastio;

	int h1,a1,c1;
	int h2,a2;
	
	cin >> h1 >> a1 >> c1 >> h2 >> a2;

	vector<string> ans;

	while(h2>0){

		if(h2-a1>0 && h1-a2<=0){
			ans.pb("HEAL");
			h1+=c1;
		}
		else{
			ans.pb("STRIKE");
			h2-=a1;
		}

		if(h2<=0)	break;

		h1-=a2;

	}

	cout << ans.size() << endl;
	for(auto x : ans)
		cout << x << endl;

}

