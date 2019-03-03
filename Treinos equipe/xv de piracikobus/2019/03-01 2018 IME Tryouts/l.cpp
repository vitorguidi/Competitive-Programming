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

int n,l;
int memo[100100];
map<pii,int> who;
map<int,pii> coord;

bool check(pii a, pii b){
	return abs(a.fst-b.fst)+abs(a.snd-b.snd) <=5;
}

int pd(int ind){

	if(ind==n+2)	return -1;

	int& pdm = memo[ind];
	if(pdm!=-1)	return pdm;

	int nf = 0;

	int x = coord[ind].fst;
	int y = coord[ind].snd;
 
	pdm=-INF;

	frr(i,5){
		for(int j=-5;j<=5;j++){

			int xf = x+i;
			int yf = y+j;

			if(!check({xf,yf},{x,y}))	continue;
			if(who[{xf,yf}]==0)			continue;


			nf++;
			pdm=max(pdm,1+pd(who[{xf,yf}]) );

		}
	}

	if(!nf)	return pdm= -INF;


	return pdm;


}

int main(){

	fastio;
	cin >> n >> l;

	frr(i,n){
		int x,y;
		cin >> x >> y;
		who[{x,y}]=i;
		coord[i]={x,y};
	}	

	who[{l,0}]=n+2;
	coord[n+2]={l,0};

	who[{0,0}]=n+1;
	coord[n+1]={0,0};

	ms(memo,-1);

	cout << pd(n+1) << endl;


}