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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int n;
int seq[200200];

int main(){
    
	cin >> n;
	
	if(n==1){
		cout << 1 << endl;
		return 0;
	}

	frr(i,n)
		cin >> seq[i]; 

	int ans = 1;
	int end=1;

	while(end<=n){

		int aux = 1;

		while( end<=n){

			end++;
			if(end>n)
				break;

			if(2*seq[end-1] >= seq[end])
				aux++;
			else
				break;
		}

		ans = max(ans,aux);
	
	}


	cout << ans << endl;

}

