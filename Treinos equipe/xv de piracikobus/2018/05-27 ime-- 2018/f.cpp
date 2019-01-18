#include "bits/stdc++.h"
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
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

vi nodes[100100];
int pai[100100],memo[100100][2];

int pd(int v, int tag){

    int tam = nodes[v].size();
    
    if(tam==1){ //caso base da folha
        if(tag==0)  return 1;
        return 0;
    }

    int &pdm=memo[v][tag];
    if(pdm!=-1) return pdm;

    int pinta=1;
    int pula=0;

    fr(i,tam){
        int filho = nodes[v][i];
   
        if(pai[filho]==-1)  pai[filho]=v;
        if(filho==pai[v])   continue;

        if(tag==1)  pula+=pd(filho,0);
        else{
            pula+=pd(filho,0);
            pinta+=pd(filho,1);
        }
    }

    if(tag==1)  return pdm= pula;
    return pdm=max(pula,pinta);
    

}

int main(){

    int n,m;
    scanf("%d %d",&n,&m);

    fr(i,m){
        int x,y;
        scanf("%d %d",&x,&y);
        nodes[x].pb(y);
        nodes[y].pb(x);
    }

    ms(memo,-1);
    frr(i,n)    pai[i]=-1;
    pai[1]=1;
    
    cout << pd(1,0) << endl;

}
