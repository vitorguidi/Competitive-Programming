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

int main(){

	fastio;
	int n;
	cin >> n;
	ll v[222345];

	map<ll,ll> m;

	frr(i,n)
		cin >> v[i];

	ll acum[222345];
	acum[1]= v[1];

	for(int i=2;i<=n;i++){
		acum[i] = v[i] + acum[i-1];
	}

	pll best = {0,n+1};

	frr(i,n){
		if(acum[i] == 0){
			best = {1,i};
			break;
		}
	}

	

	frr(i,n){
		if (m[acum[i]] == 0){
			m[acum[i]] = i;
		}
		else{
			pll at;
			at = mp(m[acum[i]] + 1,i - m[acum[i]]);
			if (at.snd < best.snd){
				best = at;
			}
			m[acum[i]] = i;
		}
	}
	if(best.snd <= n)
		cout << best.fst<<' '<<best.snd<<endl;
	else
		cout << -1 << endl;

}
