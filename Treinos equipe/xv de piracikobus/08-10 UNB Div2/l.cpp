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
#define otp(x) cout << x << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int maxn = 1e7+9;

int primes[maxn],n;
vii memo;
vi ans;
map<int,int> check;

ll fastxp(ll a, ll exp){		//fastxp normal

	ll aux = 1;

	while(exp){

		if(exp%2)
			aux=a*aux;
	
		a=a*a;
		exp=exp/2;
	
	}

	return aux;

}

ll euler(ll base, ll exp){		//calcula totiente de p^k, com p primo
	
	if(exp==0ll)
		return 1ll;
	
	return (base-1)*fastxp(base,exp-1);

}

void solve(int ind, ll acum, ll num){	//indice = indice do primo no vetor memo, acum = totiente parcial acumulado, num = numero parcial acumulado

	if(acum==n && !check[num]){		//se eu tenho minha resposta, adiciono ela na lista (desde que nao tenha visto esse numero antes)
		ans.pb(num);
		check[num]=1;
	}
		
	if(ind<0)	return;

	ll primo = memo[ind].fst;	//pega um primo q eh divisor do n
	ll exp = memo[ind].snd;		//e todas as potencias desse primo, de 0 a exp, tbm sao divisoras de n
	
	for(ll i=0;i<=exp;i++){		//bruto  todas as possibilidades de divisores

		if( n % (acum*euler(primo,i)) != 0)	//corto o backtracking aqui, caso meu totiente parcial nao seja divisor do n desejado
			continue;

		solve( ind-1, acum*euler(primo,i), num*fastxp(primo,i) );

	}
	
}

int main(){

	cin >> n;

	for(ll i=2;i<=n+1;i++){		//pega todos os primos ate n+1

		if(!primes[i]){

			for(int j=i;j<=n+1;j+=i)		//crivo boladao que pega alem dos primos, todas as potencias do primo q sao divisoras de n
				primes[j]=1;

			ll exp = 0;

			while(true){					//ve qual a maior potencia do primo que divide n, e guarda o primo junto com a potencia
				ll tot = euler(i,exp+1);
				if(n%tot!=0)
					break;
				exp++;
			}

			if(exp)
				memo.pb({i,exp});

		}

	}

	solve(memo.size()-1,1,1);
	
	cout << ans.size() << endl;

	fr(i,ans.size())
		cout << ans[i] << " ";

	if(ans.size())
		gnl;


}