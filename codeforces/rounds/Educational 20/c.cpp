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

int main(){
    

	ll n,k;
	scanf("%I64d %I64d",&n,&k);

	ll minimo_aceitavel = ((k)*(k+1ll))/2ll;

	if(n<minimo_aceitavel){
		printf("-1\n");
		return 0;
	}

	long double teste = ((long double)(k)*(long double)(k+1ll))/(long double)(2ll);
	if(teste>(long double)(n)){
		printf("-1\n");
		return 0;		
	}

	ll gcd=1;
	ll somatoria=n;
	ll soma_pa=(k*(k+1ll))/2ll;


	for(ll i=1;i*i<=n;i++){

		if(n%i)	continue;

		ll soma_aux = n/i;

		if(soma_aux>=soma_pa && i>gcd){
			gcd=i;
			somatoria=soma_aux;
		}
		
		if(n/i==i)	continue;

		soma_aux=n/(n/i);

		if(soma_aux>=soma_pa && n/i>gcd){
			gcd=n/i;
			somatoria=soma_aux;
		}

	}

	somatoria-=minimo_aceitavel;

	frr(i,k){
		ll val;
		if(i!=k)
			val=gcd*i;
		else
			val=gcd*(i+somatoria);
		printf("%I64d ",val);
	}
	printf("\n");

}

