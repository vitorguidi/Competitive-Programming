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

	vi nodes[200100],son[200100];
	int low[200100],pre[200100],cut[200100];
	int clk,val,post[200100],vis[200100];
	int hgt[100100];

	map<pii,int> bridges;
	map<int,int> colinha;

	void dfs(int v, int caller){		//detecta bridges e articulatiosn no grafo original
		
		low[v]=pre[v]=clk++;
		int nf=0;bool any=false;
		vis[v]=1;

		colinha[pre[v]]=v;

		for(auto filho : nodes[v]){

			if(filho==caller)
				continue;

			if(!vis[filho]){

				nf++;dfs(filho,v);

				hgt[filho]=hgt[v]+1;

				son[v].pb(pre[filho]);

				if(low[filho]>=pre[v])
					any=true;

				if(low[filho]>pre[v]){
					bridges[{v,filho}]=1;
					bridges[{filho,v}]=1;
				}

				low[v]=min(low[v],low[filho]);
			}
			else
				low[v]=min(low[v],pre[filho]);
		}

		if(v==1 && nf>1)
			cut[v]=1;
		
		else if(v!=1 && any)
			cut[v]=1;
		
		post[v]=clk++;
	}

	bool pai(int a, int b) {return pre[a]<=pre[b] && post[b]<=post[a];}

	int get_id(int a, int b){		//retorna o no que eh o primeiro filho de b q tb eh pai de a

		auto x = upper_bound( all(son[b]) ,pre[a] ); x--;	//pega primeiro filho de b com pre menor que a
		int ida=colinha[*x];		//recupera o id do vertice a partir do preorder number
		return ida;

	}

	bool check(int a, int b, int c){

		if(!pai(c,a) && !pai(c,b))		//dois fora da subtree do C nao corta o caminho
			return false;		

		if(!pai(c,a))						//no caso de soh um ser filho, quero que o a seja o filho
			swap(a,b);

		int ida=get_id(a,c);

		if(  pai(c,a) && pai(c,b)  ){	


			int idb = get_id(b,c);
			if(idb==ida && ida!=c)	return false;	//um mesmo filho de C eh pai de A e B, nesse caso nao corta o caminho
			if(low[idb]<pre[c] && low[ida]<pre[c])	return false;
			return true;	
		
		}

		if(low[ida]<pre[c])	return false;	
		return true;

	}

	int main(){

		fastio;

		int n,e;
		cin >> n >> e;
		
		fr(i,e){
			int x,y;
			cin >> x >> y;
			nodes[x].pb(y);
			nodes[y].pb(x);
		}
		
		dfs(1,1);		//reconhece bridges e articulation pointss

		int q; cin >> q;

		fr(i,q){

			int tipo,a,b,c,d;
			cin >> tipo >> a >> b >> c;
		
			if(tipo==1){

				cin >> d;

				if(pre[c]<pre[d])
					swap(c,d);

				if(!bridges[{c,d}])					puts("da");			//n eh ponte

				else if( pai(c,a) && pai(c,b) )		puts("da");		
				else if( !pai(c,a) && !pai(c,b))	puts("da");

				else puts("ne");										
			}

			else{	
				if(!cut[c])				puts("da");					
				else if(check(a,b,c))	puts("ne");					//check maroto
				else					puts("da");
			}

		}


	}
