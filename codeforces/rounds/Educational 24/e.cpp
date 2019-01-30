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

ll v[100100];
ll acum[100100][40];

int crivo[50000];
int fatora[40];

vi divisors;

bool check(int ini, int end, int i){
	return acum[end][i]-acum[ini-1][i] >=fatora[i];
}

int main(){
    
	fastio;

	ll n,k;
	cin >> n >> k;

	if(k==1){
		cout << (n*(n+1ll))/2ll << endl;
		return 0;
	}

	ll bkp=k;

	int clk=0;

	for(ll i=2;i*i<=(ll)1e9;i++){

		if(!crivo[i]){
		
			crivo[i]=1;
		
			if(k%i==0){
				divisors.pb(i);			
				while(k%i==0)
					k/=i;
			}
		
			for(ll j=i;j*j<=(int)1e9;j+=i)
				crivo[j]=1;

		}

	}

	if(k!=1)
		divisors.pb(k);
	
	k=bkp;


	frr(i,n)
		cin >> v[i];

	int len = divisors.size();

	fr(i,len){
		int cnt =0;
		while(k%divisors[i]==0){
			cnt++;
			k/=divisors[i];
		}
		fatora[i]=cnt;
	}


	fr(i,len){

		frr(j,n){

			int cnt =0;
			while(v[j]%divisors[i]==0){
				cnt++;
				v[j]/=divisors[i];
			}

			acum[j][i]=cnt+acum[j-1][i];

		}

	}

	ll ini=1;
	ll end=1;
	ll ans = 0;

	while(ini<=n){


		while(ini>end)	end++;

		for(int i=0;i<len;i++)
			while( !check(ini,end,i) && end+1<=n)
				end++;

		bool flag=true;

		fr(i,len)	flag&=check(ini,end,i);
			
		if(flag)	ans+=n-end+1ll;

		ini++;

	}

	cout << ans << endl;

}

