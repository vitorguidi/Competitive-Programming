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

int n,k;
int memo[1100100];

ll pd(int x){

    if(x==0)
        return memo[x]=0;

    int& pdm=memo[x];
    if(pdm!=-1)
        return pdm;

    int cand1 = x-1;
    int cand2 = x-2;
    int cand3 = x-k;

    set<int> mex;

    if(cand1>=0)
        mex.insert(pd(cand1));
    if(cand2>=0)
        mex.insert(pd(cand2));
    if(cand3>=0)
        mex.insert(pd(cand3));

    for(int i=0;i<=10000;i++)
        if(mex.find(i)==mex.end())
            return pdm=i;
}

int main(){

    fastio;

    int q; cin >> q;
    while(q--){
        int n,k;
        cin >> n >> k;
        int grundy;
        if(k%3==0){
            grundy = n%(k+1);
            if(grundy==k)
                grundy=3;
            else
                grundy=grundy%3;
        }
        else
            grundy = n%3;
        cout << ( grundy != 0 ? "Alice" : "Bob" ) << endl;
    }
    

}