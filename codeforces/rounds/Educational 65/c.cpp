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

int id[500500],sz[500500];

int find(int a){
    if(a==id[a])    return a;
    return id[a]=find(id[a]);
}

void join(int a, int b){
    a=find(a);b=find(b);
    if(a==b)    return;
    if(sz[a]<sz[b])
        swap(a,b);
    id[b]=a;
    sz[a]+=sz[b];
}

vi adj[500500];

int main(){

	fastio;

    int n,m;
    cin >> n >> m;

    for(int i=1;i<=n;i++){
        id[i]=i;
        sz[i]=1;
    }

    for(int i=1;i<=m;i++){
        int amt; cin >> amt;
        if(!amt)    continue;
        int x; cin >> x;
        for(int i=1;i<amt;i++){
            int y; cin >> y;
            join(x,y);
        }
    }	

    for(int i=1;i<=n;i++)
        cout << sz[find(i)] << " ";
    gnl;

}