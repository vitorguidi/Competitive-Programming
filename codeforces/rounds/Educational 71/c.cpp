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
const int MOD = 1e9+7;

ll memo[200200][3];
string s;
ll n,a,b;

//a = pipe b = pillar

ll pd(int ind, int hgt){

	if(ind==n+1){
		if(hgt==1)
			return 1e18;
		return 0;
	}

	ll &pdm=memo[ind][hgt];
	if(pdm!=-1)	return pdm;

	pdm = 1e18;

	if(s[ind-1]=='1' && hgt==0)
		return pdm;

	if(hgt==0){
		ll sobe = 2ll*a + b + pd(ind+1,1);
		ll mantem = a + b + pd(ind+1,0);
		if(s[ind-1]=='1'){
			mantem = 1e18;
		}
		pdm=min({sobe,mantem});
	}
	else{
		ll mantem = a + 2ll*b + pd(ind+1,1);
		ll desce = 2ll*a + 2ll*b + pd(ind+1,0);
		if(s[ind-1]=='1'){
			desce = 1e18;
		}

		pdm=min({desce,mantem});
	}

	return pdm;
}
 
void go(){
	
	cin >> n >> a >> b;
	cin >> s;

	s.pb(0);

	for(int i=0;i<s.size()+2;i++){
		fr(j,3)
			memo[i][j]=-1;
	}

	cout << b + pd(1,0) << endl;

}

int main(){
 
	fastio;
 
	int q; cin >> q;
	while(q--)	go();

}