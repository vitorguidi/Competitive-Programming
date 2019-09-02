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
const int MAXN=1010;
const int MAXM=10100;
 
int ned;
int first[MAXN],dist[MAXN],work[MAXN];
int to[MAXM],cap[MAXM],nxt[MAXM];

void init(){
	ned=0;
	memset(first,-1,sizeof first);
}

void add(int u, int v, int f){
	to[ned]=v,cap[ned]=f;
	nxt[ned]=first[u],first[u]=ned++;
	to[ned]=u,cap[ned]=0;
	nxt[ned]=first[v],first[v]=ned++;
}

int dfs(int u, int s, int t, int f){

	if(u==t)	return f;

	int v,df;

	for(int& e = work[u];e!=-1;e=nxt[e]){
		v=to[e];
		if(dist[v]==1+dist[u] && cap[e]>0){
			df=dfs(v,s,t,min(f,cap[e]));
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
	memset(dist,-1,sizeof dist);
	dist[s]=0;
	queue<int> q;q.push(s);
	int u,v;
	while(!q.empty()){
		u=q.front();q.pop();
		for(int e=first[u];e!=-1;e=nxt[e]){
			v=to[e];
			if(dist[v]==-1 && cap[e]>0){
				dist[v]=1+dist[u];
				q.push(v);
			}
		}
	}
	return dist[t]>=0;
}

int dinic(int s, int t){
	int result=0,df;
	while(bfs(s,t)){
		memcpy(work,first,sizeof work);
		while(df=dfs(s,s,t,INF))
			result+=df;
	}
	return result;
}

char grid[60][60];
int n,m;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int getId(int i, int j){
	return 1 + i*m+j;
}

bool valid(int i, int j){
	return i>=0 && i<n && j>=0 && j<m && grid[i][j]=='*';
}

void go(){

	init();
	cin >> n >> m;

	string s;
	getline(cin,s);

	int source=0;
	int sink=900;

	fr(i,n){
		getline(cin,s);
		fr(j,m)
			grid[i][j]=s[j];
	}

	// fr(i,n){
	// 	fr(j,m){
	// 		cout<<getId(i,j)<< " ";
	// 	}
	// 	gnl;
	// }
	// gnl;

	int cnt = 0;

	fr(i,n){
		fr(j,m){

			if(grid[i][j]=='*'){
				cnt++;
				if( (i+j)%2==0){
					//cout << "0 -->" << getId(i,j) << endl;
					add(source,getId(i,j),1);
				}
				else{
					//cout << getId(i,j) << " -> si" << endl;
					add(getId(i,j),sink,1);
				}
			}

			//dbg(getId(i,j));

			fr(k,4){

				int x = i+dx[k];
				int y = j+dy[k];

				if(valid(x,y) && grid[x][y]=='*'){
					if( (i+j)%2 ){
						//cout << getId(x,y) << " -> " << getId(i,j) << endl; 
						add(getId(x,y),getId(i,j),1);
					}
					else{
						//cout << getId(i,j) << " -> " << getId(x,y) << endl; 
						add(getId(i,j),getId(x,y),1);
					}
				}

			}

			//gnl;

		}
	}


	int ans = dinic(source,sink);
	ans = ans + (cnt-2*ans);

	cout << ans << endl;

}

int main(){
 
	fastio;

	int t; cin >> t;
	while(t--)	go();
 
}