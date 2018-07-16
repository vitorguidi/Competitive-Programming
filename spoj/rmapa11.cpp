//BEATRIZ QUE NAO SABE CODAR APROVA ESSE HEADER

#include "bits/stdc++.h"
using namespace std;

#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define grtp greater<pair<int,int>>
#define pq priority_queue

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x, v) memset(x, v, sizeof x)
#define all(x)	x.begin(),x.end()
#define dbg(x) cout << #x << " = " << x << endl
#define gnl cout << endl
#define olar()  cout << "olarr" << endl;

const int INF = 0x3f3f3f3f;
const long long int llINF = 1e18;

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int pai[501];
int peso[501];

int find(int x){
	if(pai[x]==x)	return x;
	return pai[x]=find(pai[x]);
}

void join(int x, int y){

	x=pai[x];
	y=pai[y];

	if(peso[x]<peso[y])	pai[x]=y;
	if(peso[x]>peso[y]) pai[y]=x;
	else{
		pai[x]=y;
		peso[y]+=1;
	}  
}

int main(){

	int n,m,u,v,c;
	vector< pair<int,pii> > arestas;
	cin >> n >> m;

	fr(i,n){
		pai[i]=i;
		peso[i]=1;
	}
	
	fr(i,m){
		cin >> u >> v >> c;
		pii nos=mp(u,v);
		arestas.pb( mp(c, nos ) );
	}
	
	sort(all(arestas));
	
	int cost=0;
	fr(i,m){
		pii nos = arestas[i].snd;
		int v1=nos.fst;
		int v2=nos.snd;
		if(find(v1)!=find(v2)){
			cost+=arestas[i].fst;
			join(v1,v2);
		}
	}
	
	cout << cost << endl;
}	
	