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
int v[200002];
int prox[200002];
int memo[200002];
int n;

int pd(int k){
	if(k>=n) return INF;
	if(k == n -1) return (0);
	int& pdm = memo[k];
	if(pdm!= -1) return pdm;
	pdm = INF;

	if(prox[k] != -1)
		pdm = 1 + pd(prox[k]);
	int x = 1 + pd(k+1);

	if(pdm > x)
		pdm = x;

	return (pdm);
}

int main(){
	fastio;
	
	cin >> n;
	
	fr(i,n){
		cin >> v[i];
	}

	int vi[200002];
	ms(vi,-1);
	ms(prox,-1);
	ms(memo,-1);

	for(int i = n-1;i>=0;i--){
		if(vi[v[i]] != -1) prox[i] = vi[v[i]];
		vi[v[i]] = i;
	}

	//fr(i,n)
	//	cout << prox[i] << endl;

	cout << pd(0)<<endl;

}
