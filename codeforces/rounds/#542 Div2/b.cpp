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

ll loja[100100][2];
ll memo[100100][5];
int n;


ll pd(int ind, int mask){

	if(ind==n)	return 0;

	ll& pdm = memo[ind][mask];
	if(pdm!=-1)	return pdm;

	int from1 = 1&mask;
	int from2 = 2&mask;
	if(from2)	from2=1;

	pdm=1e18;

	ll p1left = abs(loja[ind+1][0]-loja[ind][from1]);
	ll p1right = abs(loja[ind+1][1]-loja[ind][from1]);

	ll p2left = abs(loja[ind+1][0]-loja[ind][from2]);
	ll p2right = abs(loja[ind+1][1]-loja[ind][from2]);

	pdm=min(pdm,p1left + p2right + pd(ind+1,2));
	pdm=min(pdm,p1right + p2left + pd(ind+1,1));

	return pdm;


}

int main(){
    
	fastio;

	cin >> n;

	loja[0][0]=loja[0][1]=1;

	frr(i,2*n){
		int x; cin >> x;
		if(!loja[x][0])	loja[x][0]=i;
		else			loja[x][1]=i;
	}

	ms(memo,-1);

	cout << pd(0,0) << endl;


}