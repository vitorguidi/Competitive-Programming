#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;

ll id[100],sz[100];
ll edges[100][100],used[100][100];
ll removed[100][100],added[100][100];

int find(int p){
    if(id[p]==p)
        return p;
    return id[p]=find(id[p]);
}

void join(int p, int q){

    p=find(p);q=find(q);
    if(p==q)
        return;
    if(sz[p]>sz[q])
        swap(p,q);
    id[p]=q;sz[q]+=sz[p];

}

int main(){

    int n,d,a;

    cin >> n >> d >> a;
    
    ms(sz,1);
    fr(i,n)
        id[i]=i;

    string s;
    getline(cin,s);

    fr(i,n){
    	getline(cin,s);
    	fr(j,n){
    		if(s[j]=='1')
    			edges[i][j]=1;
    		else
    			edges[i][j]=0;
    	}    
    }

    vii antes,depois;

    fr(i,n){
        for(int j=i;j<n;j++){

            if(edges[i][j]){
                used[i][j]=used[j][i]=1;
                antes.pb(mp(i,j));
            }
        
            else
                depois.pb(mp(i,j));
        
        }
    }

    ll custo_remover=0;

    for(auto x : antes){

        if(find(x.fst)!=find(x.snd))
            join(x.fst,x.snd);
        
        else{
            custo_remover+=d;
            removed[x.snd][x.fst]=1;
            removed[x.fst][x.snd]=1;
            used[x.fst][x.snd]=0;
            used[x.snd][x.fst]=0;
        }

    }

    ll custo_adicionar=0;

    for(auto x : depois){

        if(find(x.fst)!=find(x.snd)){
        
            join(x.fst,x.snd);
            custo_adicionar+=a;
            added[x.fst][x.snd]=1;
            added[x.snd][x.fst]=1;
       
       	}

    }

    cout << custo_adicionar + custo_remover << endl;

    fr(i,n){
        fr(j,n){

            if(removed[i][j])
                cout << "d";
        
            else if(added[i][j])
                cout << "a";
        
            else
                cout << 0;
        }

        gnl;
    }

    return 0;
    

}
