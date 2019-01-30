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

int cap[110];
int tem[110];
vii lista;

int main(){
    
	fastio;

	int n,w; cin >> n >> w;

	fr(i,n){
		cin >> cap[i];
		lista.pb({cap[i],i});
		w-=(cap[i]+1)/2;
		tem[i]=(cap[i]+1)/2;
	}


	if(w<0){
		cout << -1 << endl;
		return 0;
	}

	sort(all(lista));

	while(w){
		for(int i = n-1;i>=0;i--){

			int ind = lista[i].snd;
			int delta = min(w,cap[ind]-tem[ind]);
			w-=delta;
			tem[ind]+=delta;


		}
	}

	fr(i,n)
	cout << tem[i] << " ";
	gnl;

}

