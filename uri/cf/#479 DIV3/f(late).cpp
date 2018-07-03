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
    
    int seq[200100],n;
    map<int,int> pd;

    scanf("%d",&n);
    frr(i,n)    scanf("%d",&seq[i]);

    int mx,val;
    mx=val=0;

    frr(i,n){
        pd[seq[i]]=pd[seq[i]-1]+1;
        if(pd[seq[i]]>mx){
            val=seq[i];
            mx=pd[seq[i]];
        }
    }

    vi ans;
    for(int i=n;i>0;i--){
        if(seq[i]==val){
            ans.pb(i);
            val--;
        }
    }

    cout << ans.size() << endl;
    reverse(ans.begin(),ans.end());
    fr(i,ans.size())    cout << ans[i] << " ";
    gnl;

}
