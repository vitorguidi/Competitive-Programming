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

int n,v[112345],p=pow(10,9) + 7;

long long sum (int i){
    if (i==n-1) return (v[n-1]);
    long long x;
    x = sum (i+1)%p;
    return((v[i]*(1 + x) + x)%p);
}

int main(){

	int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        fr(i,n)
            scanf("%d",&v[i]);
        printf("%I64d\n",sum(0));



    }
}
