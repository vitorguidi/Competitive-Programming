//isso passa o problema https://codeforces.com/gym/101908/problem/J (subreg 2018)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define fr(i,n)	for(int i=0;i<n;i++)

int n,k;
int x[220],y[220];

double memo[220][1<<12];
double dist[220][220];

double calc(int i, int j){
	long long int dx = x[i]-x[j];
	long long int dy = y[i]-y[j];
	return sqrt( (double)(dx*dx+dy*dy));
}

double min(double a, double b){
	if (a<b)	return a;
	return b;
}

int main(){
 
	scanf("%d %d",&n,&k);

	fr(i,n)
		scanf("%d %d",&x[i],&y[i]);
 
	fr(i,n)
		fr(j,n)
			dist[i][j] = dist[j][i] = calc(i,j);

	double ans = 1e18;

	fr(i,n){
		fr(j,1<<k){

			memo[i][j]=1e18;
			
			if(__builtin_popcount(j)==1){
				int ind = 31 - __builtin_clz(j);
				memo[i][j] = dist[i][ind];
			}

		}
	}

	//itera por todas as masks da menor pra maior
	for(int mask=1;mask<(1<<k);mask++){

		//itera por todos os pivot vertex pra fazer o /\
		//so pode os nao capitais (se nao ta na restricao do problema, comeca em 0)

		for(int i=k;i<n;i++){

			//itera por todas as submasks
			//assume q todas as submasks menores estao corretamente calculadas
			for(int j=(mask-1)&mask;j>0;j=(j-1)&mask){

				int mask1 = j;
				int mask2 = j^mask;

				memo[i][mask] = min(memo[i][mask], memo[i][mask1] + memo[i][mask2]);
			
			}

		}
		
		//ve se tem vantagem usar outro no intermediaro como raiz e extender
		for(int i=0;i<n;i++)
			for(int j=k;j<n;j++)
				memo[i][mask] = min( memo[i][mask], dist[i][j] + memo[j][mask] );

	}

	fr(i,n)
		ans = min( ans,  memo[i][(1<<k)-1]);

	printf("%.5f\n",ans);

}