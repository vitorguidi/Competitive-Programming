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
#define pq priority_queue
#define grtp greater< pair<int,int> >

#define gnl cout << endl
#define olar cout << "olar" << endl
#define gottagofast ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const double pi = 3.141592653589793238462643383279502884L;

double vol[10010];
double epsilon=1e-6;		//margem de precisao
int n,f;

bool check(double size){

	int ini=0,cnt=0;		//ini eh a torta atual, cnt eh a quantidade de pedacos de tamanho size q consegui faer
	double atual;			//vlume atual da torta
	
	while(ini<n){			//enquanto tenho tortas

		atual=vol[ini];
		
		while(atual-size>=0.0){		//enquanto da pra pegar pedaço da torta, incremento  contador e diminuo a torta
			cnt++;
			atual-=size;
		}

		ini++;						//passo pra proxima torta
	}

	if(cnt>=f+1)					//se da pra dar pedaço pro cara e pros f amigos, eh vdd
		return true;				//senao cagou
	return false;

}

double bins(double ini, double end, double prev){
	
	double mid=(ini+end)/2.0;			//novo valor que testo como solucao
	
	if(!check(mid))
		return bins(ini,mid,mid);		//se o valor nao servir, busco um menor

	else{								//se servir, verifico se estou na margem de precisao e retorno ele
		if(abs(prev-mid)<epsilon)
			return mid;
		return bins(mid,end,mid);		//se ainda da pra melhorar continuo a busca
	}
}

int main(){ 

	int t;
	cin >> t;
	cout << fixed << setprecision(4);
	while(t--){
		cin >> n >> f;
		fr(i,n){
			double x;
			cin >> x;
			vol[i]=pi*x*x;
		}
		cout << bins(0,1e15,1e15) << endl;
	}


}
