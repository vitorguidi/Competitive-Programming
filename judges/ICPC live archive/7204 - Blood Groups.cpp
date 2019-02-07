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
#define olar cout << "pira" << endl
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll; 

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

const int MAXN = 100100,MAXM=1100100;

int work[MAXN],dist[MAXN],first[MAXN];
int to[MAXM],nxt[MAXM],cap[MAXM];
int ned;

int init(){
	memset(first,-1,sizeof first);
	ned=0;
}

void add(int u, int v, int f){

	to[ned]=v,cap[ned]=f;
	nxt[ned]=first[u];
	first[u]=ned++;

	to[ned]=u,cap[ned]=0;
	nxt[ned]=first[v];
	first[v]=ned++;

}

int dfs(int u, int f, int s, int t){

	if(u==t)	return f;
	int df,v;

	for(int &e=work[u];e!=-1;e=nxt[e]){
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
	memset(dist,-1,sizeof dist);
	int u,v;
	queue<int>q;q.push(s);
	dist[s]=0;
	while(!q.empty()){
		u=q.front();q.pop();
		for(int e =first[u];e!=-1;e=nxt[e]){
			v=to[e];
			if(dist[v]<0 && cap[e]>0){
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
		while(df=dfs(s,INF,s,t))	result+=df;
	}
	return result;
}

int grupos[110][110];
int consulta[110];
int n,q;

int go(){

	init();

	int amt;
	cin >> amt;		//quantos antigenos diferentes no sangue

	ms(consulta,0);
	consulta[0] = n-amt;	//se aceita alelo O
	
	int dif=0;

	while(amt--){
		int x; cin >> x;
		dif++;
		consulta[x]=1;
	}

	//cada pai pode doar 1 alelo
	frr(i,n)	add(0,i,1);		

	//para cada pai, pego todos os antigenos q ele pode doar e jogo nos antigenos do filho		
	frr(i,n)
		for(int j=1;j<=n;j++)
			if(grupos[i][j])	add(i,n+j,1);

	//para cada alelo, permito somente um de cada antigeno sair. depois vejo quem nao doou pra checar redundancia
	for(int j=1;j<=n;j++){
		if(!consulta[j])	continue;
		add(n+j,2*n+1,1);
	}	

	int mf = dinic(0,2*n+1);
	
	if(mf<dif)	return 0;
	return 1;

}

void solve(){

	ms(grupos,0);

	frr(i,n){
		
		int amt;
		cin >> amt;
		grupos[i][0]+=n-amt;
		
		while(amt--){
			int val; cin >> val;
			grupos[i][val]++;
		}

	}

	frr(i,q){
		
		int ans = go();
		
		if(!ans){
			cout <<"N" << endl;		//tenta pegar um de cada antigeno de algum dos pais
			continue;				//se tem menos antigeno disponivel do que o requisitado, nao rola
		}

		bool flag2=true;

		for(int e = first[0];e!=-1;e=nxt[e]){

			int v= to[e];

			if(cap[e]==0)		continue;					//pai doou, beleza
			if(grupos[v][0] && consulta[0])	continue;		//pode doar O e nao cagar o role

			bool flag1=false;

			for(int e2=first[v];e2!=-1;e2=nxt[e2]){
				if(e2&1)	continue;
				int ant = to[e2]-n;
				if(consulta[ant])	flag1=true;
			}

			flag2&=flag1;

		}

		if(flag2)	cout << "Y" << endl;
		else		cout << "N" << endl;


	}

}

int main(){

	fastio;
	while(cin >> n){
		cin >> q;
		solve();
	}
}