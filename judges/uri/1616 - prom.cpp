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

#define gnl cout << endl
#define olar cout << "olar" << endl
#define gottagofast ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

ll memo[1010][1010];

ll b,g;

ll pd(int x, int y){

    if(x==0 && y==0)
        return 1;

    if(x<0 || y<0)
        return 0;
    
    if(x==0 && y>0)
        return 0;

    ll &pdm=memo[x][y];

    if(pdm!=-1)
        return pdm;

    return pdm =  ( (g-y)*pd(x-1,y) + y*pd(x-1,y-1) ) % 1000000007;

}

int main(){

    while(cin >> b){

        cin >> g;

        if(!b)
            break;
        
        ms(memo,-1);
        cout << pd(b,g) << endl;

    }

}