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

int n;
int a[4][3000];
vector<ll> c,b;

int main(){

    cin >> n;

    fr(i,n){
        cin >> a[0][i] >> a[1][i] >> a[2][i] >> a[3][i]; 
    }

    fr(i,n){
        fr(j,n){
            b.pb(a[0][i]+a[1][j]);
            c.pb(a[2][i]+a[3][j]);
        }
    }

    sort(b.begin(),b.end());
    sort(c.begin(),c.end());

    int ans=0;
    fr(i,b.size()){

        auto l = lower_bound(c.begin(),c.end(),-1*b[i]);
        auto r = upper_bound(c.begin(),c.end(),-1*b[i]);
        ans+=(r-l);
    }

    cout << ans << endl;

}
