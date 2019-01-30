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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MAXN = 1e7+5e6+10;


int freq[MAXN],primes[MAXN];
int v[300300];

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;

	int g=0;
	
	frr(i,n){
		cin >> v[i];
		g=__gcd(g,v[i]);
	}

	int cnt=0;

	frr(i,n){
		v[i]/=g;
		if(v[i]==1)	cnt++;
	}

	if(cnt==n){
		cout << -1 << endl;
		return 0;
	}

	for(int i=2;i<=MAXN;i++){
		
		if(!primes[i]){
			for(int j=i;j<=MAXN;j+=i)
				if(!primes[j])
					primes[j]=i;
		}
	
	}

	int ans = 0;

	frr(i,n){

		int val = v[i];
		
		while(val!=1){
			
			int div = primes[val];
			freq[div]++;

			ans=max(ans,freq[div]);
		
			while(val%div==0)
				val/=primes[val];
		}

	}

	cout << n-ans << endl;

}