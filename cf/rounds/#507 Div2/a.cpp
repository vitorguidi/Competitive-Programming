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

int v[22];

bool is_pal(int n){

	fr(i,(n+1)/2){

		if(v[i]==2 || v[n-1-i]==2)
			continue;

		if(v[i]!=v[n-i-1])
			return false;

	}

	return true;

}

int main(){
    
    int n,a,b;
    cin >> n >> a >> b;

    int ans=0;

    fr(i,n){
    	int aux; cin >> aux;
    	v[i]=aux;
    }

    if(!is_pal(n)){
    	cout << -1 << endl;
    	return 0;
    }

    fr(i, (n+1)/2 ){
    	
    	int left = i;
    	int right = n-1-i;


    	if(left==right){
    		if(v[left]==2){
    			ans+=min(a,b);
    			continue;
    		}
    		else
    			continue;
    	}

    	if(v[left]==2 && v[right]==2)
    		ans+=2*min(a,b);
    	

    	else if(v[left]==2 && v[right]==0)
    		ans+=a;
    	
    	else if(v[left]==2 && v[right]==1)
    		ans+=b;
    	

    	else if(v[left]==0 && v[right]==2)
    		ans+=a;
    	else if(v[left]==1 && v[right]==2)
    		ans+=b;


    }

    cout << ans << endl;


}

