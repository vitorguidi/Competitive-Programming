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

int dice[6][6];
map<int,ll> cnt;
ll ans,x,n;

ll fastxp(ll x, ll exp){

	ll ans = 1;
	while(exp>0){
		if(exp%2)
			ans=(ans*x)%mod;
		x=(x*x)%mod;
		exp=exp/2;
	}

	return ans;

}

void solve_left(int ind, ll state){
	
	if(ind==n/2){
		fr(i,6)
			cnt[(state*dice[ind][i])%mod]++;
		return;
	}

	fr(i,6)
		solve_left( ind+1, (state*dice[ind][i])%mod );
	
}
		
void solve_right(int ind, ll state){

	if(ind==n/2){
		ll desired = x*fastxp(state,mod-2);
		desired=desired%mod;
		if(desired<0)
			desired+=mod;
		ans+=cnt[desired];
		return;
	}

	fr(i,6)
		solve_right(ind-1, (state*dice[ind][i])%mod );

}

int main(){

	int t; cin >> t;
	
	while(t--){
		
		cin >> n >> x;

		cnt.clear();
		ans=0;
		fr(i,n)
			fr(j,6)
				cin >> dice[i][j];
		
		solve_left(0,1);
		solve_right(n-1,1);

		cout << ans << endl;	
		
	}

}