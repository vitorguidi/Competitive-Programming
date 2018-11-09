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

int main(){

	fastio;

	int n,p,x;
	cin >> p >> n >> x;

	int jump = x/p;

	int ans1 = jump + abs(jump*p-x);

	int fim = jump*p + p;
	int ans2 = jump+1;

	if(fim>n){
		fim=n; 
	}
	ans2+=abs(fim-x);
	

	int ans3=0;
	ans3+=(n+p)/p;
	ans3+=abs(x%p - n%p);
	ans3+=abs(x/p - n/p); 


	cout << min({ans1,ans2,ans3}) << endl;

}