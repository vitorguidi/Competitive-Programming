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
#define pq priority_queue
#define grtp greater< pair<int,int> >

#define gnl cout << endl
#define olar cout << "olar" << endl
#define gottagofast ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const double pi = 3.141592653589793238462643383279502884L;

int n,q,v[200200];
int logtable[200200];

int query(int x){

	int base=int(log2(x));

	int ans=0;
	
	for(int i = base;i>=0;i--){

		int aux=int( log2(x) );
		
		// dbg(x);
		// dbg(aux);
		// dbg(i);
		
		int cnt=logtable[i];

		int muda=min( cnt, x/int( exp2(i) ) );
		// dbg(muda);

		x-=int(exp2(i)*muda);
		ans+=muda;
		if(x<=0)
			break;
	}

	if(x==0)
		return ans;
	else
		return -1;

}

int main(){
    
    cin >> n >> q;
    fr(i,n){
    	cin >> v[i];
    	logtable[ int(log2(v[i])) ]++;
    }

    fr(i,q){
    	int x;
    	cin >> x;
    	cout << query(x) << endl;
    }

}

