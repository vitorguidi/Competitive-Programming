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

int n,tam[330],eq[330][330],pd[330][330];
vector<string> palavras;

int main(){

	string s;
	cin >> n;

	int total_length = n-1;		//variavel que guarda o tamanho total do texto. inicio com quantidade de espacos
	
	fr(i,n){
		cin >> s;
		palavras.pb(s);
		total_length+=s.size();		//coloca o tamanho da palavra lida no tamanho total do texto
	}

	fr(i,n){
		fr(j,n){
			if(palavras[i]==palavras[j])		//matriz que memoriza se as palavras i e j sao iguais
				eq[i][j]=eq[j][i]=1;			//foi inicializado como zero entao so marco os positivos
		}
	}

	for(int i=n-1;i>=0;i--){					//pd[i][j] = k  ---> o maior segmento igual começando uma palavra em palavra[i] e outra palavra em palavras[j]
		for(int j=n-1;j>=0;j--){				//eh igual a k. estou gerando essa tabela pra saber maior segmento possivel nos intervalos e depois brutar todos
												//os tamanos possivels de segmentos e ver a melhor resposta			
			if(! eq[i][j] )
				continue;

			if(i==n-1 || j==n-1)				//nao tem mais palavra depos de palavras[n-1]. se deu math, soh pode ser 1 o tamanho do segmento
				pd[i][j]=1;
			else
				pd[i][j]=1+pd[i+1][j+1];		//se as palavras em i e j sao iguai, o maior segmento possivel partindo de i,j eh o melhor
												//segmento partindo de i+1,j+1 somado a um (mathc atual)
		}
	}



	int ans=total_length;

	for(int i=0;i<n;i++){						//bruto todas as posicoes iniciais
		
		int sum=0;								//guarda o tamanho do segmento que vou substituir, comecando a construcao do segmento a partir de i		

		for(int j=0; i+j<n;j++){				//bruto todos os possiveis tamanhos de segmento a partir da tal posicao inicial

			sum+=palavras[i+j].size();			//adiciona o tamanho da palavra que pertence a parte da esquerda no tamanho do segmento

			int cnt=1;							//defini que vou substituir com base no segmento i,j , entao ao menos uma substituicao ocorre

			for(int pos=i+j+1; pos < n; pos++ ){	//comeco as substituicoes a partir de palavras[i+j+1] ==> posicao seguintte a ultima word do segmento
 				
				if(pd[i][pos]>j){				//pd[i][pos] = j : numero maximo de elementos no segmento a substituir começando de i,pos
					cnt++;						//numero de elementos eh j+1 ==> pd[i][pos]>=j+1 ==> pd[i][pos]>j		
					pos+=j;
				}

			}

			
			int cur = total_length - sum*cnt - (j-1)*cnt + j*cnt;	//sum*cnt eh a quantidade de palavras na abreviacao x num de abreviacoes
																	//(j-1)*cnt eh a quantidade de espacos que somem	
			

			if(cur<ans && cnt>1)		//o enunciaod pede ao menos dois segmentos pra abreviar, entao cnt>1 eh uma necessidade
				ans=cur;				//j*cnt eh quantidade de iniciais adicionadas ao texto aps abreviacao

		}

											
	}

	cout << ans << endl;

}

