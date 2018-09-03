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

int main(){
    
    int n,seq[100100],dif[100100];
    int dif2[100100];

    cin >> n;

    if(n==1 || n==2){
        cout << 0 << endl;
        return 0;
    }

    fr(i,n)    cin >> seq[i];

    int ans=INF;

    for(int dx=-1;dx<=1;dx++){
        for(int dy=-1;dy<=1;dy++){
            
            int a = seq[0]+dx;          //primeiro termo artificial
            int b = seq[1]+dy;          //segundo termo atificial
            int r = b-a;                //razao da PA

            int aux[100100];
            fr(i,n) aux[i]=seq[i];
            aux[0]=a;
            aux[1]=b;

            int cnt=abs(dx)+abs(dy);    //conta alteracoes iniciais na seq
            for(int i=2;i<n;i++){       //itera resto da sequencia
               
                int flag=0;

                for(int j=-1;j<=1;j++){
                    if(aux[i]+j-aux[i-1]==r){
                        cnt+=abs(j);
                        aux[i]=aux[i]+j;
                        flag=1;
                    }
                }

                if(flag==0){
                    cnt=INF;
                    break;
                }

            }
            ans=min(ans,cnt);

        }
    }

    if(ans==INF)    cout << -1 << endl;
    else            cout << ans << endl;
    

}

