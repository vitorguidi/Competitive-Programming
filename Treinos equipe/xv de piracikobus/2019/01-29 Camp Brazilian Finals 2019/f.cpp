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
int id[50500],sz[50500],peso[50500];
int n,k;

void init(){
	frr(i,n){
		id[i] = i;
		sz[i] = 1;
		peso[i] = 0;
	}
}

int find(int a){
	if(a == id[a]) return a;
	else return find(id[a]);
}

int rel(int a){
	if(a == id[a]) return 0;
	else return peso[a] + rel(id[a]);
}

int new_rel(int rela,int relb,int rell){
	return (rell + 2*rela + relb)%3;
}

void merge(int a,int b,int rell){ ///// A É O MENOR SEMPRE////////////
	int rela = rel(a);
	int relb = rel(b);
	rela = rela%3;
	relb = relb%3;

	rell = new_rel(rela,relb,rell);

	a = find(a);
	b = find(b);
	if(a == b) return;
	id[a] = b;
	sz[b] += sz[a];
	peso[a] = rell; 

}

bool same(int a,int b){
	return(find(a) == find(b));
}


void solve(){
	cin >> n >> k;
	int op,a,b;
	init();
	int ct = 0;
	fr(i,k){
		cin >> op >> a >> b;
		if( a>n || b>n){
			ct++;
			continue;
		}

		if(a == b && op == 1) continue;

		if (a == b && op == 2){
			ct++;
			continue;
		}

		if(!same(a,b)){
			bool tro = false;
			if(sz[a] > sz[b]){
				tro = true;
				swap(a,b);
			}

			if(op == 1){
				merge(a,b,0);
			}

			if(op == 2){
				if(!tro){
					merge(a,b,1);
				}
				else
					merge(a,b,2);
			}
			continue;
		}

		int rela = rel(a);
		int relb = rel(b);
		rela = rela%3;
		relb = relb%3;

		if(rela == relb){
			if(op != 1) ct++;
			continue;
		}
		if(relb == 0){
			if(op == 1)ct++;
			if(op == 2){
				if(rela == 2) ct++;
			}
		}

		if(relb == 1){
			if(op == 1)ct++;
			if(op == 2){
				if(rela == 0) ct++;
			}
		}

		if(relb == 2){
			if(op == 1) ct++;
			if(op == 2){
				if(rela == 1) ct++;
			}
		}


	}

	cout << ct << endl;


}

int main(){

	fastio;
	int T;
	cin >> T;
	while(T--){
		solve();
	}

}
