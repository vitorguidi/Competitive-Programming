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
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) 

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;

const int MAXN=1010;
const int MAXM=20200;

int n,m,g;

int ned;
int first[MAXN],dist[MAXN],work[MAXN];
int nxt[MAXM],to[MAXM],cap[MAXM];

void init(){
    memset(first,-1,sizeof first);
    ned=0;
}

void add_edge(int u,int v, int f){
    
    to[ned] = v, cap[ned] = f;
    nxt[ned] = first[u];
    first[u] = ned++;

    to[ned] = u, cap[ned] = 0;
    nxt[ned] = first[v];
    first[v] = ned++;

}

int dfs(int u, int f, int s, int t){

    if(u==t)    return f;
    int df,v;

    for(int &e = work[u];e!=-1;e=nxt[e]){
    
        v=to[e];
        if(dist[v]==dist[u]+1 && cap[e]>0){

            df=dfs(v,min(f,cap[e]),s,t);
            
            if(df>0){
                cap[e]-=df;
                cap[e^1]+=df;
                return df;
            }

        }

    }

    return 0;

}

bool bfs(int s, int t){
    
    int u,v;
    memset(&dist,-1,sizeof(dist));
    
    dist[s]=0;
    queue<int> q;q.push(s);
    
    while(!q.empty()){

        u=q.front();q.pop();
    
        for(int e = first[u];e!=-1;e=nxt[e]){
            v=to[e];
            if(dist[v]<0 && cap[e]>0){
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }

    }

    return dist[t]>=0;

}

int dinic(int s,int t){
    int result=0,f;
    while(bfs(s,t)){
        memcpy(work,first,sizeof work);
        while(f=dfs(s,INF,s,t)) result+=f;
    }
    return result;
}


bool go(){

    init();

    int games[45][45];
    int points[45];
    int id[45][45];

    ms(points,0);
    ms(games,0);
    
    int cnt=1;

    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            id[i][j]=id[j][i]=cnt++;
        }
    }

    int sink = 2*n + cnt;

    fr(i,g){
        int l,r;
        char op;
        cin >> l >> op >> r;
        l++;r++;
        games[l][r]++;
        games[r][l]++;
        if(op=='>')
            points[l]+=2;
        else if(op=='<')
            points[r]+=2;
        else
            points[r]++,points[l]++;
    }

    for(int i=1;i<=n;i++)
        add_edge(0,i,INF);

    int jogados=0;
    int sobra=0;
    for(int i=2;i<=n;i++){
        sobra+=(m-games[1][i]);
        points[1]+=(m-games[1][i])*2;
    }

    for(int i=2;i<=n;i++){
        for(int j=i+1;j<=n;j++){

            int falta = m - games[i][j];

            add_edge(i,2*n+id[i][j],falta);
            add_edge(j,2*n+id[i][j],falta);
            
            add_edge(2*n+id[i][j],n+i,2*falta);
            add_edge(2*n+id[i][j],n+j,2*falta);
        
        }
    }

    for(int i=2;i<=n;i++){
        int tgt = points[1]-1-points[i];
        if(tgt<0)   return false;
        add_edge(i+n,sink,tgt);
    }

    
    int check = m*n*(n-1);
    int mf = dinic(0,sink);
    int aux = 2*sobra + 2*g + mf;
    // dbg(aux);
    // dbg(2*sobra);
    // dbg(2*g);
    // dbg(mf);
    // dbg(check);


    return (check==aux);

}

int main(){

    fastio;

    init();

    while(cin >> n >> m >> g  && n!=0)
        cout << (go() ? "Y" : "N") << endl;

}

