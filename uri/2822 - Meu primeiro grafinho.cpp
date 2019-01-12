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
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll; 

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

ll v[200100];
ll bit_sum[200100],bit_freq[200200];
multiset<ll> caras;

void update(int ind, ll val, int id){

	ll* bit;
	if(id==1)	bit=bit_sum;
	else		bit=bit_freq;

	for(int i=ind;i<200100;i+=i&-i)
		bit[i]+=val;

}

ll query(int ind, int id){
	
	ll* bit;
	if(id==1)	bit=bit_sum;
	else		bit=bit_freq;

	ll ans = 0;

	for(int i=ind;i>0;i-=i&-i)
		ans+=bit[i];

	return ans;


}

void solve(){

	ll n,q; cin >> n >> q;

	fr(i,200100)
		bit_sum[i]=bit_freq[i]=0;
	caras.clear();

	frr(i,n){

		v[i]=i;
		
		update(v[i],1,2);		//incrementa frequencia do valor
		update(v[i],v[i],1);	//incrementa soma acumulada na regiao
		
		caras.insert(v[i]);		//bota no multiset		

	}

	fr(i,q){

		int op; cin >> op;
		
		if(op==1){

			ll i,k;
			cin >> i >> k;

			if(n==1 | n==0)	continue;

			auto it = caras.find(v[i]);		//tira o cara do set e bota o valor novo
			caras.erase(it); 
			caras.insert(k);

			update(v[i],-1ll,2);			//decrementa frequencia do valor velho
			update(k,1ll,2);				//incrementa frequencia do valor novo

			update(v[i],-1ll*v[i],1);		//decrementa soma do cara velho
			update(k,k,1);					//incrementa soma do cara novo

			v[i]=k;


		}

		else{

			if(n==1 | n==0){
				cout << 0 << endl;
				continue;
			}

			ll mn = *caras.begin();		//maior label de node
			ll mx = *caras.rbegin();		///menor label de node

			ll meio = (mn+mx)/2ll;		//media

			ll to_max = query(meio,2);	//quantos tem ate a media
			ll to_min = n-to_max;		//quantos tem acima da media

			ll ans = 0;

			ll acum_down = query(meio,1);			//soma dos pesos dos nos <=media
			ll acum_up = query(n,1) - acum_down;	//soma dos pesos dos nos acima da media
		
			ans+= abs<ll>( to_max*mx - acum_down );		//coloca todos <=media com o maximo
			ans+= abs<ll>( to_min*mn - acum_up );		//colodca todos >media com o minimo

			ans-=abs<ll>(mx-mn);						//contei a areas mn,mx duas vezes, desconto

			cout << ans << endl;

		}

	}

}

int main(){

	fastio;

	int t; cin  >> t;
	while(t--)	solve();

}