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
typedef vector<ll> vl;
typedef vector<pll> vll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

int n,f;

bool check(vector<long double>& pies, long double mid){

	int ans =0;

	for(auto x : pies)
		ans+=(int)floor(x/mid);
	

	if(ans>=f+1)
		return true;
	return false;

}

void solve(){

	scanf("%d%d",&n,&f);

	vector<long double> pies;

	fr(i,n){
		long double val;
		scanf("%LF",&val);
		val=val*val*acos(-1);
		pies.pb(val);
	}

	long double ini=0;
	long double end=1e18;

	long double ans = 0;

	fr(i,100){

		long double mid = (ini+end)/2.0;

		if(check(pies,mid)){
			ans=max(ans,mid);
			ini=mid;
		}
		else
			end=mid;

	}

	printf("%.15LF\n",ans);

}

int main(){

	int t;
	scanf("%d",&t);
	while(t--)	solve();

}