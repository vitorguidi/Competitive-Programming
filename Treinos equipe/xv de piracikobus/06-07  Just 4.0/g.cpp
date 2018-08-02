#include <bits/stdc++.h>
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

int v[1001000],pref[1000100],suf[1000100];

int main(){

	int t,n;
	scanf("%d",&t);
	
    while(t--){
		
        int n;
		
        scanf("%d",&n);
		fr(i,n) scanf("%d",&v[i]);
		
        ms(pref,-INF);
        ms(suf,INF);
        
        for(int i=1;i<n;i++)
            pref[i]=max(pref[i-1],v[i-1]);
        for(int i=n-2;i>=0;i--)
            suf[i]=min(suf[i+1],v[i+1]);
        
        int cnt=0;
		
        fr(i,n){
            if(i==0 || i==n-1)    continue;
            if(v[i]>=pref[i] && v[i]<=suf[i])    cnt++;
        }
		
        printf("%d\n",cnt);	
	}
	
}
