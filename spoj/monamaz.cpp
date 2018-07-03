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
#define pq priority_queue
#define grtp greater< pair<int,int> >

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
const double pi = 3.141592653589793238462643383279502884L;

struct point{
	int x,y,d,id;
};

point v[1010];
point d[1010][1010];
vi nodes[1010];
int vis[1010];

void dfs(int v){
	vis[v]=1;
	int tam = nodes[v].size();
	fr(i,tam){
		int filho=nodes[v][i];
		if(!vis[filho])
			dfs(filho);
	}
}

int dist(point a, point b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

bool check(point a, point b){
	if(a.d<b.d)
		return true;
	if(a.d==b.d){
		if(a.x<b.x)
			return true;
		if(a.x==b.x){
			if(a.y<=b.y)
				return true;
			else
				return false;
		}
	}
	return false;
}

int main(){
	
	int n;
	
	while(cin >> n){
		
		if(!n)
			break;
		
		fr(i,n){
			int x,y;
			cin >> x >> y;
			point aux;
			aux.d=INF;
			aux.x=x;
			aux.y=y;
			v[i]=aux;
		}

		point aux;
		
		fr(i,n){
			fr(j,n){
				aux=v[j];
				aux.id=j;
				aux.d=dist(v[i],v[j]);
				d[i][j]=aux;
			}
		}

		fr(i,n){
			point a,b;
			a.d=b.d=INF;
			a.x=b.x=a.y=b.y=INF;
			nodes[i].clear();
			fr(j,n){
				if(i==j)
					continue;
				if(check(d[i][j],a)){
					swap(a,b);
					a=d[i][j];
				}
				else if(check(d[i][j],b))
					b=d[i][j];
			}
			if(a.d!=INF)
				nodes[i].pb(a.id);
			if(b.d!=INF)
				nodes[i].pb(b.id);
		}

		ms(vis,0);
		dfs(0);
		int flag=0;
		fr(i,n){
			if(!vis[i])
				flag=1;
		}

		if(!flag)
			cout << "All stations are reachable." << endl;
		else
			cout << "There are stations that are unreachable." << endl;
	}
}