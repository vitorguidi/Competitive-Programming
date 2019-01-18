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

int mat[330][330];
map<int,int> m;
vi lin,col;
int l,c;

bool pos(){
	bool ok = true;
	fr(j,c){
		fr(i,l-1){
			if(abs(mat[i][j] - mat[i+1][j])%c != 0)
				ok = false;

		}
	}

	return ok;
}

int main(){

	fastio;
	
	cin >> l >> c;
	fr(i,l){
		fr(j,c){
			cin >> mat[i][j];
		}
	}

	if(!pos()){
		cout << '*' << endl;
		return 0;
	}

	frr(i,l){
		frr(j,c){
			m[(i-1)*c + j] = i;
		}
	}

	bool ok = true;

	lin.pb(0);
	col.pb(0);

	fr(i,l){
		int aux = m[mat[i][0]];
		lin.pb(aux);
		fr(j,c){
			if(m[mat[i][j]] != aux){
				ok = false;
			}
		}
		if(aux == 1){
			fr(j,c){
				col.pb(mat[i][j]);
			}
		}
	}

	if(!ok){
		cout << '*' << endl;
		return 0;
	}

	int id[330];
	int n = lin.size();

	frr(i,lin.size()){
		id[i] = lin[i];
	}

	//dbg(n);

	//olar;

	ll ans = 0;
	int vis[1123];
	ms(vis,0);
	frr(i,n-1){
		if(vis[i]) continue;
		vis[i] = 1;
		ll k = id[i];
		ll ct = 1;
		while(k != i){
			vis[k] = 1;
			k = id[k];
			ct++;
		}
		ans += ct - 1;
	}

	//olar;

	ll aux = 0;
	n = col.size();
	ms(vis,0);
	frr(i,col.size()){
		id[i] = col[i];
	}

	frr(i,n-1){
		if(vis[i]) continue;
		vis[i] = 1;
		ll k = id[i];
		ll ct = 1;
		while(k != i){
			vis[k] = 1;
			k = id[k];
			ct++;
		}
		ans += ct - 1;
	}
	
	cout << ans<< endl;


}
