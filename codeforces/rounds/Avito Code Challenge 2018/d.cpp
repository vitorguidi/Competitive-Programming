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

int memo[55][55][80];
int n,k;
ll v[55];
ll tmp;

int pd(int ind, int k, int bit){

	if(ind>n){
		if(k!=0)	return 0;
		return 1;
	}

	int& pdm = memo[ind][k][bit];
	if(pdm!=-1)	return pdm;

	pdm=0;

	for(int i=ind;i<=n;i++){

		ll val = (1ll<<bit) +tmp;
		ll cur = val&(v[i]-v[ind-1]); 
		ll lol = val&cur;

		if(lol!=val)	continue;
		pdm|=pd(i+1,k-1,bit);

	}

	return pdm;


}

int main(){
    
	fastio;

	ms(memo,-1);

	cin >> n >> k;
	frr(i,n){
		cin >> v[i];
		v[i]+=v[i-1];
	}

	for(int i = 60;i>=0;i--){
		ms(memo,-1);
		if(pd(1,k,i))	tmp|=(1ll<<i);
	}	

	cout << tmp << endl;

}