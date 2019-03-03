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

vii cands,obs,deltas;

bool check(pii cara){

	map<pii,int> cnt;

	for(auto x : deltas)	cnt[x]++;

	for(auto x : obs){
		pii aux = {cara.fst-x.fst,cara.snd-x.snd};
		if(!cnt[aux])	return false;
		cnt[aux]--;
	}

	return true;

}

int main(){
    
	fastio;

	int n; cin >> n;

	fr(i,n){
		int x,y;
		cin >> x >> y;
		obs.pb({x,y});
	}

	fr(i,n){
		int x,y;
		cin >> x >> y;
		deltas.pb({x,y});
	}

	for(auto x : deltas){
		pii cara = obs[0];
		cands.pb({cara.fst+x.fst,cara.snd+x.snd});
	}

	for(auto x : cands){
		if(check(x)){
			cout << x.fst << " " << x.snd << endl;
			return 0;
		}
	}

}