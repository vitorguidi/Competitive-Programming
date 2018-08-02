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

#define gnl cout << endl
#define olar cout << "olar" << endl
#define gottagofast ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int main(){

	vi ans;
	int n,v[1010];
	cin >> n;

	frr(i,n)
		cin >> v[i];

	v[0]=0;

	int cnt=0,sum=0;
	int ini=0;

	while(ini<=n){

		if(v[ini]==1)
			cnt++;
		
		if(ini!=0 && ini+1<=n && v[ini+1]==1)
			ans.pb(v[ini]);
		
		if(ini==n)
			ans.pb(v[ini]);
		
		ini++;
	}
    
    cout << cnt << endl;
    fr(i,ans.size())
    	cout << ans[i] << " ";
    gnl;

}

