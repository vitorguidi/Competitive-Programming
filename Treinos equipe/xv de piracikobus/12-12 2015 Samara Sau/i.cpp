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

ll memo[1123][1123];
ll t[1123]; 		
ll n,d,c;


ll pd(ll q,ll ind){
	if(ind == n - 1) return (d);

	ll &pdm = memo[q][ind];
	if(pdm != -1) return pdm;

	pdm = (q+1)*(t[ind + 1] - t[ind])*c + pd(q+1,ind+1);

	ll aux;
	aux = d + pd(0,ind + 1);

	if(aux<pdm) pdm = aux;

	return (pdm);



}

int main(){

	fastio;
	cin >> n >> d >> c;
	

	fr(i,n) cin >> t[i];

	ms(memo,-1);
	cout << pd(0,0)<< endl;

}
