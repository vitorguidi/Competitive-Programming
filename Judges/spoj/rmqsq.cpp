#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;

int v[MAXN],memo[MAXN][23];
int n,  q;

void build_table(){		//intervalo aberto na ponta direita

	for(int i=0;i<n;i++)
		memo[i][0]=v[i];

	for(int i=1; i<23; i++ ){

		for(int j=0; j + (1<<i) <= n ; j++){

			int meio = j + (1<<(i-1));
			memo[j][i]=min( memo[j][i-1], memo[meio][i-1] );
		
		}
		
	}

}

int query(int x, int y){

	if(x>y)
		swap(x,y);

	int k = int(log2(y-x+1));
	int meio = y-(1<<k)+1;
	return min( memo[x][k] , memo[meio][k] );

}

int main(){

	cin >> n;

	fr(i,n)
		cin >> v[i];

	build_table();

	cin >> q;
	fr(i,q){
		int x,y;
		cin >> x >> y;
		cout << query(x,y) << endl;
	}

}
