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

ll n,v[120120],check[120120];

int main(){    
	
	cin >> n;
	
	fr(i,n)
		cin >> v[i];

	sort(v,v+n);

	ll cnt=0;

	fr(i,n){

		ll flag=0;

		fr(j,33){
		
			ll aux =  (1<<j) - v[i];
			auto it = lower_bound(v,v+n,aux);
			int index = it - v;
		
			if(index==i && index+1<n)
				index++;
		
			if(index!=i && v[index]==aux){
				flag=1;
				break;
			}
		
		}

		if(flag){
			check[i]=1;
			cnt++;
		}

	}

	cout << n-cnt << endl;


}

