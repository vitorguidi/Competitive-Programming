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

int n,memo[220][220];
vector<pair<double,double>> v;

int pd(int id, int last){

	if(id>n)	return 0;

	int &pdm=memo[id][last];
	if(pdm!=-1)	return pdm;

	pdm=0;

	pair<double,double> now = v[id];
	pair<double,double> prev = v[last];

	if(now.fst>prev.fst && now.snd<prev.snd)
		pdm=1+pd(id+1,id);

	pdm = max(pdm,pd(id+1,last));

	return pdm;

}

void solve(){

	cin >> n;
	
	v.clear();

	v.pb({-1.0,11.0});

	fr(i,n){
		double a,b;
		cin >> a >> b;
		v.pb({a,b});
	}
	
	ms(memo,-1);

	cout << pd(1,0) << endl;

}

int main(){

	fastio;

	int t; cin>>t;
	while(t--)	solve();

}