#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;

ll m,n,v[22][22];
map<ll,ll> check[22][22];
ll ans,k;

int mid;

bool ingrid(int x, int y){

	if(x<0 || x>=n)
		return false;
	if(y<0 || y>=m)
		return false;
	return true;

}

void left(int x, int y, ll mask, int cnt){

	if(!ingrid(x,y))
		return;

	mask = mask ^ v[x][y];
		
	if(cnt==mid){
		check[x][y][mask]++;
		return;
	}

	left(x+1,y,mask,cnt+1);
	left(x,y+1,mask,cnt+1);

}

void right(int x, int y, ll mask, int cnt){

	if(!ingrid(x,y))
		return;

	if(cnt == m + n - 2 - mid){
		ans+=check[x][y][mask^k];
		return;
	}

	right(x-1,y,mask^v[x][y],cnt+1);
	right(x,y-1,mask^v[x][y],cnt+1); 

}

int main(){

	cin >> n >> m >> k;

	mid=(m+n-2)/2;

	fr(i,n)
		fr(j,m)
			cin >> v[i][j];


	left(0,0,0ll,0);
	right(n-1,m-1,0ll,0);

	cout << ans << endl;

}