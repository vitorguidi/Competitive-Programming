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

int main(){

    gottagofast;
    int quarrel[200100];
    int param[200100],org[200100];
    map<int,int> refr;

    int n,k;
    cin >> n >> k;

    ms(param,-INF);
    ms(quarrel,0);

    fr(i,n){
        int aux;
        cin >> aux;
        param[i]=org[i]=aux;
    }

    fr(i,k){
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        if(param[x]<param[y])   quarrel[y]++;
        if(param[y]<param[x])   quarrel[x]++;
    }

    fr(i,n) param[i]=-param[i];
    sort(param,param+n);

    fr(i,n){
        auto it = upper_bound(param,param+n,-org[i]);
        int num=it-param;
        int ans;
        if(num==n) ans=0;
        else{
            ans=n-num-quarrel[i];
        }
        cout << ans << " ";
    }
    gnl;

}

