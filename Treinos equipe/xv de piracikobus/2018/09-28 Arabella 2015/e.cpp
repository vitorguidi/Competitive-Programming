#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;
const ll mod=1e9+7;

int bit[20000];

void update(int ind, int val){
	for(int i=ind;i<20000;i+=i&-i)
		bit[i]+=val;
}

int query(int ind){
	int ans = 0;
	for(int i=ind;i>0;i-=i&-i)
		ans+=bit[i];
	return ans;
}

int main(){

	int t; cin >> t;
	while(t--){

		ms(bit,0);
		
		int n; cin >> n;
		
		int ans = 0;

		fr(i,n){
			
			int x; cin >> x;
			
			int left = -32+x;
			int right = 32+x;
			
			right--;	//int aberto

			left=max(left,0);

			ans+= query(right)- query(left);
			update(x,1);

		}

		cout << ans << endl;
	
	}

}