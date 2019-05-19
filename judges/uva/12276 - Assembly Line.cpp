#include "bits/stdc++.h"
using namespace std;

#define pb push_back

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()
#define fst first
#define snd second
#define endl "\n"

#define gnl cout << "\n"
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) 

typedef vector<int> vi;
typedef vector<pair<int,int>> vii;

const int INF = 0x3f3f3f3f;

int n;
int sz;
int clk;

int cost[30][30];
int dp[220][220][26];
int symb[26];

vii possibilities[26];

char to[220],x[220];
char frase[220];

void go(){

    fr(i,26)
        possibilities[i].clear();

    ms(cost, INF);

    fr(i,n){
        scanf("%s" ,x);
        symb[i]=x[0]-'a';
    }

    fr(i,n){
        fr(j,n){

            int l = symb[i];
            int r = symb[j];

            scanf("%d-%s",&cost[l][r], to);
            possibilities[to[0]-'a'].pb({l,r});
        }
    }

    int q; scanf("%d",&q);


    while(q--){

        scanf("%s",frase);

        int ans = INF;
        int cara = 0;

        int len = strlen(frase);
        
        for(int i=0;i<len;i++)
            for(int j=i;j<len;j++)
                for(int k=0;k<n;k++)
                    dp[i][j][symb[k]] = (i==j && symb[k]==frase[i]-'a'? 0 : INF);


        for(int tam=2;tam<=len;tam++)               //itera pelo ponto inicial  
            for(int i=0;i+tam-1<len;i++){                 //ordem crescente de tamanho

                int from = i;
                int to = i + tam -1;
                
                for(int letra=0;letra<n;letra++){       //tenta fazer o intervalo [from][mid] com a letra fixada

                    int tgt = symb[letra];
                    int& pdm = dp[from][to][tgt];

                    for(auto x : possibilities[tgt])
                        for(int mid = from; mid<to; mid++)
                            pdm = min(pdm, cost[x.fst][x.snd] + dp[from][mid][x.fst] + dp[mid+1][to][x.snd]);
                
                }

            }

        for(int i=0;i<n;i++){
            int quem = symb[i];
            if(ans>dp[0][len-1][quem] ){
                ans = dp[0][len-1][quem];
                cara = quem;
            }
        }

        printf("%d-%c\n",ans,'a'+cara);

    }

}

int main(){

    int clk = 0;
    while(scanf("%d",&n)){
        if(!n)  break;
        if(clk++!=0)    printf("\n");
        go();
    }
}