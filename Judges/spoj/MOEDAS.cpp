#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cerr << #x << " = " << x << endl
#define pq priority_queue
#define grtp greater< pair<int,int> >

#define gnl cout << endl
#define olar cout << "olar" << endl

typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int v[110],n,m,memo[50100][110];

int pd(int m){

    if(m<0)     return INF;
    if(m==0)    return 0;

    int &pdm=memo[m][n];
    if(pdm!=-1) return pdm;

    int ans=INF;
    fr(i,n) ans=min( ans,1+pd(m-v[i]) );
    return pdm=ans;
}

int main(){
    
    m=-1;
    while(m!=0){
        cin >> m;
        if(m==0)    break;
        cin >> n;
        fr(i,n) cin >> v[i];
        ms(memo,-1);
        int ans=pd(m);
        if(ans!=INF)    cout << pd(m) << endl;
        else            cout << "Impossivel" << endl;
    }
    
}
    
