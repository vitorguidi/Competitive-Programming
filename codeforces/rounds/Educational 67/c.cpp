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

int id[1010];
int sz[1010];
int vis[1010];
int ans[1010];

int find(int a){
    if(a==id[a])    return a;
    return id[a]=find(id[a]);
}

void join(int a,int b){
    a=find(a);b=find(b);
    if(a==b)    return;
    if(sz[a]<sz[b]) swap(a,b);
    id[b]=a;
    sz[a]+=sz[b];
}

int main(){

	fastio;

	int n,m;
    cin >> n >> m;

    frr(i,n){
        id[i]=i;
        sz[i]=1;
    }

    vii caga;

    while(m--){
        int op,l,r;
        cin >> op >> l >> r;
        if(!op){
            caga.pb({l,r});
        }
        else{
            for(int i=l+1;i<=r;i++)
                join(l,i);
        }
    }

    for(auto x : caga){
        if(find(x.fst)==find(x.snd)){
            cout << "NO" << endl;
            return 0;
        }
    }

    int val = n;

    frr(i,n){
        if(!vis[find(i)]){
            vis[find(i)]=1;
            ans[find(i)]=val--;
        }
    }
    cout << "YES" << endl;
    frr(i,n)
        cout << ans[find(i)] << " ";
    gnl;
}