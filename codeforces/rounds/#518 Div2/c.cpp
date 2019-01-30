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

int main(){
    
	fastio;

	int n,m; cin >> n >> m;
	vi nodes[1010];
	vii guys[1010];
	int pos=n+1;

	fr(i,m){
		int a,b;
		cin >> a >> b;
		nodes[a].pb(b);
	}

	frr(i,n){
		for(auto x : nodes[i]){
			guys[i].pb({i,pos});
			guys[x].pb({x,pos});
			pos++;	
		}
	}

	frr(i,n){
		cout << 1+guys[i].size() << endl;
		cout << i << " " << i << endl;
		for(auto x : guys[i])
			cout << x.fst << " " << x.snd << endl;
	}

}

