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

int freq[300300];
map<pii,int> both;
vi quem[300300];

int main(){

	fastio;

	int n,m;
    cin >> n >> m;

    fr(i,m){
        int x,y;
        cin >> x >> y;
        freq[x]++;
        freq[y]++;
        both[{x,y}]++;
        both[{y,x}]++;
    }

    for(int i=1;i<=n;i++){
        if(freq[i]==0)  continue;
        quem[ freq[i] ].pb(i);
    }

    bool flag=false;

    for(int i=1;i<=m;i++){

        for(auto x : quem[i]){

            for(int j = m-i;j<=m;j++){

                for(auto y : quem[j]){
                    if(x==y)    continue;
                    int aux = i + j - both[{x,y}];
                    if(aux>=m){
                        flag=true;
                        break;
                    }
                }

                if(flag)    break;
            }

            if(flag)    break;

        }

        if(flag)    break;

    }

    cout << (flag ? "YES" : "NO") << endl;

}