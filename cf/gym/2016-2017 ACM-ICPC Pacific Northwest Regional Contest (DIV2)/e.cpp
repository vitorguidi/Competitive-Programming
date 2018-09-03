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
#define pira cout << "pira" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int main(){
    
	int n,k;
	cin >> n >> k;

	ll time = 0;
	ll ans = 0;

	set<int> aux;

	fr(i,k){
		int x; cin >> x;
		aux.insert(x);
	}

	n-=k;

	while(!aux.empty()){

		auto it = aux.begin();
		int lol = *it;
		time+=lol;
		ans+=time;
		aux.erase(aux.begin());
		
		if(n){
			int x; cin >> x;
			aux.insert(x);
			n--;
		}

	}
	

	cout << ans << endl;

}
