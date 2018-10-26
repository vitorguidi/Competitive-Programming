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

vector< pair<pii,int> > v;
int n;
int prox[200200];
pll memo[200200];
int path[200200];
int volta[200200];

pll better(pll a, pll b){

	if(a.fst>b.fst)
		return a;

	if(a.fst==b.fst){
		if(a.snd<=b.snd)
			return a;
	}

	return b;

}

pll pd(int ind){

	if(ind==n)
		return mp(0ll,0ll);

	pll &pdm = memo[ind];
	if(pdm!=mp(-1ll,-1ll))
		return pdm;

	pll pega = pd(prox[ind]);
	pll pula = pd(ind+1);

	int dt = v[ind].fst.snd - v[ind].fst.fst;
	pega.snd+=dt;
	pega.fst+=v[ind].snd;

	if(better(pega,pula)==pega)
		path[ind] = prox[ind];
	else
		path[ind] = -0;

	return pdm = better(pega,pula);

}

int main(){

	fastio;

	cin >> n;

	vector< pair<pii,pii> > v2;

	fr(i,n){
	
		int a,b,c;
		cin >> a >> b >> c;
		
		pair<pii,pii> aux;
		
		aux.fst.fst=a;
		aux.fst.snd=b;
		aux.snd.fst=c;
		aux.snd.snd=i;
	
		v2.pb(aux);

	}

	sort(all(v2));

	fr(i,n){
		volta[i]=v2[i].snd.snd;
		v.pb(mp( mp(v2[i].fst.fst,v2[i].fst.snd),v2[i].snd.fst ));
	}

	for(int i=0;i<n;i++){

		auto it = lower_bound( all(v), mp( mp(v[i].fst.snd,0),0 )  );
		prox[i] = it - v.begin();

	}


	fr(i,n)
		memo[i]={-1,-1};

	pll ans = pd(0);
	vi out;

	int cnt=0;
	int ini=0;

	while(ini<n && !path[ini])
		ini++;

	if(ini<n){
		out.pb(volta[ini]);
		cnt++;
	}

	while(ini<n){

		ini=prox[ini];
		
		if(ini==n)	break;

		while(!path[ini] && ini<n)
			ini++;

		if(ini<n){
			cnt++;
			out.pb(volta[ini]);
		}

	}

	cout << cnt << " " << ans.fst << " " << ans.snd << endl;
	for(auto x : out)
		cout << x+1 << " ";
	gnl;
 
}
