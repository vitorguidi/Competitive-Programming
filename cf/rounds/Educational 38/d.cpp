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
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

ll d[200200];
vector<pll> nodes[200200];
int n,m;

void dijkstra(){

	set<pair<ll,ll>> fila;

	frr(i,n)
		fila.insert({d[i],i});

	while(!fila.empty()){

		pair<ll,ll> pai = *fila.begin();
		fila.erase(fila.begin());
	
		for(auto x : nodes[pai.snd]){

			if(d[x.snd]>pai.fst+x.fst){

				fila.erase({d[x.snd], x.snd});
				d[x.snd]=pai.fst+x.fst;
				fila.insert({d[x.snd],x.snd});
			
			}

		}

	}

}

int main(){
    
	scanf("%d %d",&n,&m);
	
	fr(i,m){
		ll a,b,w;
		scanf("%lld %lld %lld",&a,&b,&w);
		nodes[a].pb({2ll*w,b});
		nodes[b].pb({2ll*w,a});
	}


	frr(i,n)
		scanf("%lld",&d[i]);
	
	dijkstra();

	frr(i,n)
		printf("%lld ",d[i]);
	printf("\n");

}

