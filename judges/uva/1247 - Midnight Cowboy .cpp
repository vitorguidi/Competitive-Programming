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
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) 

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;

int n,a,b,c;

const double eps = 1e-9;

double coef[110][110], val[110];
vi adj[110];
int where[110];

void printa(){

    cout << setprecision(2) << fixed;

    frr(i,n){
        frr(j,n)
            cout << coef[i][j] << " ";
        cout << "- " << val[i] << endl;
    }
    gnl;

}

void go(){

    fr(i,110){
        where[i]=i;
        adj[i].clear();
    }

    fr(i,n-1){
        int x,y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    frr(i,n)
        frr(j,n)
            coef[i][j]=0;

    coef[c][c]=coef[b][b]=1;

    frr(i,n){
        if(i==c || i==b)    continue;
        int cnt = adj[i].size();
        for(auto x : adj[i])
            coef[i][x]=1.0/cnt;
        coef[i][i]=-1;
        val[i]=0;
    }

    val[b]=1.0;
    val[c]=0.0;

    //printa();

    for (int col=1, row=1; col<=n && row<=n; col++) {
        
        int pivot = row;

        for (int i=row; i<=n; ++i)
            if (abs (coef[i][col]) > abs (coef[pivot][col]))
                pivot = i;

        swap(coef[pivot],coef[row]);
        swap(val[pivot],val[row]);
        swap(where[row], where[pivot]);

        for (int i=1; i<=n; ++i)
            if (i != row) {
                double c = coef[i][col] / coef[row][col];
                for (int j=col; j<=n; j++)
                    coef[i][j] -= coef[row][j] * c;
                val[i]-=c*val[row];
            }
        ++row;
    }

    for(int i=1; i<=n; i++)
        val[i]=val[i]/coef[i][i];

    cout << fabs(val[a]) << endl;

}

int main(){

    fastio;
    cout << setprecision(6) << fixed;
    while(cin>> n >> a >> b >> c)
        go();

}