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

    int n,m,c[100100],t[100100];

    cin >> n >> m;

    fr(i,n)
        cin >> c[i];
    fr(i,m)
        cin >> t[i];

    sort(c,c+n);
    sort(t,t+m);

    int ini=0;
    int end=0;
    
    int r=0;

    fr(i,n){
        while(ini+1 < m && t[ini+1]<=c[i])
            ini++;
        while(end+1 < m && t[end]<=c[i])
            end++;
        int nr = min(abs(c[i]-t[ini]),abs(c[i]-t[end]));
        r=max( r,nr );
    }
    cout << r << endl;
    
}