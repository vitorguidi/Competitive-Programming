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
const int MOD = 998244353;

ll memo[1010][2020][4];
ll n,k;
map<pii,int> wgt;

ll pd(int ind, int comp, int mask){
	
	if(comp>k)	return 0;

	if(ind==n)
		return comp==k;

	if(ind==0){
		ll ans=0;
		ans+=pd(1,1,0);	//ww
		ans+=pd(1,2,1);	//wb
		ans+=pd(1,2,2); //bw
		ans+=pd(1,1,3); //bb
		ans%=MOD;
		return ans;
	}


	ll &pdm = memo[ind][comp][mask];
	if(pdm!=-1)	return pdm;


	pdm=0;

	fr(i,4){
		int amt = wgt[{mask,i}];	//adiciona numero appropriado de comp conexas
		pdm+=pd(ind+1,comp+amt,i);
		pdm%=MOD;
	}
	
	return pdm;

}

int main(){

	fastio;

	cin >> n >> k;

	wgt[{0,0}]=0;
	wgt[{0,1}]=1;
	wgt[{0,2}]=1;
	wgt[{0,3}]=1;

	wgt[{1,0}]=0;
	wgt[{1,1}]=0;
	wgt[{1,2}]=2;
	wgt[{1,3}]=0;

	wgt[{2,0}]=0;
	wgt[{2,1}]=2;
	wgt[{2,2}]=0;
	wgt[{2,3}]=0;

	wgt[{3,0}]=1;
	wgt[{3,1}]=1;
	wgt[{3,2}]=1;
	wgt[{3,3}]=0;

	ms(memo,-1);
	ll ans = pd(0,0,0);

	cout << ans << endl;
	
}