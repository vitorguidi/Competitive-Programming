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
#define all(x)	x.begin(),x.end()

#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) 

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;

int v[300300];
int work[300300];
int n,m;

bool check(int val){

    memcpy(work,v,sizeof work);

    for(int i=n;i>0;i--){

        if(work[i]==work[i+1]) continue;

        else if(work[i]>work[i+1]){
            int passa = m - work[i];
            if(passa>val)   return false;
            int resto = val-passa;
            work[i] = resto;
            work[i] = min(work[i],work[i+1]);
        }

        else{
            work[i]+=val;;
            work[i]=min({work[i],m-1,work[i+1]});
        }

    }

    for(int i=1;i<n;i++)
        if(work[i]>work[i+1])
            return false;


    // dbg(val);

    // for(int i=1;i<=n;i++)
    //     cout << work[i] << " ";
    // gnl;

    return true;

}

int main(){

	fastio;

    cin >> n >> m;

    frr(i,n)    cin >> v[i];
    v[n+1]=INF;

    int ini = 0;
    int end = 2*m;
    int best = -1;
    while(ini<=end){
        int mid = (ini+end)>>1;
        if(check(mid)){
            best=mid;
            end=mid-1;
        }
        else
            ini=mid+1;
    }

    cout << best << endl;

}