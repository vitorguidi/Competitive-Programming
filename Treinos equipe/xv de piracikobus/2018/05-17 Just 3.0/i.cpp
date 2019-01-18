#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define pq priority_queue
#define grtp greater< pair<int,int> >
#define gnl cout << endl
#define olar cout << "olar" << endl

typedef pair<int,int> pii;
typedef vector<int,int> vi;
typedef vector< pair<int,int> > vii;

const int INF = 0x3f3f3f3f;

int dist[251];
string vocab[251];
vector<vii> nodes;
int are[251][251];

void dijkstra(int v){

	pq <pii,vii,grtp> fila;
	ms(dist,INF);
	dist[v]=0;
	fila.push(mp(0,v));

	while(!fila.empty()){

		pii atual = fila.top();
		fila.pop();

		if(dist[atual.snd]<atual.fst)	continue;

		for(int i=0;i<nodes[atual.snd].size();i++){
			pii filho = nodes[atual.snd][i];
			if(dist[filho.snd]>dist[atual.snd]+filho.fst){
				dist[filho.snd]=dist[atual.snd]+filho.fst;
				fila.push( mp( dist[filho.snd],filho.snd ) );
			}
		}

	}

}

bool check_pair(string a, string b){

	int cnt=0;
	int v1[10],v2[10];
	ms(v1,0);
	ms(v2,0);

	for(int i=0;i<20;i++){
		v1[ a[i]-'0' ]++;
		v2[ b[i]-'0' ]++;
	}

	for(int i=0;i<10;i++)	cnt+=min(v1[i],v2[i]);

	if(cnt==17)	return true;
	return false;
}

void make_graph(int n){

	ms(are,0);		//cuido pra nao adicionar as arestas mais de uma vez
	for(int i=1;i<=n;i++){
	
		for(int j=1;j<=n;j++){

			if( check_pair(vocab[i],vocab[j]) && are[i][j]==0 ){
				nodes[i].pb( mp(1,j) );
				nodes[j].pb( mp(1,i) );
				are[i][j]=are[j][i]=1;
			}
		
		}
	
	}

}

void run(){
	int n,s,e;
	cin >> n >> s >> e;
	getchar();
	for(int i=1;i<=n;i++)	getline(cin,vocab[i]);
	nodes.clear();
	nodes.resize(n+1);
	make_graph(n);
	dijkstra(s);
	if(dist[e]==INF)	cout << -1 << endl;
	else				cout << dist[e] << endl;
}

int main(){

	int t;
	cin >> t;
	for(int i=0;i<t;i++)	run();
}