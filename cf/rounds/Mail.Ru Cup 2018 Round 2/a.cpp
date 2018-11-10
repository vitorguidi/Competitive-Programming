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

vi nodes[1010];
int d[1010];
int vai[1010];
int volta[1010];

void bfs(int v){

	if(vai[v])
		d[v]=0;
	queue<int> fila;
	fila.push(v);
	
	while(!fila.empty()){
	
		int pai = fila.front();
		fila.pop();
	
		for(auto x : nodes[pai]){
		
			if(d[x]>1+d[pai]){
				d[x]=1+d[pai];
				fila.push(x);
			}
		
		}

	}
}


int main(){
    
	fastio;

	int n,s; cin >> n >> s;

	frr(i,n)	cin >> vai[i];
	frr(i,n)	cin >> volta[i];

	for(int i=n;i>1;i--){
		
		for(int j=i-1;j>0;j--){
			if(volta[j] && volta[i])
				nodes[i].pb(j);	
		}

	}

	for(int i=1;i<n;i++){
		
		for(int j=i+1;j<=n;j++){
			if(vai[i] && vai[j])
				nodes[i].pb(j);
		}
	}

	ms(d,INF);
	bfs(1);

	if(d[s]!=INF)
		puts("YES");
	else
		puts("NO");	

}

