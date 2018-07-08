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

vi nodes[1000100];
int dist[10001000];
int f,s,g,u,d;

void bfs(int v){

	dist[v]=0;
	queue<int> fila;
	fila.push(v);

	while(!fila.empty()){

		int pai = fila.front();
		fila.pop();

		if(pai-d>=1 && dist[pai-d]>1+dist[pai]){
			dist[pai-d]=1+dist[pai];
			fila.push(pai-d);
		}


		if(pai+u<=f && dist[pai+u]>1+dist[pai]){
			dist[pai+u]=1+dist[pai];
			fila.push(pai+u);
		}

	}

}

int main(){

	cin >> f >> s >> g >> u >> d;

	ms(dist,INF);

	bfs(s);
	
	if(dist[g]==INF)
		cout << "use the stairs" << endl;
	else
		cout << dist[g] << endl;

}
