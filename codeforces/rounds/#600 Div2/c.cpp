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

ll dp[200200];
ll acum[200200];

int main() {

	int n,m;
	cin >> n >> m;
	vi candies(n);

	fr(i,n){
		cin >> candies[i];
	}

	sort(all(candies));

	fr(i,n){
		acum[i]+=candies[i];
		if(i>=0)	acum[i]+=acum[i-1];
	}

	for(int i=0;i<n;i++){
		dp[i]=acum[i];
		if(i-m>=0)	dp[i]+=dp[i-m];
	}

	fr(i,n){
		cout << dp[i]<< " ";
	}
	gnl;

}
