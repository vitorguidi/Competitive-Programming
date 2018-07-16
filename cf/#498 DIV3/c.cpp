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


ll v[200200],pre[200200],suf[200200];

int main(){
    
    int n;
    cin >> n;
    frr(i,n)
    	cin >> v[i];
    
    frr(i,n)
    	pre[i]=pre[i-1]+v[i];

    for(int i=n;i>0;i--)
    	suf[i]=suf[i+1]+v[i];
    

    frr(i,n)
    	suf[i]=-suf[i];

    ll ans=0;

    frr(i,n){

		ll val = -pre[i];    	

		auto find_left = lower_bound(suf+1,suf+n+1,val);
		int left = find_left-suf;

		auto find_right = upper_bound(suf+1,suf+n+1,val);
		find_right--;
		int right = find_right - suf;

		if(!suf[left] )
			continue;

		if(suf[right]==val && right>=left && right>i)
			ans = max(ans,-val);
		if(suf[left]==val && left<=n && left>i)
			ans = max(ans,-val);


    }

    cout << ans << endl;
 
}

