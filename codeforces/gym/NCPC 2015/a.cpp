#include "bits/stdc++.h"
#define FILE_IN freopen("in", "r", stdin);
#define FILE_OUT freopen("out", "w", stdout);
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define fi first
#define se second
#define ll long long
#define pii pair<int,int>

bool debug = 0;
#define prin(a) if(debug) cout << #a << " = " << (a) << endl
#define prinpar(a) if(debug) printf("%d/%d\n", (a.fi), (a.se))
#define separa() if(debug) cout << endl

const ll MOD = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-9;
using namespace std;
#define N 100100

int fat[N], rnk[N];

int find(int x) { return fat[x] == x ? x : fat[x] = find(fat[x]); }
void join(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return;
    rnk[a] = max({rnk[a], rnk[b], (rnk[a]+1)/2 + (rnk[b]+1)/2 + 1});
    fat[b] = a;
}

int d[N];
vector<int> adj[N];
bool vis[N];
pii bfs(int x) {
    vector<int> vis_;
    queue<int> f;
    f.push(x);
    d[x] = 0;
    int idres = x;
    while(!f.empty()) {
        int u = f.front(); f.pop();
        vis_.pb(u);
        vis[u] = 1;
        for(int v : adj[u]) {
            if(d[v] != -1) continue;
            d[v] = d[u] + 1;
            if(d[v] > d[idres]) idres = v;
            f.push(v);
        }
    }
    pii res = {idres, d[idres]};
    for(int v : vis_) d[v] = -1;
    return res;
}

int main () {

    int n,m;

    scanf("%d %d", &n, &m);
    FOR(i,0,n) {
        d[i] = -1;
        fat[i] = i;
    }

    int a,b;
    FOR(i,0,m) {
        scanf("%d %d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
        join(a,b);
    }


    int maxi=-1;
    int id;
    FOR(i,0,n) {
        if(vis[i]) continue;
        pii a = bfs(i);
        pii b = bfs(a.fi);
        rnk[find(b.fi)] = b.se;
        prin(i);
        prin(find(b.fi));
        prin(b.fi);
        prin(b.se);
        separa();
        if(b.se > maxi) {
            maxi = b.se;
            id = find(b.fi);
        }
    }

    prin(id);
    prin(maxi);
    prin(rnk[find(id)]);
    separa();
    FOR(i,0,n) {
        join(id,i);
        prin(i);
        prin(find(id));
        prin(rnk[find(id)]);
        separa();
    }

    prin(find(id));
    prin(rnk[find(id)]);
    

    cout << rnk[find(id)] << endl;

    return 0;

}


