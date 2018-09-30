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
const int mod = 1e9+7;

int n;
double v[20][20];
double memo[1<<20];

void go(){

	fr(i,1<<20)
		memo[i]=0.0;

	memo[(1<<n)-1]=1.0;
	
	for(int i = (1<<n)-1;i>=0;i--){		//posso calcular nessa ordem pq todas as dependencias de um numero sao estritamente maiores que ele mesmo

		int amt = __builtin_popcount(i);
		double ans = 2.0/(double)(amt*(amt-1));
		
		for(int j=0;j<n;j++){
			for(int k=j+1;k<n;k++){

				if( ( (1<<j)&i ) && ( (1<<k)&i ) ){
					memo[i^(1<<j)]+=ans*v[k][j]*memo[i];
					memo[i^(1<<k)]+=ans*v[j][k]*memo[i];
				}

			}
		}

	}

}

void solve(int cnt){
	
	cin >> n;

	fr(i,n)
		fr(j,n)
			cin >> v[i][j];
	
	go();

	cout << "Case " << cnt << ":";
	fr(i,n)
		cout << " " << memo[1<<i];
	gnl;

}

int main(){
	
	cout << setprecision(6) << fixed;
	int t; cin >> t;
	frr(i,t)	solve(i);

}