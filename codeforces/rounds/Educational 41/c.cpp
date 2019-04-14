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

vector<string> boards[4];
vi perm = {0,1,2,3};
int n;

int solve(){

	vector<string> coiso;

	vector<string> upper;
	fr(i,n){
		string aux = boards[perm[2]][i] + boards[perm[3]][i];

		upper.pb(aux);

	}
	vector<string> lower;
	fr(i,n){
		string aux = boards[perm[0]][i] + boards[perm[1]][i];
		lower.pb(aux);
	}

	int cost = 0;

	for(auto x : upper)	coiso.pb(x);
	for(auto x : lower)	coiso.pb(x);

	fr(i,2*n){
		fr(j,2*n){
			int cara = coiso[i][j]-'0';
			if(cara!=(i+j)%2)	cost++;
		}
	}

	return cost;

}

int main(){
    
	fastio;

	cin >> n;

	fr(i,4){

		fr(j,n){
			string aux2;
			cin >> aux2;
			boards[i].pb(aux2);
		}
	}

	int ans = INF;

	do{
		ans=min(ans,solve());
	}while(next_permutation(all(perm)));

	cout << ans << endl;

}