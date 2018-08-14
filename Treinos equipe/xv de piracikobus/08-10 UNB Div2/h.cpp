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
const int MAXN = 100100; 

int main(){
	int p=0,ip=0,ant,res;
	ant = 1;
	printf("10\n");
	fflush(stdout);
	while (1){
		scanf("%d",&res);
		if (res == -1) break;
		if (res == 0 && ant ==1) p++;
		if (res == 1 && ant == 1) ip++;
		if (res == 0 && ant ==0) ip++;
		if (res == 1 && ant == 0) p++;

		if (p>ip){
			printf("1\n");
			fflush(stdout);
			ant = 0;
		}
		else{
			printf("2\n");
			fflush(stdout);
			ant = 1;
		}
	}

	return 0;
}