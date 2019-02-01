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

set<int> s;
int n;

int prox(int ct){
	for(int i = ct + 1;i <= n;i++){
		if(s.find(i) == s.end()) return i;
	}

	return n;
}



int main(){

	fastio;
	
	cin >> n;
	int v[100100];
	fr(i,n){
		cin >> v[i];
		if(v[i] > n) v[i] = 1;
	}
	

	fr(i,n) s.insert(v[i]);

	set<int> freq;

	int ct = 0;
	ct = prox(0);

	int res[100100];
	fr(i,n){
		if(freq.find(v[i]) == freq.end()){
			res[i] = v[i];
			freq.insert(v[i]);
			s.insert(v[i]);
			continue;
		}

		res[i] = ct;
		freq.insert(ct);
		s.insert(ct);
		ct= prox(ct);
	}

	fr(i,n) cout << res[i] << ' ';
	gnl;

}