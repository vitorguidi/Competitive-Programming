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
#define gottagofast ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int n,m,ans[110],bgn[110],amt[110],done[110];
pii due[110];

int main(){

    scanf("%d %d",&n,&m);

    frr(i,m){
        int x,y,z;  //quando comeca, dia da prova, dias de estudo
        scanf("%d %d %d",&x,&y,&z);
        due[i]=mp(y,i);
        bgn[i]=x;
        amt[i]=z;
        ans[y]=m+1;
    }

    sort(due+1,due+m+1);
    frr(i,m){
        int test = due[i].snd;
        int start=bgn[test];
        int days=amt[test];
        while(days>0){

            if(start>=due[i].fst){
                cout << -1 << endl;
                return 0;
            }

            if(ans[start]==0){
                ans[start]=test;
                days--;
            }
            start++;
        }
    }

    frr(i,n)    cout << ans[i] << " ";
    gnl;

}

