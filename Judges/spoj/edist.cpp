#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl

#define gnl cout << endl
#define olar cout << "olar" << endl
#define gottagofast ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

string a,b;
int memo[2020][2020],na,nb;

int pd(int x, int y){

    if(x==0 || y==0)
        return max(x,y);

    int &pdm=memo[x][y];
    
    if(pdm!=-1)
        return pdm;

    if(a[x-1]==b[y-1])
        return pdm= pd(x-1,y-1);     //se as letras sao iguais

    int rema=pd(x-1,y);
    int remb=pd(x,y-1);
    int rep=pd(x-1,y-1);

    pdm=1+min({ rema,remb,rep });

    return pdm;

}


int main(){

    int t;
    cin >> t;
    getline(cin,a);
    while(t--){
        getline(cin,a);
        getline(cin,b);
    
        na=a.size();
        nb=b.size();
  
        ms(memo,-1);
        cout << pd(na,nb) << endl;
        
    }

}