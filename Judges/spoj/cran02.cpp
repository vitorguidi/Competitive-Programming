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

    int t,n,v[1001000],acum[1001000],x;
    cin >> t;
    while(t--){
        cin >> n;
        ms(acum,0);
        frr(i,n)
            cin >> v[i];
        frr(i,n)
            acum[i]=acum[i-1]+v[i];
        sort(acum+1,acum+n+1);
        int i=1,j=1;
        ll ans=0;
        while(i<=n && j<=n){
            while(acum[j+1]==acum[i] && j+1<=n)
                j++;
            while(i<=j){
                if(acum[i]==0)
                    ans++;
                ans+=j-i;
                i++;
            }
            i=j+1;
            j++;
        }
        cout << ans << endl;
    }

}
