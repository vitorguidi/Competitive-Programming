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
    
    int seen[1010],seq[1010];
    int n;

    ms(seen,-1);
    scanf("%d",&n);

    int cnt=0;
    frr(i,n){
        scanf("%d",&seq[i]);
        if(seen[seq[i]]==-1){
            seen[seq[i]]=i;
        }
        else{
            cnt++;
            seq[seen[seq[i]]]=INF;
            seen[seq[i]]=i;
        }
    }

    cout << n-cnt << endl;
    frr(i,n){
        if(seq[i]==INF) continue;
        cout << seq[i] << " ";
    }
    gnl;


}

