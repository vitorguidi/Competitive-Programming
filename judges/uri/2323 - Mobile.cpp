#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000000000

vector< vector<int> > nodes;
vector<int> flag;
vector<int> peso;

string ans = "bem";

int dfs(int v){			//atualiza peso dos nodes pra levar em conta ele e tudo abaixo dele

	int tam = nodes[v].size();

	if (tam==0)	return peso[v]=1;	//se nao tem filhos, seu peso acumulado eh 1

	peso[v]+=1;						//atualiza peso dele levando em conta ele mesmo

	for(int i=0;i<tam;i++)	peso[v]+=dfs(nodes[v][i]);	//soma peso de tudo que estiver abaixo dele
	
	return peso[v];

}

void bfs(int v){
	queue<int> fila;
	int tam;
	fila.push(v);
	
	while(!fila.empty()){
		v=fila.front();
		fila.pop();
		tam=nodes[v].size();		//procuro vizinhos abaixo do no atual

		vector<int> cnt;			//armazena o peso dos neighbours

		for(int i=0;i<tam;i++){
			int ngbr=nodes[v][i];

			if(flag[ngbr]==0){
				fila.push(ngbr);		//filho atual
				flag[ngbr]=1;
				cnt.push_back(peso[ngbr]);	//armazzena peso de cada vizinho
			}

		}
		
		if(tam<2)	continue;		//se o vertice nao tem filhos ou tem um soh, n da pra desbalanceara

		for(int i=0;i<tam-1;i++){	
			if(peso[ nodes[v][i] ]!=peso[ nodes[v][i+1] ] )		ans="mal";
		}

	}

}

int main(){

	int n,x,y;
	cin >> n;
	nodes.resize(n+1);
	flag.resize(n+1);
	peso.resize(n+1);

	for(int i=0;i<n;i++){
		cin >> x >> y;
		nodes[y].push_back(x);
	}

	dfs(0);		//atualiza peso (quantidade de nodes abaixo dele mais ele mesmo) dos nodes

	bfs(0);		//procura desbalanceamentos. se achar, muda a string global ans pra 'mal'

	cout << ans << endl;

	return 0;
}
