#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()

#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) 

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;

int id[1100100];
int sz[1100100];
int comp;
int grid[1010][1010];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};


int n,m,q;

bool valid(int x, int y){
    return x>=0 && x<n && y>=0 && y<m;
}

int find(int x){
    if(x==id[x])    return x;
    return id[x]=find(id[x]);
}

void join(int a, int b){
    a=find(a);b=find(b);
    if(a==b)    return;
    comp--;
    if(sz[a]<sz[b]) swap(a,b);
    id[b]=a;
    sz[a]+=sz[b];
}

void merge_neighbors(int x, int y){

    fr(k,4){
        int new_x = x + dx[k];
        int new_y = y + dy[k];
        
        if( valid(new_x,new_y) && grid[new_x][new_y]==0 )
            join(new_x*m + new_y, x*m + y );
    }

}

int main(){

    fastio;
    
    cin >> n >> m >> q;
    
    stack< vii > s;
    
    for(int i=0;i<q;i++){
    
        vii aux;
        pii a,b;
        
        cin >> a.fst >> a.snd >> b.fst >> b.snd;
        
        a.fst--;a.snd--;
        b.fst--;b.snd--;
        
        aux.pb(a);aux.pb(b);
        s.push(aux);
        
        if(a==b){
            grid[a.fst][a.snd]++;
        }
        
        else if(a.fst==b.fst){
            int x = a.fst;
            int lo = min(a.snd,b.snd);
            int hi = max(a.snd,b.snd);
            for(int y = lo; y<=hi;y++)
                grid[x][y]++;
        }
        
        else{
            int y = a.snd;
            int lo = min(a.fst,b.fst);
            int hi = max(a.fst,b.fst);
            for(int x = lo; x<=hi; x++)
                grid[x][y]++;
        }
    }
    
    fr(i,n){
        fr(j,m){
            sz[i*m+j]=1;
            id[i*m+j]=i*m+j;
            if(grid[i][j]==0)
                comp++;
        }
    }
    
    
    fr(i,n){
        fr(j,m){
        
            if(grid[i][j]!=0)
                continue;
                
            merge_neighbors(i,j);
        }
    }
    
    vi ans;
    ans.pb(comp);
    
    for(int i=0;i<q-1;i++){
    
        vii aux = s.top();
        s.pop();
        
        pii a = aux[0];
        pii b = aux[1];
        
        if(a==b){
            grid[a.fst][a.snd]--;
            if(grid[a.fst][a.snd]==0){
                merge_neighbors(a.fst,a.snd);
                comp++;
            }
        }
        else if(a.fst==b.fst){
        
            int x = a.fst;
            int lo = min(a.snd,b.snd);
            int hi = max(a.snd,b.snd);
            
            for(int y = lo; y<=hi;y++){
                grid[x][y]--;
                if(grid[x][y]==0){
                    comp++;
                    merge_neighbors(x,y);
                }
            }
        }
        else{
        
            int y = a.snd;
            int lo = min(a.fst,b.fst);
            int hi = max(a.fst,b.fst);
            
            for(int x = lo; x<=hi; x++){
                grid[x][y]--;
                if(grid[x][y]==0){
                    comp++;
                    merge_neighbors(x,y);
                }
            }
        }
        
        ans.pb(comp);
        
    }
    
    reverse(all(ans));
    for(auto x : ans)
        cout << x << " ";
    cout << endl;

}