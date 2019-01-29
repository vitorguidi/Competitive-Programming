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
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

int euler[1100100];
map<int,int> primos;

int main(){

	fastio;
	ll n,k;
	cin >> n >> k;
	
	for(int i=2;i<=1000000;i++){
		if(!euler[i]){
			euler[i]=i;
			for(int j=i;j<=1000000;j+=i)
				euler[j]=i;
		}
	}

	frr(i,n){
		ll x; cin >> x;
		
		while(x!=1){
		
			int cnt = 0;
			ll cara = euler[x];
			
			while(x%cara==0){
				cnt++;
				x/=cara;
			}
		
			primos[cara]=max(primos[cara],cnt);
		
		}
	}

	bool flag = true;

	while(k!=1){

		int cnt = 0;
		ll cara = euler[k];

		while(k%cara==0){
			cnt++;
			k/=cara;
		}

		if(primos[cara]<cnt)
			flag=false;

	}

	if(flag)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

}
