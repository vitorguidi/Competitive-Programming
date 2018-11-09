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

int memo[10010][911][3];
int n;
vii v;
vi ss;

int pd(int id,int s,int falta){

	if(s<0) return(-INF);
	if(id==n)
		return (s < 210 ? -INF : 0);

	int &pdm = memo[id][s][falta];

	if(pdm != -1) return(pdm);

	pii at = v[id];

	pdm = pd(id + 1,s,falta);

	int pega = at.fst + pd(id+1,s-at.snd,falta);

	pdm = max( pdm , pega );

	if(falta != 0)
		pdm = max(pdm,at.fst+ pd(id + 1, s + ss[id] - at.snd,falta - 1));


	return(pdm);

}

int main(){

	fastio;
	
	int s;
	cin >> n >>s;
	
	
	
	fr(i,n){
		int p,w,d;
		cin >> p >> w >> d;
		v.pb(mp(p,w));
		ss.pb(d);	
	}


	ms(memo,-1);

	cout << max(0,pd(0,s + 210,2))<<endl;



}
