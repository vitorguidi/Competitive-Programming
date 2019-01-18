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

int t,n,q;
ll sum[10100][26];
char s[10100];
char c;

int main(){
    
    scanf("%d",&t);
    
    while(t--){
        scanf("%d %d",&n,&q);
        scanf(" %s",s);
        
        fr(i,26){
            
            frr(j,n){
                if(s[j-1]==i+'a')   sum[j][i]=sum[j-1][i]+1;
                else                sum[j][i]=sum[j-1][i];    
            }

        }

        fr(i,q){

            int l,r;
            scanf("%d %d %c",&l,&r,&c);
            
            int letra = c-'a';
            ll pf= r/n;
            ll pb= (l-1)/n;
          	
          	ll front = sum[n][letra]*pf+ sum[r%n][letra];
            
            ll back = sum[n][letra]*pb + sum[(l-1)%n][letra];

            printf("%lld\n",front-back);
            
        }
    }

}
