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

int n;
int seq[1000001];

int sel[9][2] = { {28,1},{14,2},{9,3},{7,4},{5,5},{4,7},{3,9},{2,14},{1,28} };

int pd(int ind){

	if(ind==n)
		return 0;
	int i,j;
	int maxx=0;
	bool ok;
	for (i=0;i<9;i++){
		if (seq[ind] <= sel[i][1]){
			ok = true;
			for(j=ind;j<(sel[i][0] + ind) && j<n;j++){
				if(seq[j] > sel[i][1])
					ok = false;
			}
			if (ok)
				maxx = max(maxx,j-ind); 
		}
	}



	return (1 + pd (ind + maxx));

}

int main(){

	fastio;
	cin >> n;

	fr(i,n){
		int aux; cin >> aux;
		int num = 32 - __builtin_clz(aux);
		seq[i]=num;
	}
	cout << "Total bytes: " << 4*pd(0) << endl;

}