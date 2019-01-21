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

int memo[11234][130][6];
int n;
pii v[11234];

int pd (int ind,int t,int vs){
	if(ind == n) return 0;
	int& pdm = memo[ind][t][vs];
	if(pdm != -1) return pdm;

	pdm = v[ind].snd + pd(ind + 1,max(0,120 - v[ind].fst),5);

	if (t == 0 || vs == 0){
		return pdm;
	}
	if (vs == 5){
		int aux = v[ind].snd/2 + pd(ind + 1,max(0,t - v[ind].fst),4);
		pdm = min(pdm,aux);
	}
	else{
		int aux = v[ind].snd/4 + pd(ind + 1,max(0,t - v[ind].fst),vs-1);
		pdm = min(pdm,aux);
	}

	return pdm;

}

int main(){

	fastio;
	cout << setprecision(2) << fixed;
	
	
	cin >> n;
	fr(i,n){
		cin >> v[i].fst >> v[i].snd;
		v[i].snd *= 4;
	}
	ms(memo,-1);
	double ans = (v[0].snd + pd(1,max(0,120 - v[0].fst),5))/4;
	int ss = (v[0].snd + pd(1,max(0,120 - v[0].fst),5))%4;
	ans += ss*0.25;

	cout << ans<< endl;




}
