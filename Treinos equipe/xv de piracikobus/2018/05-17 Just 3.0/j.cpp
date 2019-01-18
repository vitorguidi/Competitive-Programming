#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define pq priority_queue
#define grtp greater< pair<int,int> >

#define gnl cout << endl
#define olar cout << "olar" << endl

typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef vector<int,int> vi;
typedef vector< pair<int,int> > vii;
typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int cards[1010];
int n,memo[1010][1010][2];		//memo guarda a pontuacao do ibraheem

//p=0 ibraheem, p=1 hussam, p0 joga primeiro

int solve(int i, int j, int p){
    
    int &pdm=memo[i][j][p];

    if(i>j)     return pdm=0;		//se acabaram as cartas, retorna zero (base)
    if(pdm!=-1) return pdm;			//because PD

    if(p==0)    return pdm=max(cards[i]+ solve(i+1,j,1),cards[j]+solve(i,j-1,1) );	//ibraheem pega a melhor possivel pra melhorar seus pontos		
    if(p==1)    return pdm=min( solve(i+1,j,0), solve(i,j-1,0) );					//ibraheem pega a carta que minimiza a pontuação do hussam na prox rodada

}

int main(){

	int t;
	scanf("%d",&t);
	frr(i,t){
		int n,sum=0;
		scanf("%d",&n);
		frr(j,n){
			scanf("%d",&cards[j]);
			sum+=cards[j];
		}
        ms(memo,-1);
		solve(1,n,0);
        printf("%d\n",2*memo[1][n][0]-sum);		//pontos do ibraheem = memo, pontos do hussam = sum - memo, entao x-y = 2*memo-sum =)
	}		

}
