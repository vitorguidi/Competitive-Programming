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

	int n,m,k;
	cin >> n >> m >> k;

	vector<ll> v;
	vector<pii> aux;

	ll ans = 0;

	frr(i,n){
		int x; cin >> x;
		aux.pb({x,i});
	}

	sort(all(aux));
	reverse(all(aux));

	vi inds;

	fr(i,k*m){
		inds.pb(aux[i].snd);
		ans+=aux[i].fst;
	}

	sort(all(inds));
	reverse(all(inds));


	vector<vi> parts;
	parts.resize(k);

	fr(i,k){

		while(parts[i].size()<m){
			parts[i].pb(inds[inds.size()-1]);
			inds.pop_back();
		}

		sort(all(parts[i]));

	}


	int ini=1;

	vii coisos;

	fr(i,k){
		int best = 0;
		for(auto x : parts[i])
			best=max(best,x);
		coisos.pb({ini,best});
		ini++;
	}

	cout << ans << endl;
	fr(i,k-1)	cout << coisos[i].snd << " ";
	gnl;

}