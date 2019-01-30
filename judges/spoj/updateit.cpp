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

    gottagofast;
    int t,v[100100],aux[100100];
    cin >> t;
    while(t--){
        int n,u,q;
        cin >> n >> u;
        ms(aux,0);
        ms(v,0);
        fr(i,u){
            int l,r,val;
            cin >> l >> r >> val;
            aux[l]+=val;
            aux[r+1]-=val;
        }
        int sum=0;
        fr(i,n){
            sum+=aux[i];
            v[i]+=sum;
        }
        int x;
        cin >> q;
        fr(i,q){
            cin >> x;
            cout << v[x] << " ";
        }
        gnl;
    }

}
