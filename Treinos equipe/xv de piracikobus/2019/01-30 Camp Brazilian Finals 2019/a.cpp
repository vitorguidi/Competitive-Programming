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

int main(){
	int x;
	int v[112345];
	char c;

	bool ok=1;
	while(ok){
		c=0;
		v[0]=1;
		int i=1;
		while(c!='\n' && ok){
			if(scanf("%d",&v[i])==EOF)
				ok=0;
			if(scanf("%c",&c)==EOF)
				ok=0;

			i++;
		}

		int sum;
		int mx,mn;
		sum=0;mn=0;mx=0;
		ll ans = 0;
		frr(j,i-1){
			
			sum+=v[j];
			ans=max<ll>(ans,sum);
			if(sum<0)	sum=0;
		}
		if(ok){
			printf("%lld\n",ans);
		}


	}




}
