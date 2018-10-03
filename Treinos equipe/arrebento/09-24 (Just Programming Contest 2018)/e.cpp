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
const int mod = 1e9+7;

int grid[20][20];
int memo[1<<17][20];
int n; 
int dx[2]={1,-1};
map<int,int> id;
vi nodes[1<<16];

bool valid(int x){
	return x>=0 && x<n;
}

bool check(int mask){
	
	fr(i,n-1)		//horizontal cara cima
		if( ( (1<<i)&mask ) && ( ( 1<<(i+1) )&mask) )
			return false;

	return true;

}

bool compatible(int x, int y){


	fr(i,n)			//vertical
		if( ( (1<<i)&x ) && ( (1<<i)&y ) )
			return false;

	fr(i,n)	
		fr(j,2)
			if( valid(i+dx[j]) && ( (1<<i)&x ) && ( ( 1<<(i+dx[j]) )&y )  )
				return false;
		
	return true;

}

int getsum(int mask, int ind){
	
	int ans = 0;
	
	fr(i,n)
		ans+= ( grid[ind][i] ) *( ( (1<<i)&mask )!=0 );
	
	return ans;

}

int pd(int mask, int ind){

	if(ind==n)	return 0;

	int &pdm=memo[mask][ind];
	if(pdm!=-1)	return pdm;

	pdm=0;
	for(auto x : nodes[mask])
		pdm=max(pdm,getsum(x,ind)+pd(x,ind+1));
	return pdm;

}

void solve(){

	cin >> n;
	
	fr(i,n)
		fr(j,n)
			cin >> grid[i][j];

	ms(memo,-1);
	cout << pd(0,0) << endl;

}

int main(){
	
	fastio;

	id[0]=0;
	int cnt=1;
	vi masks;

	n=16;

	fr(i,1<<16){
		if(!check(i))
			continue;
		masks.pb(i);
	}

	for(auto x : masks)
		for(auto y : masks)
			if(compatible(x,y))
				nodes[x].pb(y);

	int t; 
	cin >> t;
	while(t--)	solve();

}