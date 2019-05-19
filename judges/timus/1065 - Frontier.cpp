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

struct point{

    int x,y;

    point(){}
    point(int a, int b){
        x=a,y=b;
    }

    int operator*(point p){
        return x*p.x + y*p.y;
    }
    int operator^(point p){
        return x*p.y-y*p.x;
    }
    point operator-(point p){
        return {x-p.x,y-p.y};
    }
    long double dist(point p){
        return sqrt( (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y) );
    }

};

point guards[55];
point monuments[1010];

long double adj[55][55];

int main(){

    fastio;

    int n,m;
    cin >> n >> m;

    frr(i,n){
        int x,y;
        cin >> x >> y;
        guards[i]=point(x,y);
    }
    frr(i,m){
        int x,y;
        cin >> x >> y;
        monuments[i]=point(x,y);
    }

    frr(i,n)
        frr(j,n)
            adj[i][j]=1e20;

    frr(i,n)
        adj[i][i]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){

            if(i==j)
                continue;

            bool flag = true;

            frr(k,m){
                int aux = (monuments[k]-guards[i])^(guards[j]-guards[i]);
                if(aux<=0)
                    flag=false;
            }

            if(!flag)
                continue;

            adj[i][j]=guards[i].dist(guards[j]);

        }
    }    

    frr(k,n)
        frr(i,n)
            frr(j,n)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

    long double ans = 1e20;

    frr(i,n){   
        frr(j,n){
            if(i==j)
                continue;
            frr(k,n){
                if(k==j || i==k)
                    continue;
                if( (guards[i]-guards[j])^(guards[i]-guards[k]) )
                    ans = min(ans, adj[i][j] + adj[j][k] + adj[k][i]);
            }
        }
    }

    cout << setprecision(15) << fixed;
    cout <<ans << endl;

}