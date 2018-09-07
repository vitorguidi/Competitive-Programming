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
#define olar cout << "pira" << endl

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

ll aux = 1300031;
ll memo[2000000];

ll fat(ll x){
	if(x==1)
		return 1;
	if(memo[x]!=-1)
		return memo[x];
	return memo[x]=(x*fat(x-1))%aux;
}

ll fastxp(ll a, ll b){

	ll ans=1;
	while(b){
		if(b%2)
			ans=(ans*a)%aux;
		a=a*a;
		a=a%aux;
		b=b/2;
	}
	return ans;

}

ll comb(ll a, ll b){

	ll cima = fat(a);
	
	ll baixo1=fat(b);
	baixo1=fastxp(baixo1,aux-2);
	
	ll baixo2=fat(a-b);
	baixo2=fastxp(baixo2,aux-2);

	cima=cima*baixo1;
	cima=cima%aux;
	cima=cima*baixo2;
	cima=cima%aux;

	return cima;

}

int main(){

	    
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ms(memo,-1);
	int t; cin >> t;
	while(t--){
		ll x,y;
		cin >> x >> y;
		cout << comb(x+y-1,x-1) << endl;
	}	


}