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

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;
const int mod = 1e9+7;

ll memo[200];

ll fastxp(ll base, ll exp){

	ll ans = 1;

	while(exp){

		if(exp%2){
			ans=ans*base;
			ans=ans%mod;
		}

		base=base*base;
		base=base%mod;
		exp=exp/2;
	
	}

	return ans;
}

ll fat(ll x){
	if(x==0)	return 1;
	return x*(fat(x-1))%mod;
}


ll pd(int amt){


	if(amt<0)	return 0;
	if(amt==0)	return 1;

	ll &pdm=memo[amt];
	if(pdm!=-1)	return pdm;

	ll ans=0;
	frr(i,amt){
		ll n = fat(amt);
		ll k = fat(i);
		k=fastxp(k,mod-2);
		ll nk = fat(amt-i);
		nk = fastxp(nk,mod-2);
		ll coef;
		coef = (n*k)%mod;
		coef = (coef*nk)%mod;
		ans+=coef*pd(amt-i);
		ans=ans%mod;
	}

	return pdm=ans;


}

int main(){

	int n;
	string s1,s2;
	
	cin >> n;
	getline(cin,s1);
	getline(cin,s1);
	getline(cin,s2);
	
	int atual=0,desired=0;

	fr(i,s1.size()){
		if(s1[i]!='.')
			atual++;
	}
	fr(i,s2.size()){
		if(s2[i]!='.')
			desired++;
	}

	ms(memo,-1);

	int delta = atual-desired;

	if(delta==0)
		cout << 0 << endl;
	else
		cout << pd(delta) << endl;

}