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

ll memo[300300][3][3];
ll v[300300];
ll n,x;

ll pd(int ind, int pegou, int fase){

	if(ind>n)	return 0;

	ll& pdm = memo[ind][pegou][fase];
	if(pdm!=-1)	return pdm;

	pdm=0;

	if(!pegou){
		pdm=max(pdm,pd(ind+1,1,0))+v[ind];
		pdm=max(pdm,pd(ind+1,1,1)+x*v[ind]);
		pdm=max(pdm,pd(ind+1,0,0));
	}

	if(pegou){
		pdm=max(pdm, pd(ind+1,1,fase) + v[ind]* ( fase==1 ? x : 1 ) );
		if(fase==0)	pdm=max(pdm, pd(ind+1,1,1) + v[ind]* x);
	}

	if(fase==1){
		pdm=max(pdm, pd(ind+1,1,2) + v[ind] );
	}

	return pdm;

}

int main(){

	fastio;

	cin >> n >> x;

	frr(i,n)	cin >> v[i];
	
	ms(memo,-1);
	cout << max(pd(1,0,0),0ll) << endl;

}