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

int bit[1010][1010]; // vetor que guarda as posições da BIT

void upd(int x, int y, int val){
		
	// percorro as linhas da BIT que representam as linhas desejadas
	for(int i=x;i<1010;i+=i&-i){
		
		// e dentro da BIT que representa as linhas que estou percorrendo
		// uso o mesmo algoritmo para acessar apenas as colunas que me interessam
		for(int j=y;j<1010;j+=j&-j){
			
			// somando o valor de delta a cada uma delas
			bit[i][j]=max(val,bit[i][j]);
		}

	}
}


int query(int x, int y){
		
	// resposta começa com valor zero
	int resp=0;
	
	// percorro as linhas da BIT que representam as linhas desejadas
	for(int i=x;i>0;i-=i&-i){
		
		// e dentro da BIT que representa as linhas que estou percorrendo
		// uso o mesmo algoritmo para somar apenas as colunas que me interessam
		for(int j=y;j>0;j-=j&-j){
			
			// somando o valor de cada uma delas a resp
			resp=max(resp,bit[i][j]);
		}
	}
	
	// por fim, retorno resposta
	return resp;
}

int main(){

	int t;
	cin >> t;

	while(t--){

		int n;
		cin >> n;

		ms(bit,0);

		fr(i,n){
			int x,y;
			cin >> x >>y;
			int val = query(x,y);
			upd(x,y,val+1);
		}

		// frr(i,mxx){
		// 	frr(j,mxy){
		// 		cout << bit[i][j] << " ";
		// 	}
		// 	gnl;
		// }

		cout << query(1000,1000) << endl;

	}

	

}

