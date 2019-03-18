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

int cost[110];
int value[110];
int expire[110];
vii caras;
int who[110];
int take[110][2200];
int n;
int memo[110][2200];

bool comp(int a, int b){
	return expire[a]<expire[b];
}

int pd(int ind, int clk){

	if(ind==n)	return 0;

	int& pdm = memo[ind][clk];
	if(pdm!=-1)	return pdm;

	int eu = who[ind];

	pdm=-INF;
	int pega = -INF;

	int finish = clk + cost[eu] - 1;


	if(finish<expire[eu])
		pega = value[eu] + pd(ind+1,clk+cost[eu]);

	int passa = pd(ind+1,clk);

	if(pega>passa){
		take[ind][clk]=1;
		return pdm=pega;
	}

	return pdm=passa;

}

int main(){
    
	fastio;

	cin >> n;

	fr(i,n){
		cin >> cost[i] >> expire[i] >> value[i];
		caras.pb({expire[i],i} );
	}

	sort(all(caras));
	fr(i,n)	who[i]=caras[i].snd;

	ms(memo,-1);

	cout << pd(0,1) << endl;

	int clk = 1;

	vi ans;

	fr(i,n){
		int eu = who[i];
		if(take[i][clk]){
			ans.pb(who[i]);
			clk+=cost[who[i]];
		}
	}

	cout << ans.size() << endl;
	for(auto x : ans)	cout << x+1 << " ";
	gnl;


}