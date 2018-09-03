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

    int n,m;
    ll acum[200100],letters[200100];
    ms(acum,0);

    cin >> n >> m;
    frr(i,n){
        ll aux;
        cin >> aux;
        acum[i]=acum[i-1]+aux;
    }
    frr(i,m){
        cin >> letters[i];
    }


    frr(i,m){
        ll *dorm,pos;
        dorm=lower_bound(acum,acum+n,letters[i]);
        pos=dorm-acum;
        ll ans = letters[i]-acum[pos-1];
        cout << pos << " " << ans << endl; 
    }

}

