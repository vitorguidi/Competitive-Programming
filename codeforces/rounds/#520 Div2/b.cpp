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
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int check[1100100];
vii d;

int main(){
    
	fastio;

	int n; cin >> n;

	for(int i=2;i<=1000000;i++){
		if(!check[i]){

			check[i]=1;
			
			int cnt = 0;
			while(n%i==0){
				cnt++;
				n/=i;
			}
			if(cnt)
				d.pb(mp(i,cnt));
			
			for(int j=i;j<=1000000;j+=i)
				check[j]=1;
		
		}
	}

	if(n!=1)
		d.pb({n,1});

	int mx = 0;

	for(auto x : d)
		mx=max(mx,x.snd);

	int target = 0;

	while( (1<<target) < mx )
		target++;

	ll ans = 1;
	bool flag = false;
	int target2 = 1<<target;

	for(auto x : d){
		ans*=x.fst;
		if(x.snd<target2)
			flag=true;
	}

	int num = flag + target;

	cout << ans << " " << num << endl;

}

