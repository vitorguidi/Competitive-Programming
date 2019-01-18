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
	int v[1123456];
	int p[58];

	cin >> n >> m;

	fr(i,n)
		cin >> v[i];

	int sum = 0;

	fr(i,m){
		cin >> p[i];
		sum += p[i];
	}

	int mx = v[n-1];

	vi ans;

	fr(i,n){
		int ano = v[i] + 50;
		int q = i;
		int ct = 0;

		int alvo = v[i] + p[ct];

		while(q < n && v[q] <= ano){
			if(v[q] == alvo){
				ct++;
				if(ct == m) break;
				alvo +=p[ct];
			}
			q++;
		} 

		if(ct == m) ans.pb(v[i]);
	}

	cout << ans.size() << endl;
	fr(i,ans.size()){
		cout << ans[i] <<' ';
	}
	gnl;

}
