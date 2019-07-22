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

bool sortedl[300300];
bool sortedr[300300];

int main(){

	fastio;

    int n; cin >> n;
    vi v(n);
    set<int> lol;
    fr(i,n){
        cin >> v[i];
        lol.insert(v[i]);
    }

    if(lol.size()!=n){
        cout << "NO" << endl;
        return 0;
    }

    int from = -1;
    int who = -1;

    fr(i,n){
        if(v[i]>who){
            who=v[i];
            from=i;
        }
    }

    sortedr[n-1]=true;
    sortedl[0]=true;

    for(int i=1;i<n;i++){
        sortedl[i] = sortedl[i-1]&(v[i]>v[i-1]);
    }
    for(int i=n-2;i>=0;i--){
        sortedr[i] = sortedr[i+1]&(v[i]>v[i+1]);
    }

    cout << (sortedl[from] && sortedr[from] ? "YES" : "NO") << endl; 

}