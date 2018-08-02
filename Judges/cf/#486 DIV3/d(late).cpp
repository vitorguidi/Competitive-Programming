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

bool check(string aux){
    if(aux[0]=='0') return false;
    int x=0;
    int tam= aux.size();
    x+=(aux[tam-1]-'0');
    x+=(aux[tam-2]-'0')*10;
    if(x%25==0) return true;
    return false;
}

int main(){

    string s;
    getline(cin,s);

    int tam= s.size();
    int ans = INF;
    fr(i,tam){
        fr(j,tam){

            if(i==j)    continue;

            string aux = s;
            int cnt=0;

            for(int k=i;k<tam-1;k++){
                swap(aux[k],aux[k+1]);
                cnt++;
            }

            for(int k=j-(j>i);k<tam-2;k++){
                swap(aux[k],aux[k+1]);
                cnt++;
            }

            int x=-1;

            fr(k,tam-2){
                if(aux[k]!='0'){
                    x=k;
                    break;
                }
            }

            for(int k=x;k>0;k--){
                swap(aux[k],aux[k-1]);
                cnt++;
            }

            if(check(aux)){
                if(cnt<ans) ans=cnt;
            }

        }
    }

    if(ans!=INF)    cout << ans << endl;
    else            cout << -1 << endl;

}
