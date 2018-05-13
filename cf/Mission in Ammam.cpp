#include "bits/stdc++.h"
using namespace std;

#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define pq priority_queue	
#define vi vector<int>
#define vii vector<pair<int,int>>
#define pq priority_queue
#define fr(i,n)	for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)

#define ms(x, v) memset(x, v, sizeof x)
#define all(x)	x.begin(),x.end()

#define dbg(x) cout << #x << " = " << x << endl
#define olar() cout << "olaarr" << endl
#define gnl cout << endl;


const int MAXN = 100100;
const int INF = 0x3f3f3f3f;

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int open[MAXN],pos[MAXN];

int main(){

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m,q;
    cin >> n >> m >> q;
    int ans=m;

    frr(i,n){
    	int x;
    	cin >> x;
    	pos[i]=x;
    	if(open[x]==0)	ans--;
    	open[x]++;
    }

    frr(i,q){
    	int a,b;
    	cin >> a >> b;
    	int last=pos[a];
    	if(open[b]==0)	ans--;
    	open[b]++;
    	open[last]--;
    	if(open[last]==0)	ans++;
    	pos[a]=b;
    	cout << ans << endl;
    }
    
}