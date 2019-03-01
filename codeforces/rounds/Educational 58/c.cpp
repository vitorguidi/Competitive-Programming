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


bool inter(pii a, pii b){
	return (a.fst<=b.fst && b.fst<=a.snd) || (a.fst<=b.snd && b.snd<=a.snd);
}

void solve(){

	int n; cin >> n;

	vector< pair<pii,int> > v;

	fr(i,n){
		int x,y;
		cin >> x >> y;
		v.pb( mp( mp(x,y),i ) );
	}

	sort(all(v));

	vi vis(n+2);
	vi ind;
	vii segs;

	for(auto x : v){
		ind.pb(x.snd);
		segs.pb(x.fst);
	}

	int ini=1;
	vis[ind[0]]=1;

	pii lol = segs[0];

	while(ini<n){

		if(!inter(lol,segs[ini]))	break;

		lol.snd=max(lol.snd,segs[ini].snd);
		vis[ind[ini]]=1;

		ini++;

	}

	if(ini==n){
		cout << -1 << endl;
		return;
	}

	fr(i,n)	cout << (vis[i]==1 ? 1 : 2) << " ";
	gnl;

}

int main(){
   	fastio;
	int t;
	cin >> t;
	while(t--)	solve();
}