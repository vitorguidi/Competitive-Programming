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

void go(){

    int n,m;
    cin >> n >> m;
    vector<string> v(n);
    string aux;
    getline(cin,aux);

    fr(i,n){
        getline(cin,v[i]);
    }

    vi lencol(m);
    vi lenrow(n);

    fr(i,n){
        fr(j,m){
            if(v[i][j]=='*')
                lenrow[i]++;
        }
    }

    fr(i,m){
        fr(j,n){
            if(v[j][i]=='*')
                lencol[i]++;
        }
    }

    int ans = INF;

    fr(i,n){
        fr(j,m){
            int custo = n - lenrow[i] + m - lencol[j];
            if(v[i][j]=='.')
                custo--;
            ans=min(ans,custo);
        }
    }

    cout << ans << endl;

}

int main(){

	fastio;

	int q; cin >> q;
    while(q--)
        go();

}