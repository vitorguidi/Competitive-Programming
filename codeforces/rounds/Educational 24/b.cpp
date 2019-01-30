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

int v[110];
int jump[110];
int pos[110];
int taken[110];

int main(){
    
	fastio;

	int n,m;
	cin >> n >> m;
	
	frr(i,m){
		cin >> v[i];	//le lider da brincadeira no momento i
		v[i]--;			//vamos indexar de zero pra fazer modulo facil
	}

	ms(jump,-1);		//inicialmente nenhuma das criancas tem um ai definido

	frr(i,m-1){

		int aux=v[i+1]-v[i];		
		
		if(aux<0)		aux+=n;
		if(!aux)		aux=n;		//define o pulo da crianca

		
		if( jump[ v[i] ] == -1 ){		//se o pulo nao ta definido,, defino agora
			jump[ v[i] ] = aux;
			taken[ aux ]++;
		}

		else if( jump[v[i]] != aux){	//se o pulo esta definido e tem outro valor, cagou
			cout << -1 << endl;
			return 0;
		}

	}

	fr(i,n){
		if(taken[i]>1){
			cout << -1 << endl;
			return 0;
		}
	}


	fr(i,n){
		if(jump[i]==-1){				//lida com o fato d quando falta numeros da permutacao
										//qlqr indice faltando serve
			frr(j,n){
				if(!taken[j]){
					
					jump[i]=j;
					taken[j]=1;
					break;
				
				}
			}
			
		}
	}

	fr(i,n){
		if(jump[i]==-1){
			cout << -1 << endl;
			return 0;
		}
	}

	fr(i,n)	cout << jump[i] << " ";
	gnl;

}

