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
	int n,m;
	pii v[112345];

	cin >> n >> m;

	fr(i,n){
		int a;
		cin >> a;
		v[i] = mp(a,i);
	}

	sort(v,v + n);
	int ind1,ind2;
	fr(i,n){
		if (v[i].fst == m){
			ind1 = i;
			break;
		}
	}
	for(int i = n-1;i>=0;i--){
		if (v[i].fst == m){
			ind2 = i;
			break;
		}
	}
	int ind;
	if (ind1 <= n/2 && ind2 >= n/2)
		ind = n/2;
	else if (ind2 < n/2)
		ind = ind2;
	else
		ind = ind1;

	vi ans;

	while(ind != n/2){
		while(ind < n/2){
			ans.pb(v[n-1].snd);
			n--;
		}

		int j = 0;
		while(ind > n/2){
			ans.pb(v[j].snd);
			j++;
			ind--;
			n--;
		}
	}

	cout << ans.size()<<endl;
	fr(i,ans.size())
		cout << ans[i] + 1 <<' ';
	gnl;

}
