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

int a,n,m,umb[2020],seg[2020];
int memo[2020][2020];

int solve(int ind, int ind2){     //ind eh onde estou, ind2 eh de onde veio o gc que estou agora. ind2=2001 eh sem gc
                                
    if(ind==a)  return 0;   

    int &pdm=memo[ind][ind2];
    if(pdm!=-1) return pdm;

    int ans=INF;

    if(umb[ind]!=INF)           //se tem um guarda chuva na posicao, testo pegar ele
        ans=min(ans,umb[ind]+solve(ind+1,ind));

    if(ind2!=2001)              //se eu estou carregando um gc de antes, testo continuar c ele
        ans=min(ans,umb[ind2]+solve(ind+1,ind2));

    if( !(seg[ind]==seg[ind+1] && seg[ind] && seg[ind+1]) )   //se a posicao atual e a proxima na pertenem a um mesmo segmento c chuva
        ans=min(ans,solve(ind+1,2001));

    return pdm=ans;

}



int main(){

    cin >> a >> n >> m;

    frr(i,n){
        int x,y;
        cin >> x >> y;
        for(int j=x;j<=y;j++) seg[j]=i;
    }

    ms(umb,INF);

    fr(i,m){
        int x,y;
        cin >> x >> y;
        umb[x]=min(y,umb[x]);
    }

    ms(memo,-1);
    
    int ans=solve(0,2001);

    if(ans==INF)    cout << -1 << endl;
    else            cout << ans << endl;

}
