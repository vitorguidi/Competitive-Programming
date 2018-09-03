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
    
    int n,k,v[110];
    cin >> n >> k;
    fr(i,n)
        cin >> v[i];
    int ini=0;
    int end=n-1;
    int cnt=0;
    while(ini<=end){
    	if(v[ini]<=k){
    		cnt++;
    		ini++;
    	}
    	if(v[end]<=k && end>ini){
    		cnt++;
    		end--;
    	}
    	if(v[ini]>k && v[end]>k)
    		break;
    }
    cout << cnt << endl;

}

