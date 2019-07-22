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
const int MOD = 1e9+7;

int primes[1100100];
int check[1100100];
map<pii,int> seen;
int deg[1010];

int main(){

	fastio;

	int n; cin >> n;

    for(int i=2;i<=1000000;i++){
        if(!check[i]){
            primes[i]=1;
            for(int j=i;j<=1000000;j+=i)
                check[j]=1;
        }
    }

    set<pii> adj;
    int cnt = n;

    for(int i=0;i<n;i++){
        seen[{i,(i+1)%n}]=1;
        adj.insert({i,(i+1)%n});
        deg[i]++;
        deg[(i+1)%n]++;
    }

    int ini=0;

    while(!primes[cnt]){
        while(deg[ini]!=2)
            ini=(ini+1)%n;
        int to = (ini+1)%n;
        while(deg[to]!=2 || seen[{ini,to}] || seen[{to,ini}])
            to=(to+1)%n;
        cnt++;
        seen[{ini,to}]=1;
        adj.insert({ini,to});
        deg[ini]++;
        deg[to]++;
    }

    cout << cnt << endl;
    for(auto x : adj)
        cout << x.fst+1 << " " << x.snd+1 << endl;

}