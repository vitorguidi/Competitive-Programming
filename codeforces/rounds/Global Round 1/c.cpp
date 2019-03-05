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

void go(int x){

	ll best = 0;
	int who = 0;
	
	// for(int i=1;i<x;i++){
	// 	int aux = __gcd(x^i,x&i);
	// 	if(best<aux)	who=i;
	// 	best=max<ll>(best,aux);
	// }

	ll p = 32 - __builtin_clz(x);
	ll coiso = 1ll<<p;
	coiso--;

	if(x!=coiso){
		//if(coiso!=best)	cout << "errow" << endl;
		cout << coiso << endl;
		return;
	}

	// dbg(x);
	// dbg(coiso);

	int melhor=0;
	int quem = 0;
	
	for(ll i=1;i*i<x;i++){
	
		if(x%i)	continue;

		ll cara = i;
		int aux = __gcd(cara^x,cara&x);
		if(aux>melhor)	quem=cara;
		melhor = max<ll>( melhor,aux );
		
		cara = x/i;
		if(cara==x)	continue;

		aux = __gcd(cara^x,cara&x);
		if(aux>melhor)	quem=cara;
		melhor = max<ll>( melhor,aux );

	}

	cout << melhor << endl;

	// if(best==melhor)	return;

	// dbg(x);
	// dbg(best);
	// dbg(who);
	// dbg(melhor);
	// dbg(quem);
	// gnl;
}

int main(){
    
	fastio;

	int q; cin >> q;
	while(q--){
		int x;
		cin >> x;
		go(x);
	}

}