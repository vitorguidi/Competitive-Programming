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

int n;
int x,y,indeg[110],d[110];
vector<vi> nodes;

int main(){

	int cnt=0;
	while(cin >> n){

		cnt++;
		
		if(!n)
			break;

		int s;
		cin >> s;

		nodes.clear();
		nodes.resize(n+1);
		ms(indeg,0);
		ms(d,INF);
		
		while(true){
			cin >> x >> y;
			if(!x)
				break;
			nodes[x].pb(y);
		}

		d[s]=0;
		stack<int> pilha;
		pilha.push(s);

		while(!pilha.empty()){

			int pai = pilha.top();
			pilha.pop();
			
			for(auto filho : nodes[pai]){
				if(d[filho]>-1+d[pai]){
					d[filho]=min(d[filho],-1+d[pai]);
					pilha.push(filho);
				}
			}

		}

		int mn=INF,id=-1;
	
		frr(i,n){
			if(d[i]<mn){
				mn=d[i];
				id=i;
			}
			else if(d[i]==mn && d[i]!=INF)
				id=min(id,i);
		}

		cout << "Case " << cnt << ": The longest path from " << s << " has length " << -mn << ", finishing at " << id << "." << endl << endl;
	}

}