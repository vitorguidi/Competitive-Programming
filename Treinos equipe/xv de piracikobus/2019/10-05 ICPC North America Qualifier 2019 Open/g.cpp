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

#define endl "\n" 
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) 
 
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;
 
const int INF = 0x3f3f3f3f;

double dp[110][110];
double prob[110];
vi aux;

int main(){

	fastio;

	int n;
	cin >> n;
	fr(i,n){
		int x; cin >> x;
		aux.pb(x);
	}

	sort(all(aux));
	reverse(all(aux));

	dp[0][0]=1.0;
	
	for(int i=1;i<=n;i++){

		prob[i] = aux[i-1]/100.0;

		dp[i][0] = dp[i-1][0]*(1.0-prob[i]);
		
		for(int j=1;j<=n;j++)
			dp[i][j] = 
				prob[i]*dp[i-1][j-1] +
				(1-prob[i])*dp[i-1][j];
		
	}

	// for(int i=1;i<=n;i++){
	// 	dbg(i);
	// 	double lol = 0;
	// 	for(int j=0;j<=i;j++)
	// 		lol+=dp[i][j];
	// 	dbg(lol);
	// }

	//Guidi, a chamada caiu, ccta aionecta ai
	// ta bugado
	//nois
	double ans = 0;

	for(int i=1;i<=n;i++){
		double cnt = 0;
		for(int j=1;j<=n;j++){
			cnt+=dp[i][j]*pow(j,j/double(i));
		}
		ans=max(ans,cnt);
	}
 
	cout << setprecision(10) << fixed;
	cout << ans<< endl;

}