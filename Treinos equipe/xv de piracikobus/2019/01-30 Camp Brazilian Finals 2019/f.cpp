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

pll memo[1010][1010];
map<string,ll> ma;
ll v[1010];
ll t[1010];
ll idv[1010];
ll idt[1010];
int n,m;

pll comp(pll a,pll b){
	if(a.fst > b.fst) return a;
	if(b.fst > a.fst) return b;
	if(b.snd < a.snd) return b;
	return a;
}

pll pd(int i,int j){
	if( i== n || j == m) return {0,0};
	pll &pdm = memo[i][j];
	if(pdm.snd != -1) return pdm;

	pdm = pd(i+1,j);
	pdm = comp(pdm,pd(i,j+1));

	if(idv[i] == idt[j]){
		pll aux = pd(i+1,j+1);
		aux.fst += v[i] + t[j];
		aux.snd++;
		pdm = comp(pdm,aux);
	}

	return pdm;
}


void solve(){
	ma.clear();
	cin >> n;
	string s;
	int ct = 1;
	fr(i,n){
		cin >> s;
		cin >> s;
		if(ma[s] == 0){
			ma[s] = ct++;
		}
		idv[i] = ma[s];
		cin >> v[i];
	}
	cin >> m;
	fr(i,m){
		cin >> s;
		cin >> s;
		if(ma[s] == 0) ma[s] = ct++;
		idt[i] = ma[s];
		cin >> t[i];
	}

	fr(i,n+1){
		fr(j,m+1){
			memo[i][j] = {-1,-1};
		}
	}

	pll a = pd(0,0);

	cout << a.fst << ' ' << a.snd << endl;


}

int main(){

	fastio;
	int T;
	cin >> T;

	while(T--){
		solve();
	}

}
