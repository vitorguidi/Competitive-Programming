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

string s;
ll memo[1100100][4];
string aux = "vvovv";
int n;

ll pd(int ind, int state){

    if(state==3)
        return 1ll;

    if(ind==n)
        return 0;

    ll& pdm = memo[ind][state];
    if(pdm!=-1) return pdm;

    pdm=0;

    if(state==0 || state == 2){
        if(ind+1<n && s[ind]=='v' && s[ind+1]=='v')
            pdm+=pd(ind+2,state+1);
    }
    if(state == 1 && s[ind]=='o')
        pdm+=pd(ind+1,state+1);

    pdm+=pd(ind+1,state);

    return pdm;

}

int main(){

	fastio;

    cin >> s;
    
    n = s.size();

    ll ans = 0;

    ms(memo,-1);

    cout << pd(0,0) << endl;

}
