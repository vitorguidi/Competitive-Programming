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

int main(){ 

    int caso=0;
    while(true){
        int a,v,cnt[110];
        ms(cnt,0);
        caso++;
        cin >> a >> v;
        if(a==0)
            break;
        cout << "Teste " << caso << endl;
        int mx=0;
        fr(i,v){
            int x,y;
            cin >> x >> y;
            cnt[x]++;
            cnt[y]++;
            mx=max(mx,cnt[x]);
            mx=max(mx,cnt[y]);
        }
        frr(i,a){
            if(cnt[i]==mx)
                cout << i << " ";
        }
        gnl;
        gnl;
        
    }

}
