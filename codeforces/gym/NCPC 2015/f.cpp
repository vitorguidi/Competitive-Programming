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

bool memo[110][10100][2];
int vis[110][10100][2];
int clk=1;
int n,t;
vii intv;

bool dp(int ind, int where,int dir){

    if(where<0 || where>t)
        return false;

    if(ind==n)
        return true;

    bool& pdm=memo[ind][where][dir];

    if(vis[ind][where][dir]==clk)
        return pdm;

    vis[ind][where][dir]=clk;

    int delta = intv[ind].snd-intv[ind].fst;
    int tem = ( dir==0 ? where : t-where );

    if(delta>tem)
        return pdm=false;

    pdm=false;

    if(dir==0){

        pdm = dp(ind+1,where-delta,dir);
        if(pdm)
            return pdm;
        
        pdm=dp(ind+1,where-delta,!dir);
        if(pdm)
            return pdm;
    
    }
    else{

        pdm = dp(ind+1,where+delta,dir);
        if(pdm)
            return pdm;

        pdm = dp(ind+1, where+delta,!dir);
        if(pdm)
            return pdm;
    }

    return pdm=false;

}

bool go(){

    scanf("%d %d",&t,&n);
    intv.clear();

    fr(i,n){
        int x,y;
        cin >> x >> y;
        intv.pb({x,y});
    }

    clk++;
    for(int i=0;i<t;i++)
        if(dp(0,i,1)|dp(0,i,0))
            return true;
    return false;

}

int main(){


    bool ans = true;

    int f;
    scanf("%d",&f);
    while(f--)  ans&=go();

    if(ans)
        puts("possible");
    else
        puts("impossible");

}