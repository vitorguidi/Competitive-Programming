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

ll memo[31][31][55];

ll pd(int lin, int col, int k){
	if(lin*col==k)	return 0;
	if(lin*col<k)	return llINF;
	if(!k || !lin || !col)	return 0;

	ll &pdm = memo[lin][col][k];
	if(pdm!=-1)	return pdm;


	ll ans = llINF;

	int area = min<ll>(k,lin*col);

	frr(i,lin-1)
		fr(j,area+1)
			ans=min<ll>( ans , col*col + pd(lin-i,col,j) + pd(i,col,k-j) );


	frr(i,col-1)
		fr(j,area+1)
			ans = min<ll>(ans, lin*lin + pd(lin,i,j) + pd(lin,col-i,k-j) );


	return pdm=ans;

}

void solve(){

	int n,m,k;
	cin >> n >> m >> k;
	cout << pd(n,m,k) << endl;

}

int main(){

	fastio;

	int t; cin >> t;
	ms(memo,-1);
	while(t--)
		solve();

}