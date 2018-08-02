#include "bits/stdc++.h"
using namespace std;

#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define pq priority_queue	
#define vi vector<int>
#define vii vector<pair<int,int>>
#define pq priority_queue
#define fr(i,n)	for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)

#define ms(x, v) memset(x, v, sizeof x)
#define all(x)	x.begin(),x.end()

#define dbg(x) cout << #x << " = " << x << endl
#define olar() cout << "olaarr" << endl
#define gnl cout << endl;


const int MAXN = 100100;
const int INF = 0x3f3f3f3f;

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n,k;
int segtree[4*MAXN],v[MAXN];
char op;

void build(int node, int ini, int end){
	
	if(ini==end)	segtree[node]=v[ini];
	
	else{
		int mid	= (ini+end)/2;
		
		build(2*node,ini,mid);		//constroi os filhos
		build(2*node+1,mid+1,end);

		segtree[node]=segtree[2*node] * segtree[2*node+1];	//compoe os filhos pra atualizar no, estou interessado no produto
	}

}

void update(int node, int ini, int end, int idx, int val){

	if(ini==end){					//idx= id do elemento que eu qro trocar em v, val eh o novo valor (1,0 ou -1)
		v[idx]=val;					//se chego ao conjunto de 1 elemento, simplesmente atualizo valor
		segtree[node]=val;
	}

	else{
		int mid = (ini+end)/2;
		
		if(ini<=idx && idx<=mid)	update(2*node,ini,mid,idx,val);			//se o cara estiver no filho da esquerda, atualizo filho esquerda
		else						update(2*node+1,mid+1,end,idx,val);		//caso contrario, vou pra direita

		segtree[node]=segtree[2*node] * segtree[2*node+1];	//estou interessado em produtos nos intervalos

	}

}


int query(int node, int ini, int end, int a, int b){	//procura o intervalo [a,b], e o noh eh o intervalo [ini,end]

	if (a>end || b<ini)		return 1;		//range invalida, [ini,end] tem elementos fora de [a,b], q eh o intervalo original

	if(a<=ini && end<=b)	return segtree[node];	//range contida no intervalo de interesse, retorna resultado

	int mid=(ini+end)/2;
	int p1 = query(2*node,ini,mid,a,b);				//se estiver parcialmente contido, continuo buscando e concateno os resultados
	int p2 = query(2*node+1,mid+1,end,a,b);

	return p1*p2;

}

int main(){

    while( cin >> n >> k ){
	   
	    ms(segtree,0);

		frr(i,n){
			cin >> v[i];
			if(v[i]>0)	v[i]=1;
			if(v[i]<0)	v[i]=-1;
		}

		build(1,1,n);

		frr(i,k){
			
			int x,y;
			cin >> op >> x >> y;

			if(op=='C'){
				if(y>0)	y=1;
				if(y<0)	y=-1;
				update(1,1,n,x,y);
			}
			else{
				int w = query(1,1,n,x,y);
				if(w==0)	cout << 0;
				if(w<0)		cout << "-";
				if(w>0)		cout << "+";
			}	
						
		}
		gnl;
    
	}
    
}


