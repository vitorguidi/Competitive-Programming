#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
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

int main(){
    
    int n,k;
    vii ppl,ans;
    scanf("%d %d",&n,&k);
    frr(i,n){
        int a;
        scanf("%d",&a);
        ppl.pb(mp(a,i));
    }
    sort(ppl.begin(),ppl.end());
    int mx=0;
    vi resp;
    fr(i,n){
        if(ppl[i].fst>mx){
            mx=ppl[i].fst;
            resp.pb(ppl[i].snd);
        }
    }
    int tam = resp.size();
    if(tam<k)   cout << "NO" << endl;
    else{
        cout << "YES" << endl;
        fr(i,k) cout << resp[i] << " ";
        gnl;
    }
}

