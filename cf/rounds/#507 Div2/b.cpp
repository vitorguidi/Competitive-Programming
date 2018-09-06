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

int n,k;
int memo[1010];

int main(){
    
	int n,k;
	cin >> n >> k;

	int amt = (n+2*k)/(2*k+1);	


	int id=0;

	if(n<=2*k+1){
		cout << 1 << endl;
		cout << min(k+1,n) << endl;
		return 0;
	}

	if(n%(2*k+1)==0){
		
		cout << n/(2*k+1) << endl;
		int ini = min(k+1,n);
		frr(i,amt){
			cout << ini << " ";
			ini=min(n,ini+2*k+1);
		}
		gnl;
		return 0; 
	}

		cout << amt << endl;

	frr(i,k+1){

		int borda = min(k,n-i);
		int aux = n-i-borda; 
		aux=aux%(2*k+1);

		if(aux>k)
			id=i;

	}

	while(id<=n){
		cout << id << " ";
		id+=2*k+1;
	}
	gnl;



}

