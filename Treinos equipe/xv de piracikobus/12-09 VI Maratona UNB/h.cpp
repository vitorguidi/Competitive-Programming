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

int memo[1002][1002][51];
int n;
int pd(int x,int y,int ind){
	if (ind == n){
		if (x != X || y != Y) return (INF);
		else return (0);
	}

	int &pdm = memo[x][y][ind];
	if(pdm!=-1) return pdm;

	pdm = pd(x,y,ind + 1);
	bool ok =false;
	int x = 1 + pd(x + v[ind].fst,y + v[ind].snd,ind + 1);
	if(pdm > x){
		pdm = x;
		ok =true;
	}

	if(ok)
		path[x][y][ind] = mp(x + v[ind].fst,y + v[ind].snd);
	else
		path[x][y][ind]
	


}

int main(){

	fastio;
	
	cin >> n;
	int X,Y;
	cin >> X >> Y;

	int pii v[112];

	fr(i,n)
		cin >> v[i].fst >> v[i].snd;

	X += 500;
	Y += 500;

	ms(memo,-1);

	int x = pd(500,500,0);
}
