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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

string names[10100];
vii nodes[10100];
int d[10100];

int dist(string a, string b){
	
	int cnta[30],cntb[30];
	ms(cnta,0);ms(cntb,0);

	fr(i,a.size())
		cnta[a[i]-'a']++;


	fr(i,b.size())
		cntb[b[i]-'a']++;


	int ans=0;
	fr(i,26)
		ans+=(cnta[i]!=0)&(cntb[i]!=0);

	return ans;

}

void dijkstra(int v){

	set<pii> fila;
	fila.insert({0,v});
	ms(d,INF);
	d[v]=0;

	while(!fila.empty()){

		auto it = fila.begin();
		pii aux = *it;
		fila.erase(fila.begin());

		int pai = aux.snd;
		int dpai = aux.fst;

		for(auto x : nodes[pai]){

			if( d[x.snd]>d[pai]+x.fst ){

				d[x.snd]=d[pai]+x.fst;
				fila.insert({d[x.snd],x.snd});
			
			}
		}

	}

}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);    

	int n,m; cin >> n >> m;

	getline(cin,names[1]);
	
	for(int i=1;i<=n;i++){
		getline(cin,names[i]);
		fr(j,names[i].size())
			names[i][j]=tolower(names[i][j]);
	}

	for(int i=1;i<=m;i++){
		int x,y; cin >> x >> y;
		int wgt = dist(names[x],names[y]);
		nodes[x].pb({wgt,y});
		nodes[y].pb({wgt,x});
	}

	int ini,end; cin >> ini >> end;

	dijkstra(ini);

	cout << d[end] << endl;
    

}