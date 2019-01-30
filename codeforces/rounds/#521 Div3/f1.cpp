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

ll v[220];
ll memo[220][440][220];

ll n,k,x;

ll pd(int ind, int last, int amt){

	if(amt<0 || ind-last>k)
		return -llINF;

	if(ind>n)
		return (!amt ? 0 : -llINF);

	ll &pdm=memo[ind][last][amt];
	if(pdm!=-1)	return pdm;

	pdm=-llINF;

	pdm = max<ll>(pdm , v[ind] + pd( ind+1 ,ind , amt-1) );

	pdm = max<ll>(pdm , pd( ind+1 , last , amt ) );

	return pdm;

}

int main(){
    
	fastio;

	cin >> n >> k >> x;

	frr(i,n)	cin >> v[i];

	ms(memo,-1ll);

	ll ans = pd(1,0,x);

	cout << (ans<0 ? -1 : ans) << endl;

}