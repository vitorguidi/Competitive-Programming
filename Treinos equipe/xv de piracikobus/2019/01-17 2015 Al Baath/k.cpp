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
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;
const ll mod=1e9+7;
const int LMAXN = 20;

int n,mapa[110][110];
vi ans;

bool valid(int x,int y){
	if(x<0 || y<0)
		return false;
	if(x>=n || y>=n)
		return false;
	return true;
}

void solve(){
	cin>>n;

	fr(i,n)
		fr(j,n)
			cin>>mapa[i][j];

	int i=0,j=0;
	ans.clear();

	ans.pb(mapa[0][0]);

	while(i!=(n-1) || j!=(n-1)){

		if(valid(i,j+1)){//direita
			j++;
			ans.pb(mapa[i][j]);
		}
		else{

			i++;
			ans.pb(mapa[i][j]);
		}

		while(valid(i+1,j-1)){//D esquerda
			i++;j--;
			ans.pb(mapa[i][j]);
		}

		if(valid(i+1,j)){///baixo
			i++;
			ans.pb(mapa[i][j]);
		}
		else{
			j++;
			ans.pb(mapa[i][j]);
		}


		while(valid(i-1,j+1)){
			i--;j++;
			ans.pb(mapa[i][j]);

		}

	}

	fr(a,n){
		fr(b,n)
			cout<<ans[n*a+b]<<' ';
	gnl;	
	}		
	


}


int main(){
	fastio;
	int t;
	cin>>t;
	while(t--) solve();
}