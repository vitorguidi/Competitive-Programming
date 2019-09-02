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
#define all(x)	x.begin(),x.end()
 
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) 
 
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;
 
const int INF = 0x3f3f3f3f;
const int MAXN=100100;
const int MAXM=1100100;
 
int v[220];
int grid[220][220];
int n;
int ned;
int first[MAXN],dist[MAXN],work[MAXN];
int nxt[MAXM],to[MAXM],cap[MAXM];
 
void init(){
    memset(first,-1,sizeof first);
    ned=0;
}
 
void add(int u,int v, int f){
    
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
int tag[1010];
int reach[1010];
int vis[1010];
int cover[1010];
 
int matchright[1010],matchleft[1010];
 
void go(int u){
    vis[u]=1;
    reach[u]=1;
    for(int e = first[u];e!=-1;e=nxt[e]){
        int v = to[e];
        if(!vis[v] && cap[e]){
            go(v);
        }
    }
}
 
 
int main(){
 
	fastio;
	init();
 
	cin >> n;
	
	frr(i,n)
		cin >> v[i];
 
	set<int> s;
	frr(i,n)
		s.insert(v[i]);
 
	n=s.size();
	int clk=1;
	for(auto x : s)
		v[clk++]=x;
 
	frr(i,n)
		for(int j=i+1;j<=n;j++)
			if(v[j]%v[i]==0)
				grid[i][j]=1;
 
	frr(i,n){
		frr(j,n){
			if(i!=j && v[j]%v[i]==0 && !grid[i][j])
				olar;
		}
	}
 
	frr(k,n)
		frr(i,n)
			frr(j,n)
				grid[i][j]|=(grid[i][k]&grid[k][j]);
 
	frr(i,n){
		add(0,i,1);
		add(n+i,2*n+1,1);
	}
 
	frr(i,n)
		frr(j,n)
			if(grid[i][j])
				add(i,j+n,1);
 
	// int go = dinic(0,2*n+1);
 
 
 
	// cout << n - go << endl;
	
	// for(int i=1;i<=n;i++){
	// 	for(int e=first[i];e!=-1;e=nxt[e]){
	// 		int he = to[e];
	// 		if(to[e]>n && cap[e]==0){
	// 			cout << i << " - " << he-n << endl;
	// 			matchleft[i]=1;
	// 			matchright[he-n]=1;
	// 		}
	// 	}
	// }
 
	// frr(i,n)
	// 	if(matchleft[i] || !matchright[i])
	// 		tag[i]=1;
 
	// frr(i,n)
	// 	if(!tag[i])
	// 		cout << v[i] << " ";
	// gnl;
 
	dinic(0,2*n+1);
	go(0);
 
    frr(i,n){
        if( !reach[i] || reach[n+i])
            cover[i]=1;
    }   
 
    int ans = 0;
    frr(i,n)
        if(!cover[i])
            ans++;
 
    cout << ans << endl;
    for(int i=1;i<=n;i++)
        if(!cover[i])
            cout << v[i] << " ";
    gnl;
 
} 