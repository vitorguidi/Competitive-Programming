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

int n,c;
int v[222000];
int memo[220200][2];

int pd(int ind, int have){

    if(ind==n)
        return 0;

    int &pdm=memo[ind][have];

    if(pdm!=-1)
        return pdm;

    if(!have)
        return pdm= ( max( -c-v[ind]+pd(ind+1,1) , pd(ind+1,0) ) );

    return pdm=max( v[ind] +pd(ind+1,0) , pd(ind+1,1)  );

}

int main(){

    while(cin >> n){
        
        cin >> c;

        fr(i,n)
            cin >> v[i];

        ms(memo,-1);
        cout << pd(0,0) << endl;
    }

}
