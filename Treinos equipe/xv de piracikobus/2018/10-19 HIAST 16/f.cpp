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
int n,v[11234],acum[11234];
int memo[11234][112];

int pd(int score,int ind){
	
	if(ind == n){
		return(abs(2*score - acum[n -1]));
	}

	int &pdm = memo[score][ind];

	if (pdm!= -1)
		return (pdm);

	int aux = min(pd(score + v[ind],ind + 1),pd (score,ind+1));

	int dif;
	if (ind == 0) dif = 0;
	else dif = acum[ind -1];
	
	pdm = max(aux,abs(2*score - dif));

	return (pdm);




}

int main(){

	fastio;
	int T;
	cin >> T;
	while(T--){
		cin >> n;
		
		fr(i,n)
			cin >> v[i];
		
		fr(i,n){
			if (i == 0)
				acum[i] = v[i];
			else
				acum[i] = v[i] + acum[i-1];

		}

		ms(memo,-1);

		cout << pd(0,0) << endl;

	}

}