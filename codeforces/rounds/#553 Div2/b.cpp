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

int memo[1030][505];
int grid[505][505];
int n,m;
stack<int> ans;


int pd(int num, int row){
    if(row==n){
        if(num>0)   return 1;
        return 0;
    }

    int& pdm = memo[num][row];
    if(pdm!=-1) return pdm;

    pdm = 0;

    for(int i=0;i<m;i++){
        ans.push(i+1);
        int aux = pd(num^grid[row][i], row+1);
        if(aux)
            return pdm=1;
        ans.pop();
    }

    return pdm=0;
}

int main(){

	fastio;

     cin >> n >> m;

     fr(i,n)
        fr(j,m)
            cin >> grid[i][j];

    ms(memo, -1);

    if(pd(0,0)==0){
        cout << "NIE" << endl;
        return 0;
    }

    vi put;
    while(!ans.empty()){
        put.pb(ans.top());
        ans.pop();
    }

    reverse(all(put));

    cout << "TAK" << endl;
    for(auto x : put)
        cout << x << " ";
    gnl;

}