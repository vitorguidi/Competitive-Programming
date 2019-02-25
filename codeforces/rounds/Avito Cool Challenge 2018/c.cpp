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
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const ll MOD = 998244353;

ll n,m,k;
ll memo[2020][2020];

ll pd(ll ind,ll dif){

	if(ind<0)	return 0;
	if(ind==0)	return !dif;

	ll &pdm = memo[ind][dif];
	if(pdm!=-1)	return pdm;

	//opcao 1 -> pinta de mesma cor

	pdm=pd(ind-1,dif);
	pdm%=MOD;

	//opcao 2 -> pinta de outra cor (se houver e tiver algum anterior)

	pdm+=(m-1ll)*pd(ind-1,dif-1);
	pdm%=MOD;

	return pdm;

}

int main(){
    
	fastio;

	cin >> n >> m >> k;
	ms(memo,-1);
	ll ans = m*pd(n-1,k);
	ans%=MOD;
	cout << ans << endl;	

}