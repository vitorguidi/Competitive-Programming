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

int v[5000];
ll memo[5000][5000];
int prox[5000];
map<ll,vi> oc;

int n; 

ll pd(int ind, int from){

	if(ind>n)	return 0;

	ll &pdm=memo[ind][from];
	if(pdm!=-1)	return pdm;
	
	pdm=0;

	if(from<ind)	pdm = max( pdm, 1 + pd( prox[from],ind) );
	pdm = max( pdm, pd( prox[ind],from) );

	return pdm;


}

int main(){
    
	fastio;

	cin >> n;

	frr(i,n){
		cin >> v[i];
		oc[v[i]].pb(i);
	}

	for(int i=1;i<=n;i++){
		auto it = upper_bound(all(oc[v[i]]),i);
		prox[i]= (it == oc[v[i]].end() ? 10000 : *it);
	}

	ll ans = 1;
	ms(memo,-1);

	for(int i=1;i<=n;i++)	
		for(int j=1;j<i;j++)
			ans=max<ll>(ans,1+pd(i,j));

	cout << ans << endl;

}