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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int v[110];
int n,m;

int main(){
    
    cin >> n >> m;
    fr(i,n){
    	int x,y;
    	cin >> x >> y;
    	for(int i=x;i<=y;i++)
    		v[i]=1;
    }

    int sum=0;vi ans;
    frr(i,m){
    	if(!v[i]){
    		sum++;ans.pb(i);
    	}
    }

    cout << sum << endl;
    fr(i,ans.size())
    	cout << ans[i] << " ";
    gnl;

}

