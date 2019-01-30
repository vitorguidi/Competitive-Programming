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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const ll mod = 23*28*33;

int tot(int x){
	switch(x){
		case 33: return 20; 
		case 28: return 12;
		case 23: return 22;
	}
}

ll fastxp(ll a,ll x){
	if(x==1)return a;
	if(x==0)return 1;
	return (((x%2)?a:1)*fastxp((a*a)%mod,x/2))%mod;
}

ll invmod(int x, int val){
	return fastxp( x , tot(val)-1 );
}

int main(){
    
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int p,e,i,d;
	int cnt=0;
	
	while( (cin >> p >> e >> i >> d) && i!=-1 ){
		
		cnt++;
		
		p%=23;
		e%=28;
		i%=33;


		ll x1= (mod/23)*p*invmod(mod/23,23);
		x1%=mod;

		ll x2 = (mod/28)*e*invmod(mod/28,28);
		x2%=mod;
		
		ll x3 = (mod/33)*i*invmod(mod/33,33);
		x3%=mod;

		ll grandao = x1+x2+x3-d;
		grandao += 21252;
        grandao %= 21252;

        if(!grandao)
        	grandao+=mod;

		cout << "Case " << cnt << ": the next triple peak occurs in " << grandao << " days." << endl;

	}

}

