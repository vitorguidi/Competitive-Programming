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
#define olar cout << "pira" << endl
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll; 

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int bulbs[1010];
int n,m,l;
vi grid[1010];

bool check(){
	fr(i,m)
		if(bulbs[i]%2)
			return false;
	return true;
}

int main(){

	cin >> n >> m >> l;

	fr(i,l){
		int x; cin >> x;
		x--;
		bulbs[x]=1;
	}


	fr(i,n){
		int k; cin >> k;
		fr(j,k){
			int x; cin >> x;
			x--;
			grid[i].pb(x);
		}
	}

	int cnt=0;

	fr(i,2*n){
		if(check())
			break;
		for(auto x : grid[i%n])
			bulbs[x]++;
		cnt++;
	}

	if(!check())
		puts("-1");
	else
		cout << cnt << endl;


}