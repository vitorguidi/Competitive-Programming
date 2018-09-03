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
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n,w,delta[1010];
    cin >> n >> w;
    int mn=INF;
    int mx=-INF;

    fr(i,n) cin>>delta[i];

    int cnt=0;
    fr(i,n){
        cnt+=delta[i];
        mn=min(mn,cnt);
        mx=max(mx,cnt);
    }

    if(mn>0)    mn=0;
    if(mx<0)    mx=0;

    int amp=mx-mn;

    if(amp>w)   cout << 0 << endl;
    else        cout << w-mx+mn+1 << endl;


}

