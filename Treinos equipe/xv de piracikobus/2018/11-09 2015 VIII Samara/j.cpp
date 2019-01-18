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
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

int main(){

	fastio;
	int n,m,k;
	cin >> n >> m >>k;

	int v[112345],t[112345];

	fr(i,n){
		cin >> v[i];
	}

	fr(i,m)
		cin >> t[i];

	int ct,q;
	ct = 0;
	q = 0;

	vi ans;

	fr(i,n){
		
		if(v[i] == t[q]){
			ct++;
			q++;
			if(ct == k){
				ans.pb(k);
				ct = 0; 
			}
		}
		else{
			if(ct!=0)
				ans.pb(ct);
			ct = 0;
			q++;
			i--;
		}
	}

	if (ct!=0)
		ans.pb(ct);
	int g = 1;

	cout << ans.size() << endl;

	fr(i,ans.size()){
		cout << ans[i]<<' ';
		fr(j,ans[i]){
			cout << g <<' ';
			g++;
		}
		gnl;


	}

}
