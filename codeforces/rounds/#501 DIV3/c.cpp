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

pii  cost[100100];

int main(){
    
    ll n,m;
    
    cin >> n >> m;

    ll sum =0;

    frr(i,n){
    	int x,y;
    	cin >> x >> y;
    	cost[i] = {x-y,x};
    	sum+=x;
    }

    sort(cost+1,cost+n+1);
    reverse(cost+1,cost+n+1);

    if(sum<=m){
    	cout << 0 << endl;
    	return 0;
    }

    int cnt=0;
    
    for(int i=1;i<=n;i++){
    	cnt++;
    	sum-=cost[i].fst;
    	if(sum<=m){
    		cout << cnt << endl;
    		return 0;
    	}
    }

    cout << -1 << endl;


}

