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
#define pira cout << "pira" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

ll bit[200200];
ll v[100100];

int MAXN=200200;

void upd(int ind, ll val){
	for(int i=ind;i<MAXN;i+=i&-i)
		bit[i]+=val;
}

ll query(int ind){
	ll ans = 0;
	for(int i=ind;i>0;i-=i&-i)
		ans+=bit[i];
	return ans;
}

int main(){
    
	int n,k,r;
	cin >> n >> k >> r;

	frr(i,k){
		int x;
		cin >> x;
		v[x]=1;
		upd(x,1);
	}

	ll ans = 0;

	for(int i=1;i<=n-r+1;i++){

		ll acum = query(i+r-1);
		acum-=query(i-1);

		
		if(acum<2){
		
			ll falta = 2-acum;

			while(falta){

				if(!v[i+r-1]){
					upd(i+r-1,1);
					v[i+r-1]=1;
					falta--;
					ans++;
				}

				else{
					upd(i+r-2,1);
					v[i+r-2]=1;
					falta--;
					ans++;
				}

			}
		
		}

	}

	// frr(i,n){
	// 	cout << i << " - " << query(i)-query(i-1) << endl;
	// }

	cout << ans << endl;

}

	