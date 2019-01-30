#include <iostream>
#include <set>
using namespace std;

#define MAXN 100100

int n,m;
int q,a,b;
int pts[MAXN],gld[MAXN],peso[MAXN];

int find(int x){
	if(gld[x]==x)	return x;

	return gld[x]=find(gld[x]);
}

void join(int x,int y){
	x=find(x);
	y=find(y);

	if(x==y)	return;

	if(peso[x]>=peso[y]){	//agrego o de menor peso ao de maior peso
		gld[y]=x;			//guilda com menos gente eh anexada pela guilda de mais
		pts[x]+=pts[y];		//atualiza pontos da nova guilda
		if(peso[x]==peso[y])	peso[x]++;
	}

	if(peso[y]>peso[x]){
		gld[x]=y;			//guilda com menos gente eh anexada pela guilda de mais	
		pts[y]+=pts[x];		//atualiza ptos da nova guilda
	}

	return;
}


void game(){

	int w_r=0;		//wins do rafael
	int gr;			//guilda do rafael
	

	for(int i=1;i<=n;i++){
		cin >> pts[i];		//pontos do player
		gld[i]=i;			//guilda a qual o player pertence (guarda o index do lider da guilda)
		peso[i]=1;			//guarda a quantidade de membros da guilda, inicializa como 1
	}


	for(int i=0;i<m;i++){
		cin >> q >> a >> b;

		a=find(a);
		b=find(b);
		gr=find(1);

		if(q==1)	join(a,b);
		if(q==2){
			if(a==gr && pts[a]>pts[b])	w_r++;
			if(b==gr && pts[b]>pts[a])	w_r++;
		}

	}

	cout << w_r << endl;

	return;

}


int main(){

	n=m=-1;

	ios::sync_with_stdio(false);
	cin.tie(0);

	while(n!=0 && m!=0){
		cin >> n >> m;

		if(n!=0 && m!=0){
			game();
		}

	}

	return 0;

}