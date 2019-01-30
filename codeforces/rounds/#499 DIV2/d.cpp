#include "bits/stdc++.h"
using namespace std;
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)
#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;
typedef vector< vector<ll> > matrix;
const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;
const ll mod = 1e9+7;

int seq[60];

int main(){

	int m,n; cin >> m >> n;
	
	fr(i,n){
		int ans;
		cout << 1 << endl;
		fflush(stdout);
		cin >> ans;
		if(ans==0)
			return 0;
		else if(ans==-1)
			seq[i]=0;
		else if(ans==1)
			seq[i]=1;
	}
	
	int ini=1;
	int end=m;

	fr(i,60-n){
		int mid = (ini+end)/2;
		cout << mid << endl;
		int ans;
		fflush(stdout);
		int pos = i%n;
		cin >> ans;
		if(seq[pos]==0)
			ans=-1*ans;
		if(ans==-1)
			end=mid-1;
		else if(ans==1)
			ini=mid+1;
		else
			return 0;
	}
}