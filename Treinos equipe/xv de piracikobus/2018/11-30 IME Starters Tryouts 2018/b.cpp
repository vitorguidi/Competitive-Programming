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

int memo[1010][2010];
int gordo[110];
string name[1010];
int peso[1010];
int wkit,m,n;

int clk=1;

int pd(int ind, int wgt){

    if(wgt<=0)
        return 0;

    if(ind==m)
        return INF;

    int& pdm = memo[ind][wgt];
    if(pdm!=-1) return pdm;

    int pega = pd(ind+1,wgt-peso[ind]) + peso[ind];
    int passa = pd(ind+1, wgt);

    return pdm = min(pega, passa);

}

vi ans;

void recover(int ind, int wgt){

    if(ind==m || wgt<=0)
        return;

    int pega = pd(ind+1,wgt-peso[ind]) + peso[ind];
    int passa = pd(ind+1, wgt);

    if(pega<=passa){
        ans.pb(ind);
        recover(ind+1,wgt-peso[ind]);
    }
    else{
        recover(ind+1,wgt);
    }

}

void printa(){

    cout << ans.size() << " ";
    for(auto x : ans)
        cout << name[x] << " ";
    gnl;

    ans.clear();

}
    
int main(){

    fastio;

    cin >> wkit >> m;

    fr(i,m)
        cin >> name[i] >> peso[i];

    cin >> n;

    fr(i,n)
        cin >> gordo[i];

    ms(memo,-1);

    fr(i,n){
        
        int quero = (gordo[i]+1)/2 - wkit;
        if(quero<=0){
            cout << 0 << endl;
            continue;
        }
        int tgt = pd(0,quero);

        if(tgt>=INF){
            cout << -1 << endl;
            continue;
        }

        recover(0,quero);
        printa();

    }

}