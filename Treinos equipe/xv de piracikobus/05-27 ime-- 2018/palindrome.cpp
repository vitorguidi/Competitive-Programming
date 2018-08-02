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
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

string s;
int pos[2020],n,tam;
pii memo[2020][2020];

pii pd(int i, int j){

    if(i<0 || j<0 || i>=tam || j>=tam)  return mp(0,0);

    pii &pdm=memo[i][j];

    if(pdm.fst!=-1) return pdm;

    pii next= pd(i-1,j+1);
    pii left= pd(i-1,j);
    pii right = pd(i,j+1);

    if(i==j) return pdm=mp(pos[i]+next.fst,1+next.snd);

    pii take_now=mp(pos[i]+pos[j]+next.fst,2+next.snd);

    if(s[i]==s[j])    return pdm=max( max(take_now,left),right  );
    else              return pdm=max(left,right);

}

int main(){
    
    getline(cin,s);
    cin >> n;
    fr(i,n){
        int aux;
        cin >> aux;
        pos[aux-1]=1;
    }

    fr(i,2020){
        fr(j,2020)
            memo[i][j]=mp(-1,-1);
    }

    tam = s.size();
    pii resp=mp(0,0);
    pii r1,r2;
    fr(i,tam){
        r1=pd(i,i);
        r2=pd(i,i+1);
        if(r2>r1)   r1=r2;
        if(r1>resp) resp=r1;
    }
    cout << resp.snd << endl;

}

